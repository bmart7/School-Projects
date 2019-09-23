#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

#include "item.h"
#include "visitor.h"

class Technology : public Item
{
public:
    Technology();
    Technology(string nType,string nName,string nCompany,double nWeight,double nPrice,string nFact)
        :Item(nName,nPrice),type(nType),company(nCompany),weight(nWeight),fact(nFact){}
    void setType(string nType);
    void setCompany(string nCompany);
    void setWeight(double nWeight);
    void setFact(string nFact);
    string getType() const;
    string getCompany() const;
    double getWeight() const;
    string getFact() const;
    virtual void accept(Visitor *v);
protected:
    string type;
    string company;
    double weight;
    string fact;
};

#endif // TECHNOLOGY_H
