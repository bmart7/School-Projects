/*
 * Homework #2 - Information Hiding with Inheritance
 */

/* 
 * File:   main.cpp
 * Author: Brian Martin (A56350138)
 *
 * Created on January 14, 2019, 2:27 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class Employee{
    
public:
    string publicEmployeeName;
protected:
    string protectedEmployeeAddress;
private:
    string privateEmployeeSSN;
    
public:
    Employee(string a, string b, string c):publicEmployeeName(a),protectedEmployeeAddress(b),privateEmployeeSSN(c){
    };
    
    void print(){
        cout<<publicEmployeeName<<endl;
        cout<<protectedEmployeeAddress<<endl;
        cout<<privateEmployeeSSN<<endl;
    }
    
    void publicEmployeeDoWork(){
        cout<<"Public Working"<<endl;
    }
    
protected:
    void protectedEmployeeDoWork(){
        cout<<"Protected Working"<<endl;
    }
    
private:
    void privateEmployeeDoWork(){
        cout<<"Private Working"<<endl;
    }
};

class PublicManagement: public Employee{
public:
    PublicManagement(string a, string b, string c):Employee(a,b,c){
    };
    
    void print(){
        cout<<publicEmployeeName<<endl;
        cout<<protectedEmployeeAddress<<endl;
        //cout<<privateEmployeeSSN<<endl;
        //error: 'privateEmployeeSSN' is a private member of 'Employee'
    }
    
    void doWork(){
        publicEmployeeDoWork();
        protectedEmployeeDoWork();
        //privateEmployeeDoWork();
        //error: 'privateEmployeeDoWork' is a private member of 'Employee'
    }
};

class ProtectedManagement: protected Employee{
public:
    ProtectedManagement(string a, string b, string c):Employee(a,b,c){
    };
    
    void print(){
        cout<<publicEmployeeName<<endl;
        cout<<protectedEmployeeAddress<<endl;
        //cout<<privateEmployeeSSN<<endl;
        //error: 'privateEmployeeSSN' is a private member of 'Employee'
    }
    
    void doWork(){
        publicEmployeeDoWork();
        protectedEmployeeDoWork();
        //privateEmployeeDoWork();
        //error: 'privateEmployeeDoWork' is a private member of 'Employee'
    }
};

class PrivateManagement: private Employee{
public:
    PrivateManagement(string a, string b, string c):Employee(a,b,c){
    };
    
    void print(){
        cout<<publicEmployeeName<<endl;
        cout<<protectedEmployeeAddress<<endl;
        //cout<<privateEmployeeSSN<<endl;
        //error: 'privateEmployeeSSN' is a private member of 'Employee'
    }
    
    void doWork(){
        publicEmployeeDoWork();
        protectedEmployeeDoWork();
        //privateEmployeeDoWork();
        //error: 'privateEmployeeDoWork' is a private member of 'Employee'
    }
};

class PublicGeneralManager: public PublicManagement{
public:
    PublicGeneralManager(string a, string b, string c):PublicManagement(a,b,c){
    };
    
    void print(){
        cout<<publicEmployeeName<<endl;
        cout<<protectedEmployeeAddress<<endl;
        //cout<<privateEmployeeSSN<<endl;
        //error: 'privateEmployeeSSN' is a private member of 'Employee'
    }
    
    void doWork(){
        publicEmployeeDoWork();
        protectedEmployeeDoWork();
        //privateEmployeeDoWork();
        //error: 'privateEmployeeDoWork' is a private member of 'Employee'
    }
};

class ProtectedGeneralManager: protected ProtectedManagement{
public:
    ProtectedGeneralManager(string a, string b, string c):ProtectedManagement(a,b,c){
    };
    
    void print(){
        cout<<publicEmployeeName<<endl;
        cout<<protectedEmployeeAddress<<endl;
        //cout<<privateEmployeeSSN<<endl;
        //error: 'privateEmployeeSSN' is a private member of 'Employee'
    }
    
    void doWork(){
        publicEmployeeDoWork();
        protectedEmployeeDoWork();
        //privateEmployeeDoWork();
        //error: 'privateEmployeeDoWork' is a private member of 'Employee'
    }
};

class PrivateGeneralManager: private PrivateManagement{
public:
    PrivateGeneralManager(string a, string b, string c):PrivateManagement(a,b,c){
    };
    
    void print(){
        //error: cannot cast 'PrivateGeneralManager' to its private base class 'Employee'
        
        //cout<<publicEmployeeName<<endl;
        //error: 'publicEmployeeName' is a private member of 'Employee'
        
        //cout<<protectedEmployeeAddress<<endl;
        //error: 'protectedEmployeeAddress' is a private member of 'Employee'
        
        //cout<<privateEmployeeSSN<<endl;
        //error: 'privateEmployeeSSN' is a private member of 'Employee'
    }
    
    void doWork(){
        //publicEmployeeDoWork();
        //error: 'publicEmployeeDoWork' is a private member of 'Employee'
        
        //protectedEmployeeDoWork();
        //error: 'protectedEmployeeDoWork' is a private member of 'Employee'
        
        //privateEmployeeDoWork();
        //error: 'privateEmployeeDoWork' is a private member of 'Employee'
    }
};
/*
 * 
 */
