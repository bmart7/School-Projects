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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <alexlabel.h>
#include <alexlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLabel *labelFamily;
    AlexLabel *labelFox;
    QLabel *label;
    QFontComboBox *fontComboBox;
    AlexLineEdit *lineEditFamily;
    QLabel *label_3;
    QLineEdit *lineEditSize;
    QWidget *widgetWeight;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxBold;
    QCheckBox *checkBoxItalic;
    QCheckBox *checkBoxUnderline;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(777, 301);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelFamily = new QLabel(centralWidget);
        labelFamily->setObjectName(QString::fromUtf8("labelFamily"));

        gridLayout_2->addWidget(labelFamily, 1, 0, 1, 1);

        labelFox = new AlexLabel(centralWidget);
        labelFox->setObjectName(QString::fromUtf8("labelFox"));

        gridLayout_2->addWidget(labelFox, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        fontComboBox = new QFontComboBox(centralWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout_2->addWidget(fontComboBox, 2, 1, 1, 1);

        lineEditFamily = new AlexLineEdit(centralWidget);
        lineEditFamily->setObjectName(QString::fromUtf8("lineEditFamily"));

        gridLayout_2->addWidget(lineEditFamily, 1, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        lineEditSize = new QLineEdit(centralWidget);
        lineEditSize->setObjectName(QString::fromUtf8("lineEditSize"));

        gridLayout_2->addWidget(lineEditSize, 4, 1, 1, 1);

        widgetWeight = new QWidget(centralWidget);
        widgetWeight->setObjectName(QString::fromUtf8("widgetWeight"));
        horizontalLayout = new QHBoxLayout(widgetWeight);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBoxBold = new QCheckBox(widgetWeight);
        checkBoxBold->setObjectName(QString::fromUtf8("checkBoxBold"));

        horizontalLayout->addWidget(checkBoxBold);

        checkBoxItalic = new QCheckBox(widgetWeight);
        checkBoxItalic->setObjectName(QString::fromUtf8("checkBoxItalic"));

        horizontalLayout->addWidget(checkBoxItalic);

        checkBoxUnderline = new QCheckBox(widgetWeight);
        checkBoxUnderline->setObjectName(QString::fromUtf8("checkBoxUnderline"));

        horizontalLayout->addWidget(checkBoxUnderline);


        gridLayout_2->addWidget(widgetWeight, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        labelFamily->raise();
        lineEditFamily->raise();
        fontComboBox->raise();
        label->raise();
        widgetWeight->raise();
        label_3->raise();
        lineEditSize->raise();
        labelFox->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 777, 20));
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
        labelFamily->setText(QApplication::translate("MainWindow", "Family", nullptr));
        labelFox->setText(QApplication::translate("MainWindow", "The quick brown fox likes CSE 335", nullptr));
        label->setText(QApplication::translate("MainWindow", "Style", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Size", nullptr));
        checkBoxBold->setText(QApplication::translate("MainWindow", "Bold", nullptr));
        checkBoxItalic->setText(QApplication::translate("MainWindow", "Italic", nullptr));
        checkBoxUnderline->setText(QApplication::translate("MainWindow", "Underline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
