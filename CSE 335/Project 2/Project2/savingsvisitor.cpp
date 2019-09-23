#include "savingsvisitor.h"

SavingsVisitor::SavingsVisitor()
{
    bundlePrice = 0;
    techSum = 0;
}

void SavingsVisitor::visit(Technology *tech)
{
    techSum += tech->getPrice();
}

void SavingsVisitor::visit(Bundle *bundle)
{
    bundlePrice = bundle->getPrice();
    for (Technology* tech : bundle->getItems()){
        tech->accept(this);
    }
}

double SavingsVisitor::getSavings()
{
    double result = (techSum - bundlePrice) / techSum;
    techSum = 0;
    bundlePrice = 0;
    return result;
}
