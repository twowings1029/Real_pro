#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
/*For raspberry pi*/
static QString arduino_port_name="/dev/ttyACM0";
/*For windows*/
//static QString arduino_port_name="com5";
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
    for(int i=0;i<Age_List_Num;i++)
    {
	    ui->age_combo->addItem(combo_age_table[i]);
    }


    ui->bpm_plot->xAxis->setLabel("Time");
    ui->bpm_plot->yAxis->setLabel("Bpm");
    ui->bpm_plot->xAxis->setRange(0,Time_Interval);
    ui->bpm_plot->yAxis->setRange(0,200);
    ui->bpm_plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->bpm_plot->xAxis->setDateTimeSpec(Qt::UTC);
    ui->bpm_plot->xAxis->setDateTimeFormat("h:mm:ss");
    ui->bpm_plot->xAxis->setAutoTickStep(false);
    ui->bpm_plot->xAxis->setTickStep(Unit_Graph_time);
    ui->bpm_plot->replot();

    ui->tmp_plot->xAxis->setLabel("Time");
    ui->tmp_plot->yAxis->setLabel("Temp(℃)");
    ui->tmp_plot->xAxis->setRange(0,Time_Interval);
    ui->tmp_plot->yAxis->setRange(20,40);
    ui->tmp_plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->tmp_plot->xAxis->setDateTimeSpec(Qt::UTC);
    ui->tmp_plot->xAxis->setDateTimeFormat("h:mm:ss");
    ui->tmp_plot->xAxis->setAutoTickStep(false);
    ui->tmp_plot->xAxis->setTickStep(Unit_Graph_time);
    ui->tmp_plot->replot();

    port=new QSerialPort();
    port->setPortName(arduino_port_name);
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);

    QObject::connect(port,SIGNAL(readyRead()),this,SLOT(Read_data_from_arduino()));
    QObject::connect(port,SIGNAL(readyRead()),this,SLOT(Save_Data()));
    QObject::connect(port,SIGNAL(readyRead()),this,SLOT(Draw_bpm_data()));
    QObject::connect(port,SIGNAL(readyRead()),this,SLOT(Draw_tmp_data()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Is_Normal(QString &x)
{
    int i;
	QString Com_Age_Range = ui->age_combo->currentText();
    for(i=0;i<Age_List_Num;i++)
    {
        if(Com_Age_Range.compare(combo_age_table[i])==0) break;
    }
    int max_bpm=lup_bpm_table[i][age_flag];
    int normal_bpm;
    if(velo_int_data<Normal_speed)
    {
        normal_bpm=(int)(max_bpm*Normal_ratio);
    }
    else if(velo_int_data>=Normal_speed && velo_int_data<=Walk_speed)
    {
        normal_bpm=(int)(max_bpm*Walk_ratio);
    }
    else
    {
        normal_bpm=(int)(max_bpm*Running_ratio);
    }
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
    QString raw_data=port->readLine();
    QStringList cmp_list= raw_data.split(" ");
    QString bpm_str=cmp_list.value(0);
    QString tmp_str=cmp_list.value(1);
    QString vel_str=cmp_list.value(2);
    QString remainder_str=cmp_list.value(3);
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

void MainWindow::Save_Data()
{
    int year;
    int month;
    int day;
    QDate cd=QDate::currentDate();
    QString day_cal;
    QTime ct = QTime::currentTime();
    QString time=ct.toString();
    QStringList time_list=time.split(":");
    QString hour_str=time_list.value(0);
    QString min_str=time_list.value(1);
    QString sec_str=time_list.value(2);
    int hour_save=hour_str.toInt();
    int min_save=min_str.toInt();
    int sec_save=sec_str.toInt();
    year=cd.year();
    month=cd.month();
    day=cd.day();

    day_cal=day_cal.append(QString::number(year));
    day_cal=day_cal.append("-");
    day_cal=day_cal.append(QString::number(month));
    day_cal=day_cal.append("-");
    day_cal=day_cal.append(QString::number(day));
    if(graph_count==0)
    {
        int sec=(Hour_To_Sec*hour_save)+(Min_To_Sec*min_save)+(sec_save);
        graph_time_criteria=sec-(sec%Unit_Graph_time);
    }
    if(bpm_int_data>=Bpm_Lower_Bound && tmp_int_data>=Tmp_Lower_Bound)
    {
        time_x[graph_count]=(Hour_To_Sec*hour_save)+(Min_To_Sec*min_save)+(sec_save);
        bpm_y[graph_count]=bpm_int_data;
        tmp_y[graph_count++]=tmp_int_data;
        if(graph_count>=Max_For_Graph)
        {
            for(int i=0;i<=Max_For_Graph;i++)
            {
                time_x[i]=bpm_y[i]=tmp_y[i]=0;
            }
            graph_count=0;
        }
    }

    QFile file(file_dir);

    if(file.open(QIODevice::ReadWrite | QIODevice :: Text))
    {
        QTextStream stream(&file);
        if(read_bpm_data.toInt()>=Bpm_Lower_Bound && tmp_int_data>=Tmp_Lower_Bound)
        {
            while(stream.readLine()!="");
            stream<<day_cal<<" ";
            stream<<time<<" ";
            stream<<read_bpm_data<<" ";
            stream<<QString::number(tmp_int_data)<<" ";
            stream<<QString::number(velo_int_data)<<" ";
            stream<<pulse_status;
            stream<<endl;
            file.flush();
            file.close();
        }
    }
}

void MainWindow::on_Connect_Port_clicked()
{
    port->open(QIODevice::ReadOnly);
    if (port->isOpen() == false)
    {
        ui->bpm_label->setText("Error");
        ui->tmp_label->setText("Error");
        ui->velo_label->setText("Error");
    }
}
void MainWindow::on_Close_port_clicked()
{
    ui->bpm_label ->setText(".. Closed ..");
    ui->tmp_label->setText(".. Closed ..");
    ui->velo_label->setText(".. Closed ..");
    graph_count=0;
    port->close();
}


void MainWindow::Draw_bpm_data()
{
    ui->bpm_plot->addGraph();
    ui->bpm_plot->graph(0)->setPen(QPen(Qt::blue));
    ui->bpm_plot->graph(0)->setData(time_x,bpm_y);
    ui->bpm_plot->xAxis->setRange(graph_time_criteria,Time_Interval+graph_time_criteria);
    ui->bpm_plot->replot();
}

void MainWindow::Draw_tmp_data()
{
    ui->tmp_plot->addGraph();
    ui->tmp_plot->graph(0)->setPen(QPen(Qt::red));
    ui->tmp_plot->graph(0)->setData(time_x,tmp_y);
    ui->tmp_plot->xAxis->setRange(graph_time_criteria,Time_Interval+graph_time_criteria);
    ui->tmp_plot->replot();
}

void MainWindow::on_Pri_data_button_clicked()
{
    Dialog dlg;
    dlg.exec();
}

void MainWindow::on_Man_button_clicked()
{
    age_flag=Man;
}

void MainWindow::on_Woman_button_clicked()
{
    age_flag=Woman;
}
