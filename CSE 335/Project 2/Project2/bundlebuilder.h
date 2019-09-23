#ifndef BUNDLEBUILDER_H
#define BUNDLEBUILDER_H

#include "technology.h"
#include "bundle.h"
#include <vector>

class BundleBuilder
{
public:
    BundleBuilder();
    Bundle* getResult();
    virtual ~BundleBuilder();
    void buildName(string nName);
    void buildPrice(double nPrice);
    void buildItems(vector<Technology*> nItems);

//protected:
    Bundle* newBundle;
};

#endif // BUNDLEBUILDER_H
