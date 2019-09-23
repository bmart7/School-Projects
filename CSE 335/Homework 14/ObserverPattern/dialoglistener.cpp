#include "dialoglistener.h"
#include "ui_dialoglistener.h"

DialogListener::DialogListener(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListener)
{
    ui->setupUi(this);
    ui->label->setText("Value: ");
    ui->value->setNum(0);
    ui->resetButton->setText("Reset");
}

DialogListener::~DialogListener()
{
    delete ui;
}
