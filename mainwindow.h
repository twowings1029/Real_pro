#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QObject>
#include <QPixmap>
#include <QPainter>
#include <QLine>
#include <QColor>
#include <QPaintDevice>
#include <QDateTime>
#include <QVector>
#include <QString>
#include <QtSql>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QStringList>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void Read_data_from_arduino();

    void on_Close_port_clicked();

    void on_Connect_Port_clicked();

    void Save_Data();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *port;
};

#endif // MAINWINDOW_H
