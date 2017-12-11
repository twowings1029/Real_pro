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
    read_bpm_data=port->readLine(4);
    ui->bpm_label ->setText(read_bpm_data);
}

void MainWindow::Draw_bpm_from_arduino()
{
    QDate cd;
    QTime ct = QTime::currentTime();
    QString date;
    date.append(cd.year);
    date.append('-');
    date.appedn(cd.month);
    date.append('-');
    date.appedn(cd.day);
    QString time=ct.toString();
    QVector< QString > vector;
    vector.append(time);
    vector.append(read_bpm_data);
    QFile file(file_dir);


    if(file.open(QIODevice::ReadWrite | QIODevice :: Text))
    {
        QTextStream stream(&file);
        while(stream.readLine()!="")
        {
           //stream<<endl;
        }
        stream<<date<<" ";
        stream<<time<<" ";
        stream<<read_bpm_data;
        file.flush();
        file.close();
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

