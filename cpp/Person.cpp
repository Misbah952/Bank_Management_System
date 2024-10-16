#include "Person.h"
Person::Person(const Person& other) {                         //COPY CONSTRUCTOR
    this->ID = other.ID;
    strcpy_s(this->name, other.name);
    strcpy_s(this->address, other.address);
    this->s_phone = other.s_phone;
    this->f_phone = other.f_phone;
    strcpy_s(this->dob, other.dob);
    strcpy_s(this->pass, other.pass);
}
Person::Person()                                           //DEFAULT CONSTRUCTOR
{
    ID = 0;
    strcpy_s(this->name, "\0");
    strcpy_s(this->address, "\0");
	f_phone = 000;
    s_phone = 00000000;
    strcpy_s(this->dob, "\0");
    strcpy_s(this->pass, "\0");
}
////GETTERS
int Person::getIdentity_doc() const {
    return this->ID;
}
const char* Person::getName() const {
    return this->name;
}
const char* Person::getAddress() const {
    return this->address;
}
int Person::getf_Phone() const {
    return this->f_phone;
}
int Person::gets_Phone() const {
    return this->s_phone;
}
const char*Person::getDateofbirth() const {
    return this->dob;
}
const char* Person::getPassward() const {
    return this->pass;
}
void Person::setPassward(const char* newpass)
{
    strcpy_s(this->pass, newpass);
}