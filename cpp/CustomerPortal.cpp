#include"CustomerPortal.h"
using namespace std;
void Customer::DisplayDetails() const {
    cout << endl<<"Your Customer ID is : ";
    cout << ID << endl;
    cout << "Your name is : " << name << endl;
    cout << "Your adress is : " << address << endl;
	cout << "Your phone number is 0: " << s_phone<<"-"<<f_phone << endl;
    cout << "Your birthdate is : " << dob << endl;
	cout << "The Amount in your account is : "<< Amount << endl;
}
float Customer::getAmount() const {
	return this->Amount;
}
void Customer::deposit_amount(float money)
{
	this->Amount += money;
}
void Customer::withdraw_amount(float money)
{
	this->Amount -= money;
}