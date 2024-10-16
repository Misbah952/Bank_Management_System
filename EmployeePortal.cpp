#include<iostream>
#include"EmployeePortal.h"
using namespace std;
void Employee::DisplayDetails() const {
	cout << endl << "Your Employee ID is : ";
	cout << ID << endl;
	cout << "Your name is : " << name << endl;
	cout << "Your adress is : " << address << endl;
	cout << "Your phone number is : 0" << s_phone << "-" << f_phone << endl;
	cout << "Your birthdate is : " << dob << endl;
	cout << "Your salary is : " << income << endl;
}
float Employee::getincome() const
{
	return this->income;
}