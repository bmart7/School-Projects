/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(777, 301);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelFamily = new QLabel(centralWidget);
        labelFamily->setObjectName(QStringLiteral("labelFamily"));

        gridLayout_2->addWidget(labelFamily, 1, 0, 1, 1);

        labelFox = new AlexLabel(centralWidget);
        labelFox->setObjectName(QStringLiteral("labelFox"));

        gridLayout_2->addWidget(labelFox, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        fontComboBox = new QFontComboBox(centralWidget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        gridLayout_2->addWidget(fontComboBox, 2, 1, 1, 1);

        lineEditFamily = new AlexLineEdit(centralWidget);
        lineEditFamily->setObjectName(QStringLiteral("lineEditFamily"));

        gridLayout_2->addWidget(lineEditFamily, 1, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        lineEditSize = new QLineEdit(centralWidget);
        lineEditSize->setObjectName(QStringLiteral("lineEditSize"));

        gridLayout_2->addWidget(lineEditSize, 4, 1, 1, 1);

        widgetWeight = new QWidget(centralWidget);
        widgetWeight->setObjectName(QStringLiteral("widgetWeight"));
        horizontalLayout = new QHBoxLayout(widgetWeight);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxBold = new QCheckBox(widgetWeight);
        checkBoxBold->setObjectName(QStringLiteral("checkBoxBold"));

        horizontalLayout->addWidget(checkBoxBold);

        checkBoxItalic = new QCheckBox(widgetWeight);
        checkBoxItalic->setObjectName(QStringLiteral("checkBoxItalic"));

        horizontalLayout->addWidget(checkBoxItalic);

        checkBoxUnderline = new QCheckBox(widgetWeight);
        checkBoxUnderline->setObjectName(QStringLiteral("checkBoxUnderline"));

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
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 777, 20));
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
        labelFamily->setText(QApplication::translate("MainWindow", "Family", 0));
        labelFox->setText(QApplication::translate("MainWindow", "The quick brown fox likes CSE 335", 0));
        label->setText(QApplication::translate("MainWindow", "Style", 0));
        label_3->setText(QApplication::translate("MainWindow", "Size", 0));
        checkBoxBold->setText(QApplication::translate("MainWindow", "Bold", 0));
        checkBoxItalic->setText(QApplication::translate("MainWindow", "Italic", 0));
        checkBoxUnderline->setText(QApplication::translate("MainWindow", "Underline", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
