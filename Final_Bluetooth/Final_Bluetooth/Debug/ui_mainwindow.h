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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Connect;
    QPushButton *Close;
    QLabel *label;
    QLabel *bpm_label;
    QPushButton *Pri_data_button;
    QCustomPlot *bpm_plot;
    QLabel *tmp_label;
    QLabel *label_8;
    QLabel *velo_label;
    QLabel *label_9;
    QCustomPlot *tmp_plot;
    QComboBox *age_combo;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *Man_button;
    QRadioButton *Woman_button;
    QLabel *label_3;
    QLabel *pulse_status_label;
    QLabel *label_4;
    QLabel *pulse_target_label;
    QGroupBox *groupBox_2;
    QRadioButton *radio_50;
    QRadioButton *radio_60;
    QRadioButton *radio_70;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(591, 631);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(7);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setGeometry(QRect(340, 440, 101, 41));
        Close = new QPushButton(centralWidget);
        Close->setObjectName(QStringLiteral("Close"));
        Close->setGeometry(QRect(450, 440, 101, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 390, 90, 30));
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        bpm_label = new QLabel(centralWidget);
        bpm_label->setObjectName(QStringLiteral("bpm_label"));
        bpm_label->setGeometry(QRect(130, 390, 70, 30));
        bpm_label->setFrameShape(QFrame::Box);
        Pri_data_button = new QPushButton(centralWidget);
        Pri_data_button->setObjectName(QStringLiteral("Pri_data_button"));
        Pri_data_button->setGeometry(QRect(450, 520, 100, 40));
        bpm_plot = new QCustomPlot(centralWidget);
        bpm_plot->setObjectName(QStringLiteral("bpm_plot"));
        bpm_plot->setGeometry(QRect(20, 10, 530, 180));
        tmp_label = new QLabel(centralWidget);
        tmp_label->setObjectName(QStringLiteral("tmp_label"));
        tmp_label->setGeometry(QRect(300, 390, 70, 30));
        tmp_label->setFrameShape(QFrame::Box);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 390, 90, 30));
        label_8->setFrameShape(QFrame::Box);
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        velo_label = new QLabel(centralWidget);
        velo_label->setObjectName(QStringLiteral("velo_label"));
        velo_label->setGeometry(QRect(470, 390, 70, 30));
        velo_label->setFrameShape(QFrame::Box);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(380, 390, 90, 30));
        label_9->setFrameShape(QFrame::Box);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tmp_plot = new QCustomPlot(centralWidget);
        tmp_plot->setObjectName(QStringLiteral("tmp_plot"));
        tmp_plot->setGeometry(QRect(20, 190, 530, 180));
        age_combo = new QComboBox(centralWidget);
        age_combo->setObjectName(QStringLiteral("age_combo"));
        age_combo->setGeometry(QRect(40, 450, 100, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 430, 81, 21));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(240, 440, 91, 61));
        Man_button = new QRadioButton(groupBox);
        Man_button->setObjectName(QStringLiteral("Man_button"));
        Man_button->setGeometry(QRect(10, 20, 70, 16));
        Woman_button = new QRadioButton(groupBox);
        Woman_button->setObjectName(QStringLiteral("Woman_button"));
        Woman_button->setGeometry(QRect(10, 40, 70, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 490, 56, 12));
        pulse_status_label = new QLabel(centralWidget);
        pulse_status_label->setObjectName(QStringLiteral("pulse_status_label"));
        pulse_status_label->setGeometry(QRect(40, 520, 60, 31));
        pulse_status_label->setFrameShape(QFrame::StyledPanel);
        pulse_status_label->setFrameShadow(QFrame::Plain);
        pulse_status_label->setLineWidth(1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 490, 80, 12));
        pulse_target_label = new QLabel(centralWidget);
        pulse_target_label->setObjectName(QStringLiteral("pulse_target_label"));
        pulse_target_label->setGeometry(QRect(120, 520, 60, 31));
        pulse_target_label->setFrameShape(QFrame::StyledPanel);
        pulse_target_label->setFrameShadow(QFrame::Plain);
        pulse_target_label->setLineWidth(1);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 520, 211, 51));
        radio_50 = new QRadioButton(groupBox_2);
        radio_50->setObjectName(QStringLiteral("radio_50"));
        radio_50->setGeometry(QRect(11, 21, 41, 16));
        radio_60 = new QRadioButton(groupBox_2);
        radio_60->setObjectName(QStringLiteral("radio_60"));
        radio_60->setGeometry(QRect(80, 21, 41, 16));
        radio_70 = new QRadioButton(groupBox_2);
        radio_70->setObjectName(QStringLiteral("radio_70"));
        radio_70->setGeometry(QRect(150, 21, 41, 16));
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
        Connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        Close->setText(QApplication::translate("MainWindow", "Close", 0));
        label->setText(QApplication::translate("MainWindow", "Current Bpm", 0));
        bpm_label->setText(QString());
        Pri_data_button->setText(QApplication::translate("MainWindow", "Previous Data", 0));
        tmp_label->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Current Tmp", 0));
        velo_label->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Current Velo", 0));
        label_2->setText(QApplication::translate("MainWindow", "Age", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Gender", 0));
        Man_button->setText(QApplication::translate("MainWindow", "Man", 0));
        Woman_button->setText(QApplication::translate("MainWindow", "Woman", 0));
        label_3->setText(QApplication::translate("MainWindow", "Status", 0));
        pulse_status_label->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Target bpm", 0));
        pulse_target_label->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Intensity", 0));
        radio_50->setText(QApplication::translate("MainWindow", "50%", 0));
        radio_60->setText(QApplication::translate("MainWindow", "60%", 0));
        radio_70->setText(QApplication::translate("MainWindow", "70%", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
