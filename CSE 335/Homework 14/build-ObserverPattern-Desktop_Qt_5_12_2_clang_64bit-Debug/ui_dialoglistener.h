/********************************************************************************
** Form generated from reading UI file 'dialoglistener.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLISTENER_H
#define UI_DIALOGLISTENER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogListener
{
public:
    QLabel *label;
    QLabel *value;
    QPushButton *resetButton;

    void setupUi(QDialog *DialogListener)
    {
        if (DialogListener->objectName().isEmpty())
            DialogListener->setObjectName(QString::fromUtf8("DialogListener"));
        DialogListener->resize(400, 300);
        label = new QLabel(DialogListener);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 130, 57, 16));
        value = new QLabel(DialogListener);
        value->setObjectName(QString::fromUtf8("value"));
        value->setGeometry(QRect(170, 130, 57, 16));
        resetButton = new QPushButton(DialogListener);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(140, 180, 111, 32));

        retranslateUi(DialogListener);

        QMetaObject::connectSlotsByName(DialogListener);
    } // setupUi

    void retranslateUi(QDialog *DialogListener)
    {
        DialogListener->setWindowTitle(QApplication::translate("DialogListener", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogListener", "TextLabel", nullptr));
        value->setText(QApplication::translate("DialogListener", "TextLabel", nullptr));
        resetButton->setText(QApplication::translate("DialogListener", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogListener: public Ui_DialogListener {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLISTENER_H
