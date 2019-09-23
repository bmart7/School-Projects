#include "newslider.h"

void NewSlider::changeValueFromComboBox(int index){
    if (index == 0){
        this->setValue(10);
    }else if (index == 1){
        this->setValue(20);
    }else if (index == 2){
        this->setValue(40);
    }
}
