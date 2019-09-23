#include "newlineedit.h"

void NewLineEdit::setTextFromComboBox(int index){
    if (index == 0){
        this->setText("small");
    }else if (index == 1){
        this->setText("medium");
    }else if (index == 2){
        this->setText("big");
    }
}
