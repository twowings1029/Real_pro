#include "mainwindow.h"
#include "ui_mainwindow.h"
/*For raspberry pi*/
static QString arduino_port_name="/dev/ttyACM0";
/*For windows*/
//static QString arduino_port_name="com5";
static QString read_bpm_data;
static QString file_dir="data.txt";
static QVector <double> bpm_x(101),bpm_y(101);
static QVector <double> tmp_x(101),tmp_y(101);
static int graph_count;
static int bpm_int_data;
static int tmp_int_data;
static int velo_int_data;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bpm_label ->setText(".. Waiting ..");
    ui->tmp_label->setText(".. Waiting ..");
    ui->velo_label->setText(".. Waiting ..");

    ui->bpm_plot->xAxis->setLabel("Time");
    ui->bpm_plot->yAxis->setLabel("Bpm");
    ui->bpm_plot->xAxis->setRange(0,100);
    ui->bpm_plot->yAxis->setRange(0,200);

    ui->tmp_plot->xAxis->setLabel("Time");
    ui->tmp_plot->yAxis->setLabel("Temp(℃)");
    ui->tmp_plot->xAxis->setRange(0,100);
    ui->tmp_plot->yAxis->setRange(20,40);

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

void MainWindow::Read_data_from_arduino()
{
    QString raw_data=port->readLine();
    QStringList cmp_list= raw_data.split(" ");
    QString bpm_str=cmp_list.value(0);
    QString tmp_str=cmp_list.value(1);
    QString vel_str=cmp_list.value(2);
    bpm_int_data=bpm_str.toInt();
    bpm_int_data*=3;
    read_bpm_data=QString::number(bpm_int_data);

    tmp_int_data=tmp_str.toInt();
    velo_int_data=vel_str.toInt();

    if(bpm_int_data>=Bpm_Lower_Bound&& tmp_int_data>=Tmp_Lower_Bound)
    {
        ui->bpm_label->setNum(bpm_int_data);
        ui->tmp_label->setNum(tmp_int_data);
        ui->velo_label->setNum(velo_int_data);
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
    year=cd.year();
    month=cd.month();
    day=cd.day();

    day_cal=day_cal.append(QString::number(year));
    day_cal=day_cal.append("-");
    day_cal=day_cal.append(QString::number(month));
    day_cal=day_cal.append("-");
    day_cal=day_cal.append(QString::number(day));

    if(bpm_int_data>=Bpm_Lower_Bound && tmp_int_data>=Tmp_Lower_Bound)
    {
        bpm_x[graph_count]=graph_count;
        bpm_y[graph_count]=bpm_int_data;
        tmp_x[graph_count]=graph_count;
        tmp_y[graph_count++]=tmp_int_data;
        graph_count%=100;
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
            stream<<QString::number(velo_int_data);
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
    port->close();
}


void MainWindow::on_load_data_button_clicked()
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
            QString bpm_str=cmp_list.value(2);
            QString tmp_str=cmp_list.value(3);
            int bpm=bpm_str.toInt();
            int tmp=tmp_str.toInt();
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

void MainWindow::Draw_bpm_data()
{
    ui->bpm_plot->addGraph();
    ui->bpm_plot->graph(0)->setData(bpm_x,bpm_y);
    ui->bpm_plot->xAxis->setLabel("Time");
    ui->bpm_plot->yAxis->setLabel("Bpm");
    ui->bpm_plot->xAxis->setRange(0,100);
    ui->bpm_plot->yAxis->setRange(0,200);
    ui->bpm_plot->replot();
}

void MainWindow::Draw_tmp_data()
{
    ui->tmp_plot->addGraph();
    ui->tmp_plot->graph(0)->setData(tmp_x,tmp_y);
    ui->tmp_plot->xAxis->setLabel("Time");
    ui->tmp_plot->yAxis->setLabel("Temp(℃)");
    ui->tmp_plot->xAxis->setRange(0,100);
    ui->tmp_plot->yAxis->setRange(20,40);
    ui->tmp_plot->replot();
}
