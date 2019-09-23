#ifndef ALEXLINEEDIT_H
#define ALEXLINEEDIT_H
#include <QLineEdit>

class AlexLineEdit: public QLineEdit{
    Q_OBJECT

public:
    AlexLineEdit(const QString& qstring):QLineEdit(qstring){};
    AlexLineEdit(QWidget* qw):QLineEdit(qw){};

public slots:
    //QFontCombo emit QFont signal, but QLineEdit slots only accept QString signal, so we have to make our own
    //slot to receive QFont signal, and then convert to QString.
    void showFont(QFont);
};

#endif // ALEXLINEEDIT_H
