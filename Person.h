#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#define N 30
using namespace std;
//serves as a base class...
class Person
{
protected:
    int ID;
    char name[N];
    char address[N];
    int f_phone;  // first part of phone like 033
	int s_phone;        // second part is remaining number
    char dob[N];
    char pass[N];
    

public:
    Person();
    Person(int ID, const char* name, const char* address, int s_phone, int f_phone, const char* dob, const char* pass) :
        ID(ID), f_phone(f_phone), s_phone(s_phone) {
        strcpy_s(this->name, name);
        strcpy_s(this->address, address);
        strcpy_s(this->pass, pass);
        strcpy_s(this->dob, dob);
    }
    //We are using vectors to recreate objects from data files... So, using cooy constructors
    Person(const Person&);
    //Making this class a virctual class.
    virtual void DisplayDetails() const = NULL;
    //using getters to fetch data
    int getIdentity_doc() const;
    const char* getName() const;
    const char* getAddress() const;
    int getf_Phone() const;
	int gets_Phone() const;
    const char* getDateofbirth() const;
    const char* getPassward() const;
    void setPassward(const char*);
};
#endif
