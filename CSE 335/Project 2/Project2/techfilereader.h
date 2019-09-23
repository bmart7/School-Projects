#ifndef TECHFILEREADER_H
#define TECHFILEREADER_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "technologybuilder.h"
#include "technology.h"

using namespace std;

class TechFileReader
{
public:
    TechFileReader(string filename):file(filename){}
    vector<Technology*> getItems();
protected:
    string file;
};

#endif // TECHFILEREADER_H
