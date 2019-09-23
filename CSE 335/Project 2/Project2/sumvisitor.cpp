#include "sumvisitor.h"

SumVisitor::SumVisitor()
{
    sum = 0;
}

void SumVisitor::visit(Technology *tech)
{
    sum += tech->getPrice();
}

void SumVisitor::visit(Bundle *bundle)
{
    sum += bundle->getPrice();
}

double SumVisitor::getSum(){
    double temp = sum;
    sum = 0;
    return temp;
}
