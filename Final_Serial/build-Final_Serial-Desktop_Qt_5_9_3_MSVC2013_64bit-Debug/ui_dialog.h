/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label_2;
    QLabel *bpm_min_label;
    QLabel *label_7;
    QLabel *tmp_avg_label;
    QLabel *bpm_avg_label;
    QLabel *tmp_max_label;
    QLabel *label_11;
    QLabel *tmp_min_label;
    QLabel *label_4;
    QPushButton *load_data_button;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *bpm_max_label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_12;
    QComboBox *year_combo;
    QComboBox *month_combo;
    QComboBox *day_combo;
    QPushButton *Close_button;
    QCustomPlot *tmp_plot;
    QCustomPlot *bpm_plot;
    QLabel *label;
    QComboBox *hour_combo;
    QPushButton *draw_data_button;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(572, 610);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(7);
        Dialog->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 399, 88, 12));
        bpm_min_label = new QLabel(Dialog);
        bpm_min_label->setObjectName(QStringLiteral("bpm_min_label"));
        bpm_min_label->setGeometry(QRect(299, 479, 93, 30));
        bpm_min_label->setFrameShape(QFrame::StyledPanel);
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(299, 460, 86, 16));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tmp_avg_label = new QLabel(Dialog);
        tmp_avg_label->setObjectName(QStringLiteral("tmp_avg_label"));
        tmp_avg_label->setGeometry(QRect(40, 529, 92, 30));
        tmp_avg_label->setFrameShape(QFrame::StyledPanel);
        bpm_avg_label = new QLabel(Dialog);
        bpm_avg_label->setObjectName(QStringLiteral("bpm_avg_label"));
        bpm_avg_label->setGeometry(QRect(40, 479, 92, 30));
        bpm_avg_label->setFrameShape(QFrame::StyledPanel);
        bpm_avg_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tmp_max_label = new QLabel(Dialog);
        tmp_max_label->setObjectName(QStringLiteral("tmp_max_label"));
        tmp_max_label->setGeometry(QRect(170, 529, 93, 30));
        tmp_max_label->setFrameShape(QFrame::StyledPanel);
        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(299, 510, 86, 16));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tmp_min_label = new QLabel(Dialog);
        tmp_min_label->setObjectName(QStringLiteral("tmp_min_label"));
        tmp_min_label->setGeometry(QRect(299, 529, 93, 30));
        tmp_min_label->setFrameShape(QFrame::StyledPanel);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(299, 399, 88, 12));
        load_data_button = new QPushButton(Dialog);
        load_data_button->setObjectName(QStringLiteral("load_data_button"));
        load_data_button->setGeometry(QRect(430, 460, 100, 40));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 460, 90, 16));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(37, 510, 85, 16));
        label_10->setAlignment(Qt::AlignCenter);
        bpm_max_label = new QLabel(Dialog);
        bpm_max_label->setObjectName(QStringLiteral("bpm_max_label"));
        bpm_max_label->setGeometry(QRect(170, 479, 93, 30));
        bpm_max_label->setFrameShape(QFrame::StyledPanel);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 399, 88, 12));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(37, 460, 85, 16));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_12 = new QLabel(Dialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(170, 510, 90, 16));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        year_combo = new QComboBox(Dialog);
        year_combo->setObjectName(QStringLiteral("year_combo"));
        year_combo->setGeometry(QRect(41, 420, 90, 20));
        month_combo = new QComboBox(Dialog);
        month_combo->setObjectName(QStringLiteral("month_combo"));
        month_combo->setGeometry(QRect(170, 420, 90, 20));
        day_combo = new QComboBox(Dialog);
        day_combo->setObjectName(QStringLiteral("day_combo"));
        day_combo->setGeometry(QRect(300, 420, 90, 20));
        Close_button = new QPushButton(Dialog);
        Close_button->setObjectName(QStringLiteral("Close_button"));
        Close_button->setGeometry(QRect(430, 560, 100, 40));
        tmp_plot = new QCustomPlot(Dialog);
        tmp_plot->setObjectName(QStringLiteral("tmp_plot"));
        tmp_plot->setGeometry(QRect(20, 210, 530, 180));
        bpm_plot = new QCustomPlot(Dialog);
        bpm_plot->setObjectName(QStringLiteral("bpm_plot"));
        bpm_plot->setGeometry(QRect(20, 30, 530, 180));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 400, 56, 12));
        hour_combo = new QComboBox(Dialog);
        hour_combo->setObjectName(QStringLiteral("hour_combo"));
        hour_combo->setGeometry(QRect(430, 420, 90, 22));
        draw_data_button = new QPushButton(Dialog);
        draw_data_button->setObjectName(QStringLiteral("draw_data_button"));
        draw_data_button->setGeometry(QRect(430, 510, 100, 40));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Year", Q_NULLPTR));
        bpm_min_label->setText(QString());
        label_7->setText(QApplication::translate("Dialog", " Bpm min", Q_NULLPTR));
        tmp_avg_label->setText(QString());
        bpm_avg_label->setText(QString());
        tmp_max_label->setText(QString());
        label_11->setText(QApplication::translate("Dialog", "tmp min", Q_NULLPTR));
        tmp_min_label->setText(QString());
        label_4->setText(QApplication::translate("Dialog", "Day", Q_NULLPTR));
        load_data_button->setText(QApplication::translate("Dialog", "Get Data", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", " Bpm max", Q_NULLPTR));
        label_10->setText(QApplication::translate("Dialog", " tmp avg", Q_NULLPTR));
        bpm_max_label->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "Month", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", " Bpm avg", Q_NULLPTR));
        label_12->setText(QApplication::translate("Dialog", "tmp max", Q_NULLPTR));
        Close_button->setText(QApplication::translate("Dialog", "Close", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Hour", Q_NULLPTR));
        draw_data_button->setText(QApplication::translate("Dialog", "Draw Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
