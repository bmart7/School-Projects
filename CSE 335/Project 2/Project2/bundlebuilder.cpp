#include "bundlebuilder.h"
#include <iostream>

BundleBuilder::BundleBuilder()
{
    newBundle = new Bundle();
}

BundleBuilder::~BundleBuilder()
{
    if (newBundle != nullptr){
        delete newBundle;
    }
}

void BundleBuilder::buildName(string nName)
{
    newBundle->setName(nName);
}

void BundleBuilder::buildPrice(double nPrice)
{
    newBundle->setPrice(nPrice);
}

void BundleBuilder::buildItems(vector<Technology *> nItems)
{
    newBundle->setItems(nItems);
}

Bundle* BundleBuilder::getResult()
{
    Bundle* temp = newBundle;
    newBundle = new Bundle();
    return temp;
}
