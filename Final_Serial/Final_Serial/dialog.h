#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStringList>
#include <QFileDialog>
#include <QSqlDatabase>
#include "qcustomplot.h"

#define Len_For_year (23)
#define Criteria_year (2017)
#define Len_For_month (12)
#define Len_For_Day (31)
#define Len_For_Hour (24)
#define INF (400)
#define MAX_Pri_Buffer ((4000)+(1))
#define Hour_To_Sec (3600)
#define Min_To_Sec (60)
#define Unit_bpm_graph (40)
#define Unit_temp_graph (5)
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_load_data_button_clicked();

    void on_Close_button_clicked();

    void Draw_pri_data();

    void on_draw_data_button_clicked();

    void Clear_Previous_Data();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
