#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newlabel.h"
#include "newlineedit.h"
#include "newslider.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
