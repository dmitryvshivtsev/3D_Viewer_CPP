/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_number_of_v;
    QLabel *label_number_of_f;
    QLabel *label_4;
    QComboBox *comboBox_projection;
    QLabel *label_5;
    QLabel *label_7;
    QComboBox *comboBox_lineType;
    QPushButton *pushButton_zoom;
    QDoubleSpinBox *doubleSpinBox_zoomVal;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox_V_type;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_move;
    QPushButton *pushButton_rotate;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_move_x;
    QDoubleSpinBox *doubleSpinBox_move_y;
    QDoubleSpinBox *doubleSpinBox_move_z;
    QPushButton *pushButton_back_col;
    QPushButton *pushButton_line_col;
    QPushButton *pushButton_ver_col;
    QDoubleSpinBox *doubleSpinBox_rotate_x;
    QDoubleSpinBox *doubleSpinBox_rotate_y;
    QDoubleSpinBox *doubleSpinBox_rotate_z;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_v_size;
    QDoubleSpinBox *doubleSpinBox_line_width;
    QLabel *Image;
    QPushButton *pushButton_start_gif;
    QPushButton *pushButton_edit;
    QLabel *label_timer;
    QPushButton *pushButton_save_image;
    Widget *widget;
    QLabel *label_19;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1470, 807);
        MainWindow->setBaseSize(QSize(1400, 820));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 531, 41));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 230, 91, 31));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        label_number_of_v = new QLabel(centralwidget);
        label_number_of_v->setObjectName(QString::fromUtf8("label_number_of_v"));
        label_number_of_v->setGeometry(QRect(10, 190, 91, 31));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(false);
        label_number_of_v->setFont(font1);
        label_number_of_v->setAlignment(Qt::AlignCenter);
        label_number_of_v->setWordWrap(true);
        label_number_of_f = new QLabel(centralwidget);
        label_number_of_f->setObjectName(QString::fromUtf8("label_number_of_f"));
        label_number_of_f->setGeometry(QRect(10, 280, 91, 31));
        label_number_of_f->setFont(font1);
        label_number_of_f->setAlignment(Qt::AlignCenter);
        label_number_of_f->setWordWrap(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 320, 91, 31));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        comboBox_projection = new QComboBox(centralwidget);
        comboBox_projection->addItem(QString());
        comboBox_projection->addItem(QString());
        comboBox_projection->setObjectName(QString::fromUtf8("comboBox_projection"));
        comboBox_projection->setGeometry(QRect(30, 110, 181, 31));
        QFont font2;
        font2.setPointSize(14);
        comboBox_projection->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 140, 101, 31));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 140, 101, 31));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);
        comboBox_lineType = new QComboBox(centralwidget);
        comboBox_lineType->addItem(QString());
        comboBox_lineType->addItem(QString());
        comboBox_lineType->setObjectName(QString::fromUtf8("comboBox_lineType"));
        comboBox_lineType->setGeometry(QRect(230, 110, 181, 31));
        comboBox_lineType->setFont(font2);
        pushButton_zoom = new QPushButton(centralwidget);
        pushButton_zoom->setObjectName(QString::fromUtf8("pushButton_zoom"));
        pushButton_zoom->setGeometry(QRect(510, 320, 101, 32));
        QFont font3;
        font3.setPointSize(15);
        pushButton_zoom->setFont(font3);
        doubleSpinBox_zoomVal = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_zoomVal->setObjectName(QString::fromUtf8("doubleSpinBox_zoomVal"));
        doubleSpinBox_zoomVal->setGeometry(QRect(510, 280, 101, 31));
        doubleSpinBox_zoomVal->setFont(font3);
        doubleSpinBox_zoomVal->setMinimum(0.100000000000000);
        doubleSpinBox_zoomVal->setMaximum(5.000000000000000);
        doubleSpinBox_zoomVal->setValue(1.500000000000000);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(500, 350, 121, 31));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(120, 230, 91, 31));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setWordWrap(true);
        comboBox_V_type = new QComboBox(centralwidget);
        comboBox_V_type->addItem(QString());
        comboBox_V_type->addItem(QString());
        comboBox_V_type->addItem(QString());
        comboBox_V_type->setObjectName(QString::fromUtf8("comboBox_V_type"));
        comboBox_V_type->setGeometry(QRect(430, 110, 181, 31));
        comboBox_V_type->setFont(font2);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(470, 140, 101, 31));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(true);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(220, 230, 91, 31));
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setWordWrap(true);
        pushButton_move = new QPushButton(centralwidget);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));
        pushButton_move->setGeometry(QRect(420, 270, 61, 32));
        pushButton_move->setFont(font3);
        pushButton_rotate = new QPushButton(centralwidget);
        pushButton_rotate->setObjectName(QString::fromUtf8("pushButton_rotate"));
        pushButton_rotate->setGeometry(QRect(420, 330, 61, 32));
        pushButton_rotate->setFont(font3);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(120, 300, 91, 31));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setWordWrap(true);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(220, 300, 91, 31));
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(true);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(320, 300, 91, 31));
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(true);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(320, 360, 91, 31));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setWordWrap(true);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(220, 360, 91, 31));
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignCenter);
        label_16->setWordWrap(true);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(120, 360, 91, 31));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);
        label_17->setWordWrap(true);
        doubleSpinBox_move_x = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_move_x->setObjectName(QString::fromUtf8("doubleSpinBox_move_x"));
        doubleSpinBox_move_x->setGeometry(QRect(130, 270, 71, 31));
        doubleSpinBox_move_x->setFont(font3);
        doubleSpinBox_move_x->setMinimum(-50.000000000000000);
        doubleSpinBox_move_y = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_move_y->setObjectName(QString::fromUtf8("doubleSpinBox_move_y"));
        doubleSpinBox_move_y->setGeometry(QRect(230, 270, 71, 31));
        doubleSpinBox_move_y->setFont(font3);
        doubleSpinBox_move_y->setMinimum(-50.000000000000000);
        doubleSpinBox_move_z = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_move_z->setObjectName(QString::fromUtf8("doubleSpinBox_move_z"));
        doubleSpinBox_move_z->setGeometry(QRect(330, 270, 71, 31));
        doubleSpinBox_move_z->setFont(font3);
        doubleSpinBox_move_z->setMinimum(-50.000000000000000);
        doubleSpinBox_move_z->setValue(0.000000000000000);
        pushButton_back_col = new QPushButton(centralwidget);
        pushButton_back_col->setObjectName(QString::fromUtf8("pushButton_back_col"));
        pushButton_back_col->setGeometry(QRect(330, 180, 91, 51));
        pushButton_back_col->setFont(font2);
        pushButton_back_col->setAcceptDrops(false);
        pushButton_line_col = new QPushButton(centralwidget);
        pushButton_line_col->setObjectName(QString::fromUtf8("pushButton_line_col"));
        pushButton_line_col->setGeometry(QRect(430, 180, 91, 51));
        pushButton_line_col->setFont(font2);
        pushButton_line_col->setAcceptDrops(false);
        pushButton_ver_col = new QPushButton(centralwidget);
        pushButton_ver_col->setObjectName(QString::fromUtf8("pushButton_ver_col"));
        pushButton_ver_col->setGeometry(QRect(530, 180, 91, 51));
        pushButton_ver_col->setFont(font2);
        pushButton_ver_col->setAcceptDrops(false);
        doubleSpinBox_rotate_x = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_rotate_x->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_x"));
        doubleSpinBox_rotate_x->setGeometry(QRect(130, 330, 71, 31));
        doubleSpinBox_rotate_x->setFont(font3);
        doubleSpinBox_rotate_x->setMinimum(-50.000000000000000);
        doubleSpinBox_rotate_y = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_rotate_y->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_y"));
        doubleSpinBox_rotate_y->setGeometry(QRect(230, 330, 71, 31));
        doubleSpinBox_rotate_y->setFont(font3);
        doubleSpinBox_rotate_y->setMinimum(-50.000000000000000);
        doubleSpinBox_rotate_z = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_rotate_z->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_z"));
        doubleSpinBox_rotate_z->setGeometry(QRect(330, 330, 71, 31));
        doubleSpinBox_rotate_z->setFont(font3);
        doubleSpinBox_rotate_z->setMinimum(-50.000000000000000);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(430, 230, 91, 31));
        label_18->setFont(font2);
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(true);
        doubleSpinBox_v_size = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_v_size->setObjectName(QString::fromUtf8("doubleSpinBox_v_size"));
        doubleSpinBox_v_size->setGeometry(QRect(130, 190, 71, 31));
        doubleSpinBox_v_size->setFont(font3);
        doubleSpinBox_v_size->setMinimum(1.000000000000000);
        doubleSpinBox_line_width = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_line_width->setObjectName(QString::fromUtf8("doubleSpinBox_line_width"));
        doubleSpinBox_line_width->setGeometry(QRect(230, 190, 71, 31));
        doubleSpinBox_line_width->setFont(font3);
        doubleSpinBox_line_width->setMinimum(1.000000000000000);
        Image = new QLabel(centralwidget);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(20, 400, 611, 361));
        Image->setPixmap(QPixmap(QString::fromUtf8("img/fi.jpeg")));
        pushButton_start_gif = new QPushButton(centralwidget);
        pushButton_start_gif->setObjectName(QString::fromUtf8("pushButton_start_gif"));
        pushButton_start_gif->setGeometry(QRect(380, 70, 121, 32));
        pushButton_edit = new QPushButton(centralwidget);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setGeometry(QRect(30, 70, 171, 32));
        label_timer = new QLabel(centralwidget);
        label_timer->setObjectName(QString::fromUtf8("label_timer"));
        label_timer->setGeometry(QRect(520, 70, 91, 31));
        QFont font4;
        font4.setPointSize(16);
        label_timer->setFont(font4);
        label_timer->setAlignment(Qt::AlignCenter);
        pushButton_save_image = new QPushButton(centralwidget);
        pushButton_save_image->setObjectName(QString::fromUtf8("pushButton_save_image"));
        pushButton_save_image->setGeometry(QRect(220, 70, 141, 32));
        widget = new Widget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(640, 0, 831, 781));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 20, 61, 41));
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignCenter);
        label_19->setWordWrap(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Number of vertexes", nullptr));
        label_number_of_v->setText(QString());
        label_number_of_f->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Number of facets", nullptr));
        comboBox_projection->setItemText(0, QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        comboBox_projection->setItemText(1, QCoreApplication::translate("MainWindow", "Central", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Line type", nullptr));
        comboBox_lineType->setItemText(0, QCoreApplication::translate("MainWindow", "Solid", nullptr));
        comboBox_lineType->setItemText(1, QCoreApplication::translate("MainWindow", "Dashed", nullptr));

        pushButton_zoom->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Vertex size", nullptr));
        comboBox_V_type->setItemText(0, QCoreApplication::translate("MainWindow", "Without vertex", nullptr));
        comboBox_V_type->setItemText(1, QCoreApplication::translate("MainWindow", "Square", nullptr));
        comboBox_V_type->setItemText(2, QCoreApplication::translate("MainWindow", "Circle", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "Vertex Type", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Line width", nullptr));
        pushButton_move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        pushButton_rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_back_col->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        pushButton_line_col->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        pushButton_ver_col->setText(QCoreApplication::translate("MainWindow", "Vertex", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        Image->setText(QString());
        pushButton_start_gif->setText(QCoreApplication::translate("MainWindow", "Start recording", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("MainWindow", "Choose a file", nullptr));
        label_timer->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_save_image->setText(QCoreApplication::translate("MainWindow", "Save image", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Path:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
