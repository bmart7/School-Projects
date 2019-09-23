#include "technologybuilder.h"
#include <iostream>

TechnologyBuilder::TechnologyBuilder()
{
    newTech = new Technology();
}

TechnologyBuilder::~TechnologyBuilder(){
    if (newTech != nullptr){
        delete newTech;
    }
}

void TechnologyBuilder::buildType(string type)
{
    newTech->setType(type);
}

void TechnologyBuilder::buildName(string name)
{
    newTech->setName(name);
}

void TechnologyBuilder::buildCompany(string company)
{
    newTech->setCompany(company);
}

void TechnologyBuilder::buildWeight(double weight)
{
    newTech->setWeight(weight);
}

void TechnologyBuilder::buildPrice(double price)
{
    newTech->setPrice(price);
}

void TechnologyBuilder::buildFact(string fact)
{
    newTech->setFact(fact);
}

Technology* TechnologyBuilder::getResult()
{
    Technology* temp = newTech;
    newTech = new Technology();
    return temp;

}
