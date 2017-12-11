#include "mainwindow.h"
#include "ui_mainwindow.h"
/*For raspberry pi*/

//static QString arduino_port_name="/dev/ttyACM0";

/*For windows*/
static QString arduino_port_name="com5";
static QString read_bpm_data;
static QString file_dir="data.txt";
#define Len_For_year (5)
#define Criteria_year (2017)
#define Len_For_month (12)
#define Len_For_Day (31)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bpm_label ->setText(".. Waiting ..");

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Read_data_from_arduino()
{
    int int_data;
    read_bpm_data=port->readLine(3);
    int_data=read_bpm_data.toInt();
    int_data*=3;
    read_bpm_data=QString::number(int_data);
    ui->bpm_label->setNum(int_data);
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
    QVector< QString > vector;
    day_cal=day_cal.append(QString::number(year));
    day_cal=day_cal.append("-");
    day_cal=day_cal.append(QString::number(month));
    day_cal=day_cal.append("-");
    day_cal=day_cal.append(QString::number(day));

    vector.append(time);
    vector.append(read_bpm_data);
    QFile file(file_dir);

    if(file.open(QIODevice::ReadWrite | QIODevice :: Text))
    {
        QTextStream stream(&file);
        if(read_bpm_data.toInt()<=50)
        {
            while(stream.readLine()!="");
            stream<<day_cal<<" ";
            stream<<time<<" ";
            stream<<read_bpm_data<<endl;
            file.flush();
            file.close();
        }
    }
}

void MainWindow::on_Connect_Port_clicked()
{
    port->open(QIODevice::ReadWrite);
    if (port->isOpen() == false)
    {
        ui->bpm_label->setText("Error");
    }
}
void MainWindow::on_Close_port_clicked()
{
    ui->bpm_label ->setText(".. closed ..");
    port->close();
}


void MainWindow::on_pushButton_clicked()
{

}
