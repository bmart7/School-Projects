/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <newlabel.h>
#include <newlineedit.h>
#include <newslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    NewLabel *labelFox;
    QLabel *labelLineEdit;
    QLabel *labelComboBox;
    QLabel *labelSlider;
    QLabel *labelButtons;
    NewSlider *sliderSize;
    QRadioButton *radioButtonAriel;
    QRadioButton *radioButtonTNR;
    QRadioButton *radioButtonComic;
    QComboBox *comboBoxFont;
    NewLineEdit *lineEditFont;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(690, 354);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelFox = new NewLabel(centralWidget);
        labelFox->setObjectName(QString::fromUtf8("labelFox"));
        labelFox->setGeometry(QRect(0, 10, 691, 151));
        labelLineEdit = new QLabel(centralWidget);
        labelLineEdit->setObjectName(QString::fromUtf8("labelLineEdit"));
        labelLineEdit->setGeometry(QRect(10, 170, 91, 16));
        labelComboBox = new QLabel(centralWidget);
        labelComboBox->setObjectName(QString::fromUtf8("labelComboBox"));
        labelComboBox->setGeometry(QRect(10, 200, 91, 16));
        labelSlider = new QLabel(centralWidget);
        labelSlider->setObjectName(QString::fromUtf8("labelSlider"));
        labelSlider->setGeometry(QRect(10, 260, 91, 16));
        labelButtons = new QLabel(centralWidget);
        labelButtons->setObjectName(QString::fromUtf8("labelButtons"));
        labelButtons->setGeometry(QRect(10, 230, 91, 16));
        sliderSize = new NewSlider(centralWidget);
        sliderSize->setObjectName(QString::fromUtf8("sliderSize"));
        sliderSize->setGeometry(QRect(330, 260, 161, 22));
        sliderSize->setMinimum(10);
        sliderSize->setMaximum(40);
        sliderSize->setOrientation(Qt::Horizontal);
        radioButtonAriel = new QRadioButton(centralWidget);
        radioButtonAriel->setObjectName(QString::fromUtf8("radioButtonAriel"));
        radioButtonAriel->setGeometry(QRect(240, 230, 97, 20));
        radioButtonTNR = new QRadioButton(centralWidget);
        radioButtonTNR->setObjectName(QString::fromUtf8("radioButtonTNR"));
        radioButtonTNR->setGeometry(QRect(336, 230, 141, 20));
        radioButtonComic = new QRadioButton(centralWidget);
        radioButtonComic->setObjectName(QString::fromUtf8("radioButtonComic"));
        radioButtonComic->setGeometry(QRect(510, 230, 131, 20));
        comboBoxFont = new QComboBox(centralWidget);
        comboBoxFont->addItem(QString());
        comboBoxFont->addItem(QString());
        comboBoxFont->addItem(QString());
        comboBoxFont->setObjectName(QString::fromUtf8("comboBoxFont"));
        comboBoxFont->setGeometry(QRect(370, 190, 251, 32));
        lineEditFont = new NewLineEdit(centralWidget);
        lineEditFont->setObjectName(QString::fromUtf8("lineEditFont"));
        lineEditFont->setGeometry(QRect(300, 170, 311, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 690, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        labelFox->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">The quick brown fox likes CSE 335.</p></body></html>", nullptr));
        labelLineEdit->setText(QApplication::translate("MainWindow", "Font Size Type", nullptr));
        labelComboBox->setText(QApplication::translate("MainWindow", "Font Size Type", nullptr));
        labelSlider->setText(QApplication::translate("MainWindow", "Font Size", nullptr));
        labelButtons->setText(QApplication::translate("MainWindow", "Family", nullptr));
        radioButtonAriel->setText(QApplication::translate("MainWindow", "Ariel", nullptr));
        radioButtonTNR->setText(QApplication::translate("MainWindow", "Times New Roman", nullptr));
        radioButtonComic->setText(QApplication::translate("MainWindow", "Comic Sans MS", nullptr));
        comboBoxFont->setItemText(0, QApplication::translate("MainWindow", "small", nullptr));
        comboBoxFont->setItemText(1, QApplication::translate("MainWindow", "medium", nullptr));
        comboBoxFont->setItemText(2, QApplication::translate("MainWindow", "big", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
