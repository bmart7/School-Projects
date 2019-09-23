#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alexlabel.h"
#include <QtGui>
#include <QMessageBox>
//#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEditFamily,SIGNAL(textChanged(QString)),ui->labelFox,SLOT(setFontByText(QString)));

    connect(ui->lineEditFamily,SIGNAL(textChanged(QString)),ui->fontComboBox,SLOT(setCurrentText(QString)));

    connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)),ui->labelFox,SLOT(setFont(QFont)));
    //Below works also.
    //connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)),this,SLOT(getFont(QFont)));

    connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)),ui->lineEditFamily,SLOT(showFont(QFont)));

    connect(ui->checkBoxBold,SIGNAL(clicked(bool)),ui->labelFox,SLOT(modifyFontByCheckboxBold(bool)));
    connect(ui->checkBoxItalic,SIGNAL(clicked(bool)),ui->labelFox,SLOT(modifyFontByCheckboxItalic(bool)));
    connect(ui->checkBoxUnderline,SIGNAL(clicked(bool)),ui->labelFox,SLOT(modifyFontByCheckboxUnderline(bool)));

    connect(ui->lineEditSize,SIGNAL(textChanged(QString)),ui->labelFox,SLOT(modifyFontByCheckboxSize(QString)));
}

void MainWindow::getFont(QFont qf){
    ui->labelFox->setFont(qf);
    //QMessageBox::about(this, "test", qf.toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}
