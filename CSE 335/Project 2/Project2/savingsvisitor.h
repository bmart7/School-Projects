#ifndef SAVINGSVISITOR_H
#define SAVINGSVISITOR_H

#include "visitor.h"
#include "technology.h"
#include "bundle.h"

class SavingsVisitor : public Visitor
{
public:
    SavingsVisitor();
    virtual void visit(Bundle* bundle);
    virtual void visit(Technology* tech);
    double getSavings();

protected:
    double bundlePrice;
    double techSum;
};

#endif // SAVINGSVISITOR_H
