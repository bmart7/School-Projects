/*
 * Represents a College Student with a First and Last Name, Major, and GPA
 */

/* 
 * File:   Student.h
 * Author: Brian Martin (A56350138)
 *
 * Created on January 11, 2019, 6:26 PM
 */

#ifndef STUDENT_H
#define STUDENT_H

class Student{
    
protected:
    string s_firstName;
    string s_lastName;
    string s_major;
    double s_gpa;
    
public:
    Student(const string& firstName, const string& lastName, const string& major, const double gpa){
        s_firstName = firstName;
        s_lastName = lastName;
        s_major = major;
        s_gpa = gpa;
    }
    
    //Constant Member Function
    string getFirstName() const{
        return s_firstName;
    }
    
    void setFirstName(const string& firstName){
        s_firstName = firstName;
    }
    
    string getLastName() const{
        return s_lastName;
    }
    
    void setLastName(const string& lastName){
        s_lastName = lastName;
    }
    
    string getMajor() const{
        return s_major;
    }
    
    void setMajor(const string& major){
        s_major = major;
    }
    
    double getGPA() const{
        return s_gpa;
    }
    
    void setGPA(const double gpa){
        s_gpa = gpa;
    }
    
};



#endif /* STUDENT_H */

