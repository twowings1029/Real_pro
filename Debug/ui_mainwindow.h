/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Connect_Port;
    QPushButton *Close_port;
    QLabel *label;
    QLabel *bpm_label;
    QPushButton *load_data_button;
    QComboBox *year_combo;
    QComboBox *month_combo;
    QComboBox *day_combo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *bpm_avg_label;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *bpm_max_label;
    QLabel *bpm_min_label;
    QCustomPlot *bpm_plot;
    QLabel *tmp_label;
    QLabel *label_8;
    QLabel *velo_label;
    QLabel *label_9;
    QCustomPlot *tmp_plot;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *tmp_max_label;
    QLabel *label_12;
    QLabel *tmp_min_label;
    QLabel *tmp_avg_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(591, 631);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Connect_Port = new QPushButton(centralWidget);
        Connect_Port->setObjectName(QStringLiteral("Connect_Port"));
        Connect_Port->setGeometry(QRect(350, 460, 101, 41));
        Close_port = new QPushButton(centralWidget);
        Close_port->setObjectName(QStringLiteral("Close_port"));
        Close_port->setGeometry(QRect(460, 460, 101, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 380, 81, 30));
        label->setFrameShape(QFrame::Box);
        bpm_label = new QLabel(centralWidget);
        bpm_label->setObjectName(QStringLiteral("bpm_label"));
        bpm_label->setGeometry(QRect(130, 380, 61, 30));
        bpm_label->setFrameShape(QFrame::Box);
        load_data_button = new QPushButton(centralWidget);
        load_data_button->setObjectName(QStringLiteral("load_data_button"));
        load_data_button->setGeometry(QRect(420, 520, 110, 40));
        year_combo = new QComboBox(centralWidget);
        year_combo->setObjectName(QStringLiteral("year_combo"));
        year_combo->setGeometry(QRect(30, 441, 76, 20));
        month_combo = new QComboBox(centralWidget);
        month_combo->setObjectName(QStringLiteral("month_combo"));
        month_combo->setGeometry(QRect(139, 441, 76, 20));
        day_combo = new QComboBox(centralWidget);
        day_combo->setObjectName(QStringLiteral("day_combo"));
        day_combo->setGeometry(QRect(251, 441, 76, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 421, 56, 12));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 421, 56, 12));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 421, 56, 12));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(37, 471, 53, 16));
        bpm_avg_label = new QLabel(centralWidget);
        bpm_avg_label->setObjectName(QStringLiteral("bpm_avg_label"));
        bpm_avg_label->setGeometry(QRect(40, 490, 60, 30));
        bpm_avg_label->setFrameShape(QFrame::StyledPanel);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 471, 58, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 471, 54, 16));
        bpm_max_label = new QLabel(centralWidget);
        bpm_max_label->setObjectName(QStringLiteral("bpm_max_label"));
        bpm_max_label->setGeometry(QRect(150, 490, 61, 30));
        bpm_max_label->setFrameShape(QFrame::StyledPanel);
        bpm_min_label = new QLabel(centralWidget);
        bpm_min_label->setObjectName(QStringLiteral("bpm_min_label"));
        bpm_min_label->setGeometry(QRect(260, 490, 61, 30));
        bpm_min_label->setFrameShape(QFrame::StyledPanel);
        bpm_plot = new QCustomPlot(centralWidget);
        bpm_plot->setObjectName(QStringLiteral("bpm_plot"));
        bpm_plot->setGeometry(QRect(40, 10, 490, 180));
        tmp_label = new QLabel(centralWidget);
        tmp_label->setObjectName(QStringLiteral("tmp_label"));
        tmp_label->setGeometry(QRect(300, 380, 61, 30));
        tmp_label->setFrameShape(QFrame::Box);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 380, 81, 30));
        label_8->setFrameShape(QFrame::Box);
        velo_label = new QLabel(centralWidget);
        velo_label->setObjectName(QStringLiteral("velo_label"));
        velo_label->setGeometry(QRect(470, 380, 61, 30));
        velo_label->setFrameShape(QFrame::Box);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(380, 380, 81, 30));
        label_9->setFrameShape(QFrame::Box);
        tmp_plot = new QCustomPlot(centralWidget);
        tmp_plot->setObjectName(QStringLiteral("tmp_plot"));
        tmp_plot->setGeometry(QRect(40, 190, 490, 180));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(37, 521, 53, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(260, 521, 54, 16));
        tmp_max_label = new QLabel(centralWidget);
        tmp_max_label->setObjectName(QStringLiteral("tmp_max_label"));
        tmp_max_label->setGeometry(QRect(150, 540, 61, 30));
        tmp_max_label->setFrameShape(QFrame::StyledPanel);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(150, 521, 58, 16));
        tmp_min_label = new QLabel(centralWidget);
        tmp_min_label->setObjectName(QStringLiteral("tmp_min_label"));
        tmp_min_label->setGeometry(QRect(260, 540, 61, 30));
        tmp_min_label->setFrameShape(QFrame::StyledPanel);
        tmp_avg_label = new QLabel(centralWidget);
        tmp_avg_label->setObjectName(QStringLiteral("tmp_avg_label"));
        tmp_avg_label->setGeometry(QRect(40, 540, 60, 30));
        tmp_avg_label->setFrameShape(QFrame::StyledPanel);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 591, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Connect_Port->setText(QApplication::translate("MainWindow", "Connect Port", 0));
        Close_port->setText(QApplication::translate("MainWindow", "Close Port", 0));
        label->setText(QApplication::translate("MainWindow", "Current Bpm", 0));
        bpm_label->setText(QString());
        load_data_button->setText(QApplication::translate("MainWindow", "Get Data", 0));
        label_2->setText(QApplication::translate("MainWindow", "Year", 0));
        label_3->setText(QApplication::translate("MainWindow", "Month", 0));
        label_4->setText(QApplication::translate("MainWindow", "Day", 0));
        label_5->setText(QApplication::translate("MainWindow", " Bpm avg", 0));
        bpm_avg_label->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", " Bpm max", 0));
        label_7->setText(QApplication::translate("MainWindow", " Bpm min", 0));
        bpm_max_label->setText(QString());
        bpm_min_label->setText(QString());
        tmp_label->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Current Tmp", 0));
        velo_label->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Current Velo", 0));
        label_10->setText(QApplication::translate("MainWindow", " tmp avg", 0));
        label_11->setText(QApplication::translate("MainWindow", "tmp min", 0));
        tmp_max_label->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "tmp max", 0));
        tmp_min_label->setText(QString());
        tmp_avg_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
