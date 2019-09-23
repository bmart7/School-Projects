#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "dialoglistener.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CreateButton_clicked();

    void on_DeleteButton_clicked();

    void reset();

private:
    Ui::MainWindow *ui;
    std::vector<DialogListener*> listeners;
};

#endif // MAINWINDOW_H
