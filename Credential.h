#include<iostream>
#include<cstring>
#define N 30
#ifndef __CREDENTIAL_H
#define __CREDENTIAL_H
//Making credential class for data validation. So we made a data container to hold ID and password and for their comparison.
class Credential {
private:
public:
    int ID;
    char passward[N];
    Credential() :ID(-1) {
        strcpy_s(this->passward, "\0");
    }
    Credential(int ID, const char* paswrd) :ID(ID) {
        strcpy_s(this->passward, paswrd);
    };
    void setID(int ID);
    void setPassward(const char* passward);
    bool operator==(const Credential&);  //Operator overloading for verification of data.
};
#endif