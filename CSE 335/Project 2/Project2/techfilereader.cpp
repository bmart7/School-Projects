#include "techfilereader.h"

vector<Technology*> TechFileReader::getItems()
{
    ifstream infile(file);
    vector<Technology*> result = {};
    if (infile){
        string line;
        TechnologyBuilder tb = TechnologyBuilder();
        while (getline(infile,line)){
            stringstream ss(line);
            string word;
            vector<string> tokens;
            while(getline(ss,word,',')){
                tokens.push_back(word);
            }
            tb.buildType(tokens[0]);
            tb.buildName(tokens[1]);
            tb.buildCompany(tokens[2]);
            tb.buildWeight(stod(tokens[3]));
            tb.buildPrice(stod(tokens[4]));
            tb.buildFact(tokens[5]);
            result.push_back(tb.getResult());
        }
    }
    return result;
}
