#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoglistener.h"
#include "ui_dialoglistener.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setValue(0);
    ui->CreateButton->setText("Create New Window");
    ui->DeleteButton->setText("Delete Last Window");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CreateButton_clicked()
{
    DialogListener* temp = new DialogListener(this);
    listeners.push_back(temp);
    temp->show();
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), temp->getUI()->value, SLOT(setNum(int)));
    connect(temp->getUI()->resetButton, SIGNAL(clicked()), this, SLOT(reset()));
}

void MainWindow::on_DeleteButton_clicked()
{
    if (listeners.size() > 0){
        DialogListener* last = listeners.back();
        last->close();
        listeners.pop_back();
    }
}

void MainWindow::reset()
{
    ui->horizontalSlider->setValue(0);
}