int main(int argc, char** argv) {

    cout<<"\nEmployee (Base Class):"<<endl;
    Employee employee("Adam", "1st St", "123456789");
    cout<<employee.publicEmployeeName<<endl;
    //cout<<employee.protectedEmployeeAddress<<endl;
    //error: 'protectedEmployeeAddress' is a protected member of 'Employee'
    //cout<<employee.privateEmployeeSSN<<endl;
    //error: 'privateEmployeeSSN' is a private member of 'Employee'
    
    employee.publicEmployeeDoWork();
    //employee.protectedEmployeeDoWork();
    //error: 'protectedEmployeeDoWork' is a protected member of 'Employee'
    
    cout<<"\n\nPublicManagement (1st Public Inheritance):"<<endl;
    PublicManagement publicManagement("Brad", "2nd St", "234567891");
    cout<<publicManagement.publicEmployeeName<<endl;
    //cout<<publicManagement.protectedEmployeeAddress<<endl;
    //error: 'protectedEmployeeAddress' is a protected member of 'Employee'
    //cout<<publicManagement.privateEmployeeSSN<<endl;
    //error: 'privateEmployeeSSN' is a private member of 'Employee'
    
    publicManagement.publicEmployeeDoWork();
    //publicManagement.protectedEmployeeDoWork();
    //error: 'protectedEmployeeDoWork' is a protected member of 'Employee'
    
    cout<<"\n\nProtectedManagement (1st Protected Inheritance):"<<endl;
    ProtectedManagement protectedManagement("Chad", "3rd St", "345678912");
    //error: cannot cast 'ProtectedManagement' to its protected base class 'Employee'
    //cout<<protectedManagement.publicEmployeeName<<endl;
    //error: 'publicEmployeeName' is a protected member of 'Employee'
    //cout<<protectedManagement.protectedEmployeeAddress<<endl;
    //error: 'protectedEmployeeAddress' is a protected member of 'Employee'
    //cout<<protectedManagement.privateEmployeeSSN<<endl;
    //error: 'privateEmployeeSSN' is a private member of 'Employee'
    
    //protectedManagement.publicEmployeeDoWork();
    //error: 'publicEmployeeDoWork' is a protected member of 'Employee'
    //protectedManagement.protectedEmployeeDoWork();
    //error: 'protectedEmployeeDoWork' is a protected member of 'Employee'
    
    cout<<"\n\nPrivateManagement (1st Private Inheritance):"<<endl;
    PrivateManagement privateManagement("Drew", "4th St", "456789123");
    //error: cannot cast 'PrivateManagement' to its private base class 'Employee'
    //cout<<privateManagement.publicEmployeeName<<endl;
    //error: 'publicEmployeeName' is a private member of 'Employee'
    //cout<<privateManagement.protectedEmployeeAddress<<endl;
    //error: 'protectedEmployeeAddress' is a private member of 'Employee'
    //cout<<privateManagement.privateEmployeeSSN<<endl;
    //error: 'privateEmployeeSSN' is a private member of 'Employee'
    
    //privateManagement.publicEmployeeDoWork();
    //error: 'publicEmployeeDoWork' is a private member of 'Employee'
    //privateManagement.protectedEmployeeDoWork();
    //error: 'protectedEmployeeDoWork' is a private member of 'Employee'
    
    cout<<"\n\nPublicGeneralManager (2nd Public Inheritance):"<<endl;
    PublicGeneralManager publicGeneralManager("Evan", "5th St", "567891234");
    cout<<publicGeneralManager.publicEmployeeName<<endl;
    //cout<<publicGeneralManager.protectedEmployeeAddress<<endl;
    //error: 'protectedEmployeeAddress' is a protected member of 'Employee'
    //cout<<publicGeneralManager.privateEmployeeSSN<<endl;
    //error: 'privateEmployeeSSN' is a private member of 'Employee'
    
    publicGeneralManager.publicEmployeeDoWork();
    //publicGeneralManager.protectedEmployeeDoWork();
    //error: 'protectedEmployeeDoWork' is a protected member of 'Employee'
    
    cout<<"\n\nProtectedGeneralManager (2nd Protected Inheritance):"<<endl;
    ProtectedGeneralManager protectedGeneralManager("Frank", "6th St", "678912345");
    //error: cannot cast 'ProtectedGeneralManager' to its protected base class 'Employee'
    //cout<<protectedGeneralManager.publicEmployeeName<<endl;
    //error: 'publicEmployeeName' is a protected member of 'Employee'
    //cout<<protectedGeneralManager.protectedEmployeeAddress<<endl;
    //error: 'protectedEmployeeAddress' is a protected member of 'Employee'
    //cout<<protectedGeneralManager.privateEmployeeSSN<<endl;
    //error: 'privateEmployeeSSN' is a private member of 'Employee'
    
    //protectedGeneralManager.publicEmployeeDoWork();
    //error: 'publicEmployeeDoWork' is a protected member of 'Employee'
    //protectedGeneralManager.protectedEmployeeDoWork();
    //error: 'protectedEmployeeDoWork' is a protected member of 'Employee'
    
    cout<<"\n\nPrivateGeneralManager (2nd Private Inheritance):"<<endl;
    PrivateGeneralManager privateGeneralManager("Gary", "7th St", "789123456");
    //error: cannot cast 'PrivateGeneralManager' to its private base class 'Employee'
    //cout<<privateGeneralManager.publicEmployeeName<<endl;
    //error: 'publicEmployeeName' is a private member of 'Employee'
    //cout<<privateGeneralManager.protectedEmployeeAddress<<endl;
    //error: 'protectedEmployeeAddress' is a private member of 'Employee'
    //cout<<privateGeneralManager.privateEmployeeSSN<<endl;
    //error: 'privateEmployeeSSN' is a private member of 'Employee'
    
    //privateGeneralManager.publicEmployeeDoWork();
    //error: 'publicEmployeeDoWork' is a private member of 'Employee'
    //privateGeneralManager.protectedEmployeeDoWork();
    //error: 'protectedEmployeeDoWork' is a private member of 'Employee'
    
    return 0;
}

