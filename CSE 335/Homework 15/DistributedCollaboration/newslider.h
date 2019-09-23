#ifndef NEWSLIDER_H
#define NEWSLIDER_H

#include <QSlider>
#include <QObject>

class NewSlider : public QSlider{
    Q_OBJECT

public:
    NewSlider(QWidget* parent = nullptr):QSlider(parent){};

public slots:
    void changeValueFromComboBox(int index);
};

#endif // NEWSLIDER_H
