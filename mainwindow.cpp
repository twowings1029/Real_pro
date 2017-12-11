#include "mainwindow.h"
#include "ui_mainwindow.h"
/*For raspberry pi*/

//static QString arduino_port_name="/dev/ttyACM0";

/*For windows*/
static QString arduino_port_name="com5";
static QByteArray read_bpm_data;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bpm_label ->setText(".. Waiting ..");

    port=new QSerialPort();
    port->setPortName(arduino_port_name);
    port->setBaudRate(QSerialPort::Baud9600);
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
    qint64 width;
    QString draw_line;
    int i;
    width=read_bpm_data.toInt();
    ui->bpm_graph->setText(" ");
    draw_line.clear();
    for(i=0;i<width*2;i++)
    {
        draw_line.append('=');
    }
    ui->bpm_graph->setText(draw_line);
    /*QPixmap p;
    QPainter tmp(&p);
    QColor White(255,255,255,0);
    tmp.drawRect(0,0,400,20);
    tmp.setPen(White);
    ui->bpm_label->setPixmap(p);
    tmp.drawRect(0,0,2*width,20);
    tmp.setPen(White);
    tmp.end();
    ui->bpm_label->setPixmap(p);*/
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

