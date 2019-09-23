#ifndef BUNDLEFILEREADER_H
#define BUNDLEFILEREADER_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "bundle.h"
#include "technology.h"
#include "bundlebuilder.h"

using namespace std;

class BundleFileReader
{
public:
    BundleFileReader(string filename):file(filename){}
    vector<Bundle*> getItems(const vector<Technology*>& techList);

protected:
    string file;
};

#endif // BUNDLEFILEREADER_H
