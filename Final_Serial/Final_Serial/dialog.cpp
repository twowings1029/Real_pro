#include "dialog.h"
#include "ui_dialog.h"
static QString file_dir="data.txt";
static QVector <double> bpm_x(MAX_Pri_Buffer),bpm_y(MAX_Pri_Buffer);
static QVector <double> tmp_x(MAX_Pri_Buffer),tmp_y(MAX_Pri_Buffer);
static QVector <double> graph_time_x(MAX_Pri_Buffer),graph_bpm_y(MAX_Pri_Buffer),graph_tmp_y(MAX_Pri_Buffer);
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    for(int i=0;i<Len_For_year;i++)
    {
        ui->year_combo->addItem(QString::number(i+Criteria_year));
    }
    for(int i=0;i<Len_For_month;i++)
    {
        ui->month_combo->addItem(QString::number(i+1));
    }
    for(int i=0;i<Len_For_Day;i++)
    {
        ui->day_combo->addItem(QString::number(i+1));
    }
    for(int i=0;i<Len_For_Hour;i++)
    {
        ui->hour_combo->addItem(QString::number(i));
    }
    ui->bpm_plot->addGraph();
    ui->bpm_plot->xAxis->setLabel("Time");
    ui->bpm_plot->yAxis->setLabel("Bpm");
    ui->bpm_plot->xAxis->setRange(0,Hour_To_Sec);
    ui->bpm_plot->yAxis->setRange(0,200);
    ui->bpm_plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->bpm_plot->xAxis->setDateTimeSpec(Qt::UTC);
    ui->bpm_plot->xAxis->setDateTimeFormat("hh:mm");
    ui->bpm_plot->xAxis->setAutoTickStep(false);
    ui->bpm_plot->xAxis->setTickStep(600);
    ui->bpm_plot->replot();

    ui->tmp_plot->addGraph();
    ui->tmp_plot->xAxis->setLabel("Time");
    ui->tmp_plot->yAxis->setLabel("Temp(℃)");
    ui->tmp_plot->xAxis->setRange(0,Hour_To_Sec);
    ui->tmp_plot->yAxis->setRange(20,40);
    ui->tmp_plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->tmp_plot->xAxis->setDateTimeSpec(Qt::UTC);
    ui->tmp_plot->xAxis->setDateTimeFormat("hh:mm");
    ui->tmp_plot->xAxis->setAutoTickStep(false);
    ui->tmp_plot->xAxis->setTickStep(600);
    ui->tmp_plot->replot();
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::on_load_data_button_clicked()
{
    QFile file(file_dir);
    QString day_filter;
    int bpm_sum=0;
    int data_cnt=0;
    int bpm_max=0;
    int bpm_min=INF;
    int tmp_sum=0;
    int tmp_max=0;
    int tmp_min=INF;
    int hour_data_cnt=0;
    day_filter.append(ui->year_combo->currentText());
    day_filter.append("-");
    day_filter.append(ui->month_combo->currentText());
    day_filter.append("-");
    day_filter.append(ui->day_combo->currentText());

    if(file.open(QIODevice::ReadWrite | QIODevice :: Text))
    {
        QTextStream stream(&file);
        while(stream.atEnd()==false)
        {
          QString line=stream.readLine();
          QStringList cmp_list= line.split(" ");
          if(day_filter.compare(cmp_list.value(0))==0)
          {
            QString time_str=cmp_list.value(1);
            QString bpm_str=cmp_list.value(2);
            QString tmp_str=cmp_list.value(3);
            QStringList time_list=time_str.split(":");
            QString hour_str=time_list.value(0);
            QString min_str=time_list.value(1);
            QString sec_str=time_list.value(2);
            QString ui_time_str= ui->hour_combo->currentText();
            int time_basis=ui_time_str.toInt();
            int hour_pri=hour_str.toInt();
            int min_pri=min_str.toInt();
            int sec_pri=sec_str.toInt();
            int bpm=bpm_str.toInt();
            int tmp=tmp_str.toInt();
            if(time_basis==hour_pri)
            {
                 graph_time_x[hour_data_cnt]=(Hour_To_Sec*hour_pri)+(Min_To_Sec*min_pri)+(sec_pri);
                 graph_bpm_y[hour_data_cnt]=bpm;
                 graph_tmp_y[hour_data_cnt++]=tmp;
            }
            bpm_sum+=bpm;
            if(bpm_max<bpm) bpm_max=bpm;
            if(bpm_min>bpm) bpm_min=bpm;
            tmp_sum+=tmp;
            if(tmp_max<tmp) tmp_max=tmp;
            if(tmp_min>tmp) tmp_min=tmp;
            data_cnt++;
          }
        }
        if(data_cnt==0)
        {
            ui->bpm_avg_label->setText("No Data");
            ui->bpm_max_label->setText("No Data");
            ui->bpm_min_label->setText("No Data");
            ui->tmp_avg_label->setText("No Data");
            ui->tmp_max_label->setText("No Data");
            ui->tmp_min_label->setText("No Data");
        }
        else
        {
            ui->bpm_avg_label->setNum((bpm_sum/data_cnt));
            ui->bpm_max_label->setNum(bpm_max);
            ui->bpm_min_label->setNum(bpm_min);
            ui->tmp_avg_label->setNum((tmp_sum/data_cnt));
            ui->tmp_max_label->setNum(tmp_max);
            ui->tmp_min_label->setNum(tmp_min);
        }
    }

}

void Dialog::Draw_pri_data()
{
    QString ui_time_str= ui->hour_combo->currentText();
    int time_basis=ui_time_str.toInt();
    time_basis*=Hour_To_Sec;

    ui->bpm_plot->addGraph();
    ui->bpm_plot->graph(0)->setPen(QPen(Qt::blue));
    ui->bpm_plot->graph(0)->setData(graph_time_x,graph_bpm_y);
    ui->bpm_plot->xAxis->setRange(time_basis,time_basis+Hour_To_Sec);
    ui->bpm_plot->replot();

    ui->tmp_plot->addGraph();
    ui->tmp_plot->graph(0)->setPen(QPen(Qt::red));
    ui->tmp_plot->graph(0)->setData(graph_time_x,graph_tmp_y);
    ui->tmp_plot->xAxis->setRange(time_basis,time_basis+Hour_To_Sec);
    ui->tmp_plot->replot();

}

void Dialog::on_draw_data_button_clicked()
{
    on_load_data_button_clicked();
    Draw_pri_data();
}


void Dialog::on_Close_button_clicked()
{
    close();
}

