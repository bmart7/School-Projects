#ifndef DIALOGLISTENER_H
#define DIALOGLISTENER_H

#include <QDialog>

namespace Ui {
class DialogListener;
}

class DialogListener : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListener(QWidget *parent = nullptr);
    ~DialogListener();
    Ui::DialogListener* getUI() const{return ui;}

private:
    Ui::DialogListener *ui;
};

#endif // DIALOGLISTENER_H
