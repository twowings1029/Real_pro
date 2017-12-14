#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
static QString arduino_bluetooth_mac_addr="98:D3:32:70:BD:7F";
static QString read_bpm_data;
static QString file_dir="data.txt";
static QVector <double> time_x(101),bpm_y(101),tmp_y(101);
static int graph_count;
static int bpm_int_data;
static int tmp_int_data;
static int velo_int_data;
static int graph_time_criteria;
static QString pulse_status;
static int age_flag;
static int intensity_flag;
static QString cmp_data;
static int trasmit_flag;
static int lup_bpm_table[Age_List_Num][2]=
{
    //M,W
    {200,197},{196,194},{193,191},{190,188},
    {187,185},{183,182},{180,179},{177,175},
    {174,172},{170,169}
};
static QString combo_age_table[Age_List_Num]=
{
  "20 ~ 24","25 ~ 30","30 ~ 34","35 ~ 39",
  "40 ~ 44","45 ~ 49","50 ~ 54","55 ~ 59",
  "60 ~ 64","65 ~ 69"
};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bpm_label ->setText(".. Waiting ..");
    ui->tmp_label->setText(".. Waiting ..");
    ui->velo_label->setText(".. Waiting ..");
    ui->Man_button->setChecked(true);
    ui->radio_50->setChecked(true);
    for(int i=0;i<Age_List_Num;i++)
    {
        ui->age_combo->addItem(combo_age_table[i]);
    }

    ui->bpm_plot->xAxis->setLabel("Time");
    ui->bpm_plot->yAxis->setLabel("Bpm");
    ui->bpm_plot->xAxis->setLabelFont(QFont(QFont().family(), 7));
    ui->bpm_plot->yAxis->setLabelFont(QFont(QFont().family(), 7));
    ui->bpm_plot->xAxis->setTickLabelFont(QFont(QFont().family(), 7));
    ui->bpm_plot->yAxis->setTickLabelFont(QFont(QFont().family(), 7));
    ui->bpm_plot->xAxis->setRange(0,Time_Interval);
    ui->bpm_plot->yAxis->setRange(0,200);
    ui->bpm_plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->bpm_plot->xAxis->setDateTimeSpec(Qt::UTC);
    ui->bpm_plot->xAxis->setDateTimeFormat("h:mm:ss");
    ui->bpm_plot->xAxis->setAutoTickStep(false);
    ui->bpm_plot->xAxis->setTickStep(Unit_Graph_time);
	ui->bpm_plot->yAxis->setAutoTickStep(false);
	ui->bpm_plot->yAxis->setTickStep(Unit_bpm_graph);
    ui->bpm_plot->replot();

    ui->tmp_plot->xAxis->setLabel("Time");
    ui->tmp_plot->yAxis->setLabel("Temp(deg)");
    ui->tmp_plot->xAxis->setLabelFont(QFont(QFont().family(), 7));
    ui->tmp_plot->yAxis->setLabelFont(QFont(QFont().family(), 7));
    ui->tmp_plot->xAxis->setTickLabelFont(QFont(QFont().family(), 7));
    ui->tmp_plot->yAxis->setTickLabelFont(QFont(QFont().family(), 7));
    ui->tmp_plot->xAxis->setRange(0,Time_Interval);
    ui->tmp_plot->yAxis->setRange(10,40);
    ui->tmp_plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->tmp_plot->xAxis->setDateTimeSpec(Qt::UTC);
    ui->tmp_plot->xAxis->setDateTimeFormat("h:mm:ss");
    ui->tmp_plot->xAxis->setAutoTickStep(false);
    ui->tmp_plot->xAxis->setTickStep(Unit_Graph_time);
    ui->tmp_plot->yAxis->setAutoTickStep(false);
    ui->tmp_plot->yAxis->setTickStep(Unit_temp_graph);
    ui->tmp_plot->replot();

    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(Read_data_from_arduino()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(Save_Data()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(Draw_bpm_data()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(Draw_tmp_data()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Is_Normal(QString &x)
{
    int i;
    QString Com_Age_Range=ui->age_combo->currentText();
    for(i=0;i<Age_List_Num;i++)
    {
        if(Com_Age_Range.compare(combo_age_table[i])==0) break;
    }
    int max_bpm=lup_bpm_table[i][age_flag];
    int normal_bpm;

    if(intensity_flag==Intensity_50_flag)
    {
        normal_bpm=(int)(max_bpm*Intensity_50_ratio);
    }
    else if(intensity_flag==Intensity_60_flag)
    {
        normal_bpm=(int)(max_bpm*Intensity_60_ratio);
    }
    else
    {
        normal_bpm=(int)(max_bpm*Intensity_70_ratio);
    }
    ui->pulse_target_label->setNum(normal_bpm);
    if(normal_bpm<bpm_int_data)
    {
        x.operator =("High");
    }
    else
    {
        x.operator =("Normal");
    }
}

void MainWindow::Read_data_from_arduino()
{
	QString tmp_data = socket->readLine();\
	QChar enter_char = '\n';
	qDebug() << graph_count;
	if (tmp_data.indexOf(enter_char) > -1)
	{
		trasmit_flag = Transmit_Success;
        cmp_data.append(tmp_data);
        QStringList cmp_list = cmp_data.split(" ");
        QString bpm_str=cmp_list.value(0);
        QString tmp_str=cmp_list.value(1);
        QString vel_str=cmp_list.value(2);
        QString remainder_str=cmp_list.value(3);
        cmp_data.operator =("");
        bpm_int_data=bpm_str.toInt();
        bpm_int_data*=3;
        bpm_int_data+=remainder_str.toInt();
        read_bpm_data=QString::number(bpm_int_data);
        tmp_int_data=tmp_str.toInt();
        velo_int_data=vel_str.toInt();

        if(bpm_int_data>=Bpm_Lower_Bound&& tmp_int_data>=Tmp_Lower_Bound)
        {
            ui->bpm_label->setNum(bpm_int_data);
            ui->tmp_label->setNum(tmp_int_data);
            ui->velo_label->setNum(velo_int_data);
            Is_Normal(pulse_status);
            ui->pulse_status_label->setText(pulse_status);
        }
	}
    else
    {
        cmp_data.append(tmp_data);
	    trasmit_flag = Transmit_Fail;
    }
}

void MainWindow::Save_Data()
{
	if (trasmit_flag == Transmit_Success)
	{
		int year;
		int month;
		int day;
		QDate cd = QDate::currentDate();
		QString day_cal;
		QTime ct = QTime::currentTime();
		QString time = ct.toString();
		QStringList time_list = time.split(":");
		QString hour_str = time_list.value(0);
		QString min_str = time_list.value(1);
		QString sec_str = time_list.value(2);
		int hour_save = hour_str.toInt();
		int min_save = min_str.toInt();
		int sec_save = sec_str.toInt();
		year = cd.year();
		month = cd.month();
		day = cd.day();

		day_cal = day_cal.append(QString::number(year));
		day_cal = day_cal.append("-");
		day_cal = day_cal.append(QString::number(month));
		day_cal = day_cal.append("-");
		day_cal = day_cal.append(QString::number(day));
		if (graph_count == 0)
		{
			int sec = (Hour_To_Sec*hour_save) + (Min_To_Sec*min_save) + (sec_save);
			graph_time_criteria = sec - (sec % Unit_Graph_time);
		}
		if (bpm_int_data >= Bpm_Lower_Bound && tmp_int_data >= Tmp_Lower_Bound)
		{
			time_x[graph_count] = (Hour_To_Sec*hour_save) + (Min_To_Sec*min_save) + (sec_save);
			bpm_y[graph_count] = bpm_int_data;
			tmp_y[graph_count++] = tmp_int_data;
			if (graph_count >= Max_For_Graph)
			{
				for (int i = 0; i <= Max_For_Graph; i++)
				{
					time_x[i] = bpm_y[i] = tmp_y[i] = 0;
				}
				graph_count = 0;
			}
		}

		QFile file(file_dir);

		if (file.open(QIODevice::ReadWrite | QIODevice::Text))
		{
			QTextStream stream(&file);
			if (read_bpm_data.toInt() >= Bpm_Lower_Bound && tmp_int_data >= Tmp_Lower_Bound)
			{
				while (stream.readLine() != "") ;
				stream << day_cal << " ";
				stream << time << " ";
				stream << read_bpm_data << " ";
				stream << QString::number(tmp_int_data) << " ";
				stream << QString::number(velo_int_data) << " ";
				stream << pulse_status;
				stream << endl;
				file.flush();
				file.close();
			}
		}
		
	}
}

void MainWindow::on_Connect_clicked()
{
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(arduino_bluetooth_mac_addr), QBluetoothUuid(serviceUuid), QIODevice::ReadOnly);

}
void MainWindow::on_Close_clicked()
{
    ui->bpm_label ->setText(".. Closed ..");
    ui->tmp_label-> setText(".. Closed ..");
    ui->velo_label->setText(".. Closed ..");
	socket->close();
    graph_count=0;
}


void MainWindow::Draw_bpm_data()
{
	if (trasmit_flag == Transmit_Success)
	{
		ui->bpm_plot->addGraph();
		ui->bpm_plot->graph(0)->setPen(QPen(Qt::blue));
		ui->bpm_plot->graph(0)->setData(time_x, bpm_y);
		ui->bpm_plot->xAxis->setRange(graph_time_criteria, Time_Interval + graph_time_criteria);
		ui->bpm_plot->replot();
		
	}
   
}

void MainWindow::Draw_tmp_data()
{
	if (trasmit_flag == Transmit_Success)
	{
		ui->tmp_plot->addGraph();
		ui->tmp_plot->graph(0)->setPen(QPen(Qt::red));
		ui->tmp_plot->graph(0)->setData(time_x, tmp_y);
		ui->tmp_plot->xAxis->setRange(graph_time_criteria, Time_Interval + graph_time_criteria);
		ui->tmp_plot->replot();
	}
}

void MainWindow::on_Man_button_clicked()
{
    age_flag=Man;
}

void MainWindow::on_Woman_button_clicked()
{
    age_flag=Woman;
}

void MainWindow::on_radio_50_clicked()
{
    ui->radio_50->setChecked(true);
    intensity_flag=Intensity_50_flag;
}

void MainWindow::on_radio_60_clicked()
{
    ui->radio_60->setChecked(true);
    intensity_flag=Intensity_60_flag;
}

void MainWindow::on_radio_70_clicked()
{
    ui->radio_70->setChecked(true);
    intensity_flag=Intensity_70_flag;
}

void MainWindow::on_Pri_data_button_clicked()
{
    Dialog dlg;
    dlg.exec();
}
