#ifndef BUNDLE_H
#define BUNDLE_H

#include "item.h"
#include "technology.h"
#include <vector>

class Bundle : public Item
{
public:
    Bundle();
    Bundle(string nName, double nPrice, vector<Technology*> nItems):Item(nName,nPrice),items(nItems){}
    void setItems(vector<Technology*> nItems);
    vector<Technology*> getItems();
    virtual void accept(Visitor *v);
protected:
    vector<Technology*> items;
};

#endif // BUNDLE_H
