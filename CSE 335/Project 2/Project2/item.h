#ifndef ITEM_H
#define ITEM_H

using namespace std;
#include <string>
#include "visitor.h"

class Item
{
public:
    Item();
    Item(string nName,double nPrice):name(nName),price(nPrice){}
    void setName(string newName);
    void setPrice(double newPrice);
    string getName() const;
    double getPrice() const;
    virtual void accept(Visitor *v) = 0;
protected:
    string name;
    double price;
};

#endif // ITEM_H
