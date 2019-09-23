#include "mainwindow.h"
#include <QApplication>
#include "technology.h"
#include "technologybuilder.h"
#include "bundlebuilder.h"
#include "techfilereader.h"
#include "sumvisitor.h"
#include "savingsvisitor.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    TechFileReader tfr = TechFileReader("/Users/bmart/Documents/Class/SS19/CSE 335/Projects/Project 2/Project 2 Instructions/Technology.csv");
    vector<Technology*> techList = tfr.getItems();

    vector<Technology*> list = {techList[0],techList[3]};
    SumVisitor sv = SumVisitor();
    for (Technology* tech : list){
        tech->accept(&sv);
    }
    cout<<sv.getSum()<<endl;

    SavingsVisitor sv1 = SavingsVisitor();
    Bundle b = Bundle("quick", 310.14, list);
    b.accept(&sv1);
    cout<<sv1.getSavings()<<endl;

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
