#ifndef SUMVISITOR_H
#define SUMVISITOR_H

#include "visitor.h"
#include "technology.h"
#include "bundle.h"

class SumVisitor : public Visitor
{
public:
    SumVisitor();
    virtual void visit(Bundle* bundle);
    virtual void visit(Technology* tech);
    double getSum();
protected:
    double sum;
};

#endif // SUMVISITOR_H
