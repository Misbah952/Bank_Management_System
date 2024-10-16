#include<iostream>
#include"person.h"
#ifndef __CUSTOMERPORTAL_H
#define __CUSTOMERPORTAL_H
class Customer :public Person {
private:
    float Amount;
protected:
public:
    Customer() :Person(), Amount(0) {} //Default Constructor
	Customer(int ID, const char* name, const char* address,  int f_phone,int s_phone, const char* dob, const char* pass, float Amount) : //Parameterized Constructor
		Person(ID, name, address, f_phone,s_phone, dob, pass), Amount(Amount) {};

    //COPY CONSTRUCTOR 
    Customer(const Customer& other) :Person(other) {
        this->Amount = other.Amount;
    }
    float getAmount() const;  //getter function
    void DisplayDetails() const;
    // functions to deposit and withdraw
    void deposit_amount(float);
    void withdraw_amount(float);
};
#endif