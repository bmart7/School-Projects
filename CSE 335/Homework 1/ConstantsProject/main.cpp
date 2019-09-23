/*
 * Manipulates and tests Student Objects and their GPA members
 */

/* 
 * File:   main.cpp
 * Author: Brian Martin (A56350138)
 *
 * Created on January 11, 2019, 6:23 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Student.h"


//Function Parameters Passed as References
bool sameMajor(const Student& stu1, const Student& stu2){
    return stu1.getMajor().compare(stu2.getMajor()) == 0;
}
bool higherGPA(const Student& stu1, const Student& stu2){
    return stu1.getGPA() > stu2.getGPA();
}

int main(int argc, char** argv) {
    
    //Constant Objects
    const Student JimmyJohn("Jimmy", "John", "Cooking", 3.82);
    const Student Wendys("Wendy", "Redhead", "Cooking", 3.64);
    
    //Passing by Reference
    cout<<sameMajor(JimmyJohn,Wendys)<<endl;
    cout<<higherGPA(JimmyJohn,Wendys)<<endl;
    
    //Invoking Constant Member Functions on Constant Objects
    cout<<JimmyJohn.getFirstName()<<endl;
    cout<<JimmyJohn.getLastName()<<endl;
    cout<<JimmyJohn.getMajor()<<endl;
    cout<<JimmyJohn.getGPA()<<endl;
    
    Student Emily("Emily", "", "", 0.0);
    Emily.setLastName("Nononsense");
    Emily.setMajor("Crime Investigation");
    Emily.setGPA(3.9);
    
    cout<<sameMajor(JimmyJohn,Emily)<<endl;
    cout<<higherGPA(JimmyJohn,Emily)<<endl;
    cout<<Emily.getFirstName()<<endl;
    cout<<Emily.getLastName()<<endl;
    cout<<Emily.getMajor()<<endl;
    cout<<Emily.getGPA()<<endl;

    return 0;
}

