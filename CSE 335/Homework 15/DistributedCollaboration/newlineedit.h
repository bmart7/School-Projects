#ifndef NEWLINEEDIT_H
#define NEWLINEEDIT_H

#include <QLineEdit>
#include <QObject>


class NewLineEdit: public QLineEdit{
    Q_OBJECT

public:
    NewLineEdit(const QString& qstring):QLineEdit(qstring){};
    NewLineEdit(QWidget* qw):QLineEdit(qw){};

public slots:
    void setTextFromComboBox(int index);

};

#endif // NEWLINEEDIT_H
