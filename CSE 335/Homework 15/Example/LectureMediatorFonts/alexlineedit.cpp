#include "alexlineedit.h"

void AlexLineEdit::showFont(QFont font){
    this->setText(font.family());
}
