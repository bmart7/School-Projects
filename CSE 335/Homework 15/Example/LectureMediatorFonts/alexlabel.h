#ifndef ALEXLABEL_H
#define ALEXLABEL_H
#include <QObject>
#include <QLabel>
#include <QFont>
#include <QMessageBox>

/*Lessons:
 * 1. For any class with signals or slots, it must have the Q_OBJECT macro.
 * 2. Must separate .h and .cpp file. Otherwise you will get "undefined reference to vtable" error.
 *
 */

class AlexLabel: public QLabel{
    Q_OBJECT

public:
    AlexLabel(QWidget* qw):QLabel(qw){};
    //virtual ~AlexLabel(){};

public slots:
    //For receiving signal from QFontComboBox: void currentFontChanged(const QFont& font)
    void setFont(QFont);
    //For receiving signal QLineEdit for font family: void textChanged(const QString& text)
    void setFontByText(QString);
    //For receiving signal from CheckBox for Bold check box: void clicked(bool)
    void modifyFontByCheckboxBold(bool);
    //For receiving signal from CheckBox for Italic check box: void clicked(bool)
    void modifyFontByCheckboxItalic(bool);
    //For receiving signal from CheckBox for Underline check box: void clicked(bool)
    void modifyFontByCheckboxUnderline(bool);
    //For receiving signal QLineEdit for font size: void textChanged(const QString& text)
    void modifyFontByCheckboxSize(QString);
};

#endif // ALEXLABEL_H
