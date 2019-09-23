#ifndef TECHNOLOGYBUILDER_H
#define TECHNOLOGYBUILDER_H

#include "technology.h"

class TechnologyBuilder
{
public:
    TechnologyBuilder();
    Technology* getResult();
    virtual ~TechnologyBuilder();
    void buildType(string type);
    void buildName(string name);
    void buildCompany(string company);
    void buildWeight(double weight);
    void buildPrice(double price);
    void buildFact(string fact);
protected:
    Technology* newTech;
};

#endif // TECHNOLOGYBUILDER_H
