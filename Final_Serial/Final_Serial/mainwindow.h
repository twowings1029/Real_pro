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
#include <QStringList>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QTime>
#include <QVector>
#include <QDebug>
#include "qcustomplot.h"

#define Len_For_year (23)
#define Criteria_year (2017)
#define Len_For_month (12)
#define Len_For_Day (31)
#define INF (400)
#define Bpm_Lower_Bound (40)
#define Bpm_Upper_Bound (210)
#define Tmp_Lower_Bound (20)
#define Max_For_Graph (100)
#define Hour_To_Sec (3600)
#define Time_Interval ((240)+(5))
#define Min_To_Sec (60)
#define Unit_Graph_time (30)
#define Age_List_Num (10)
#define Man (0)
#define Woman (1)
#define Intensity_50_flag (0)
#define Intensity_60_flag (1)
#define Intensity_70_flag (2)
#define Intensity_50_ratio (0.5)
#define Intensity_60_ratio (0.6)
#define Intensity_70_ratio (0.7)
#define Unit_bpm_graph (40)
#define Unit_temp_graph (5)
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

    void Draw_bpm_data();

    void Draw_tmp_data();

    void on_Pri_data_button_clicked();

    void on_Man_button_clicked();

    void on_Woman_button_clicked();

    void on_radio_50_clicked();

    void on_radio_60_clicked();

    void on_radio_70_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *port;
    void Is_Normal(QString &x);
};

#endif // MAINWINDOW_H
