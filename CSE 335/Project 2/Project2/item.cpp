#include "item.h"

Item::Item()
{
    name = "";
    price = 0.0;
}

void Item::setName(string newName)
{
    name = newName;
}

void Item::setPrice(double newPrice)
{
    price = newPrice;
}

string Item::getName() const
{
    return name;
}

double Item::getPrice() const
{
    return price;
}
