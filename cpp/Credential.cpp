#include"credential.h"

bool Credential::operator==(const Credential& other)
{
    if (ID == other.ID && (strcmp(passward, other.passward) == 0))
    {
        return true;
    }
    else {
        return false;
    }
}
void Credential::setID(int ID)
{
    this->ID = ID;
}
void Credential::setPassward(const char* pass)
{
    strcpy_s(this->passward, pass);
}