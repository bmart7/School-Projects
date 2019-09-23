#include "bundlefilereader.h"

vector<Bundle*> BundleFileReader::getItems(const vector<Technology *> &techList)
{
    ifstream infile(file);
    vector<Bundle*> result = {};
    if (infile){
        string line;
        BundleBuilder bb = BundleBuilder();
        while (getline(infile,line)){
            stringstream ss(line);
            string word;
            vector<string> tokens;
            while(getline(ss,word,',')){
                tokens.push_back(word);
            }
            bb.buildName(tokens[0]);
            bb.buildPrice(stod(tokens[1]));
            vector<Technology*> techVec = {};
            for (int i=2; i<tokens.size();i++){
                for (Technology* tech : techList){
                    if (tech->getName().compare(tokens[i]) == 0){
                        techVec.push_back(tech);
                        break;
                    }
                }
            }
            bb.buildItems(techVec);
            result.push_back(bb.getResult());
        }
    }
    return result;
}
