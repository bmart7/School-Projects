#ifndef NEWLABEL_H
#define NEWLABEL_H

#include <QLabel>
#include <QObject>

class NewLabel : public QLabel{
    Q_OBJECT

public:
    NewLabel(QWidget* qw):QLabel(qw){};

public slots:
    void changeSizeFromSlider(int size);
    void changeSizeFromComboBox(int index);
    void changeFontFromArielButton(bool toggled);
    void changeFontFromTNRButton(bool toggled);
    void changeFontFromComicButton(bool toggled);
};

#endif // NEWLABEL_H
