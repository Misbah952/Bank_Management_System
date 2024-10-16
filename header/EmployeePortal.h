#ifndef __EMPLOYEEPORTAL_H
#define __EMPLOYEEPORTAL_H
#include<iostream>
#include"person.h"
class Employee :public Person {
private:
    float income;

public:
	Employee() :Person(), income(0) {}  //Default Constructor
	Employee(int ID, const char* name, const char* address,  int s_phone,int f_phone, char* dob, const char* pass, float income) : //Parameterized Constructor
		Person(ID, name, address, s_phone,f_phone, dob, pass), income(income) {}
    //Copy constructor
	Employee(const Employee& other) :Person(other), income(other.income) {}
	//Getters to fetch data
    float getincome() const;
    void DisplayDetails() const;
};
#endif