#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->sliderSize, SIGNAL(valueChanged(int)), ui->labelFox, SLOT(changeSizeFromSlider(int)));
    connect(ui->comboBoxFont, SIGNAL(currentIndexChanged(int)), ui->labelFox, SLOT(changeSizeFromComboBox(int)));
    connect(ui->comboBoxFont, SIGNAL(currentIndexChanged(int)), ui->lineEditFont, SLOT(setTextFromComboBox(int)));
    connect(ui->lineEditFont, SIGNAL(textChanged(QString)), ui->comboBoxFont, SLOT(setCurrentText(QString)));
    connect(ui->comboBoxFont, SIGNAL(currentIndexChanged(int)), ui->sliderSize, SLOT(changeValueFromComboBox(int)));
    connect(ui->radioButtonAriel, SIGNAL(clicked(bool)), ui->labelFox, SLOT(changeFontFromArielButton(bool)));
    connect(ui->radioButtonTNR, SIGNAL(clicked(bool)), ui->labelFox, SLOT(changeFontFromTNRButton(bool)));
    connect(ui->radioButtonComic, SIGNAL(clicked(bool)), ui->labelFox, SLOT(changeFontFromComicButton(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
