#include<iostream>
#include"CustomerPortal.h"
#include"Credential.h"
#include"EmployeePortal.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H
//This class is the main controller of the code, i.e Main Menu...
//With this we can edit user's data and access the data base of the BANK
class Controller {
    static bool Cust_sortingby_name(const Customer&, const Customer&);
    static bool Cust_sortingby_dateofbirth(const Customer&, const Customer&);
    static bool Cust_sortingby_id(const Customer&, const Customer&);
    static bool Cust_sortingby_balance(const Customer&, const Customer&);
public:
    static void	Introduction();
    static void MainMenu();
    static void CustomerBlock();                   //option menu for customers
    static void CustomerAccess(const int SESSION);
    static void EmployeeBlock();                    //option menu for Employees
    static void EmployeeAccess(const int SESSION);
    static void AdminBlock();                       //option menu for Admin Access
    //All other functions are for editing data files and accessing them...
    static void Projectinfo();
    static void addCustomer();
    static void editCustomerinfo();
    static void showCustomers();
    static void removeCustomer();
    static void showCustomersBy();
    static void addEmployee();
    static void editEmployeeinfo();
    static void showEmployees();
    static void RemoveEmployee();
    static void deposit();
    static void withdraw();
    static void changeCustomerPassword(const int SESSION);
	static void Instructions(); //guide to use the code

};
#endif