#include "newlabel.h"
#include <QFont>

void NewLabel::changeSizeFromSlider(int size){
    QFont font = this->font();
    font.setPointSize(size);
    this->setFont(font);
}

void NewLabel::changeSizeFromComboBox(int index){
    QFont font = this->font();
    if (index == 0){
        font.setPointSize(10);
    }else if (index == 1){
        font.setPointSize(20);
    }else if (index == 2){
        font.setPointSize(40);
    }
    this->setFont(font);
}

void NewLabel::changeFontFromArielButton(bool toggled){
    if (toggled){
        QFont font = this->font();
        font.setFamily("Ariel");
        this->setFont(font);
    }
}

void NewLabel::changeFontFromTNRButton(bool toggled){
    if (toggled){
        QFont font = this->font();
        font.setFamily("Times New Roman");
        this->setFont(font);
    }
}

void NewLabel::changeFontFromComicButton(bool toggled){
    if (toggled){
        QFont font = this->font();
        font.setFamily("Comic Sans MS");
        this->setFont(font);
    }
}
