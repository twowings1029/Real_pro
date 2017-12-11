#include "mainwindow.h"
#include "ui_mainwindow.h"
/*For raspberry pi*/

//static QString arduino_port_name="/dev/ttyACM0";

/*For windows*/
static QString arduino_port_name="com5";
static QString read_bpm_data;
static QString file_dir="data.txt";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bpm_label ->setText(".. Waiting ..");

    port=new QSerialPort();
    port->setPortName(arduino_port_name);
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
    QObject::connect(port,SIGNAL(readyRead()),this,SLOT(Read_bpm_from_arduino()));
    QObject::connect(port,SIGNAL(readyRead()),this,SLOT(Draw_bpm_from_arduino()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Read_bpm_from_arduino()
{
    int int_data;
    read_bpm_data=port->readLine(3);
    int_data=read_bpm_data.toInt();
    int_data*=3;
    read_bpm_data=QString::number(int_data);
    ui->bpm_label->setNum(int_data);
}

void MainWindow::Draw_bpm_from_arduino()
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
        if(read_bpm_data.toInt()!=0)
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

