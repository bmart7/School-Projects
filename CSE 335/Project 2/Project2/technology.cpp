#include "technology.h"

Technology::Technology():Item()
{
    type = "";
    company = "";
    weight = 0;
    fact = "";
}

void Technology::accept(Visitor *v)
{
    v->visit(this);
}

void Technology::setType(string nType)
{
    type = nType;
}

void Technology::setCompany(string nCompany)
{
    company = nCompany;
}

void Technology::setWeight(double nWeight)
{
    weight = nWeight;
}

void Technology::setFact(string nFact)
{
    fact = nFact;
}

string Technology::getType() const
{
    return type;
}

string Technology::getCompany() const
{
    return company;
}

double Technology::getWeight() const
{
    return weight;
}

string Technology::getFact() const
{
    return fact;
}
