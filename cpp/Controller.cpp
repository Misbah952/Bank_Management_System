#define adminuser "N"
#define adminpass "N"
#include"Controller.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include <limits>
#include<iomanip>

using namespace std;
void Controller::Introduction() {
    system("CLS");
     cout << "\t\tBMS - Banking Management System" << endl;
     cout << "\t\tRun in FULLSCREEEN to visualize data"<<endl;
}
void Controller::MainMenu() // Main menu that shows after every successful function execution.
{
    system("CLS");
    int ch;
   
    cout << "1. Instructions" << endl;
	cout << "2. Admin Block" <<endl;
    cout << "3. Employee Block" << endl;
    cout << "4. Customer Block" << endl;
    cout << "5. Credits"<<endl;
	cout <<"6. Exit "<< endl;
    cout << "\tEnter choice (1-6) ";
    cin >> ch;
    switch (ch)
    {
    case 1:
		Instructions();
        break;
    case 2:
    {
        string id, pass;
        cout << "Enter your ID:\t";
        cin >> id;
        cout << "Enter your Password\t";
		cin.ignore();
        cin >> pass;
        if (id == adminuser && pass == adminpass)
            AdminBlock();
        else std::cout << "Invalid Password" << std::endl;
    }
    break;
	case 3:
		EmployeeBlock();
		break;
    case 4:
		CustomerBlock();
        break;
    case 5:
		Projectinfo();
        break;
    case 6:
        exit(0);
    default:
        cout << "Invalid Input. Try again..." << endl;
    }
}
void Controller::CustomerBlock() {
    Credential credTemp;
    Customer cust;                                                            //Dedicated for customers
    vector<Credential> credVector;
    fstream fin("customer.dat", ios::binary | ios::in);                      //File handling
    while (fin.read((char*)&cust, sizeof(Customer))) {                       //This loop runs till end of file and reads data equivalent to size of an object
        credTemp.setID(cust.getIdentity_doc());                              //Writing ID and their respective Password in Credentials Vector
        credTemp.setPassward(cust.getPassward());
        credVector.push_back(credTemp);
    }
    fin.close();
    int ID;
    char pass[N];
    cout << "Login ID (Number Only) : ";
    cin >> ID;
    cin.ignore();
    cout << "Password: ";
    cin.getline(pass,N);
	cin.ignore();
    Credential userCredential(ID, pass);
    bool SUCCESS = false;
    int SESSION = -1;
    for (vector<Credential>::iterator itr = credVector.begin(); itr != credVector.end(); ++itr)   //Using iterators to compare credentials
    {
        if (userCredential == *itr)
        {
            cout << "Authentication successful" << endl;
            SUCCESS = true;
            SESSION = userCredential.ID;
            CustomerAccess(SESSION);
        }
    }
    if (!SUCCESS)
    {
        cout << "Authentication unsuccessful" <<endl;
    }
}



void Controller::CustomerAccess(const int SESSION) {                               //Portal for customers when they get authenticated
    bool running = true;
    while (running)
    {
        vector<Customer> custVector;
        fstream fin("customer.dat", ios::binary | ios::in);                       //File handling
        Customer customer;
        while (fin.read((char*)&customer, sizeof(Customer))) {                   //Loading customer information via file handling
            custVector.push_back(customer);
        }
        cout << "1. View Balance" << endl;
        cout << "2. Change Password" << endl;
        cout << "3. Logout to Mainmenu" << endl;
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            for (vector<Customer>::iterator itr = custVector.begin();
                itr != custVector.end(); itr++)
            {
                if (itr->getIdentity_doc() == SESSION)
                {
                    itr->DisplayDetails();
                }
            }
        }
        break;
        case 2:
            Controller::changeCustomerPassword(SESSION);
            break;
        case 3:
            running = false;
            break;
        default:
            cout << "Invalid Option" << endl;
        }
    }
}
void Controller::EmployeeBlock()
{
    Credential credTemp;
    Employee emp;                                                            //Temp object to hold data and for copy constructor
    vector<Credential> credVector;                                           // Vector to create and hold object information
    fstream fin("employee.dat", ios::binary | ios::in);                      // File Handling
    while (fin.read((char*)&emp, sizeof(Employee))) {
        credTemp.setID(emp.getIdentity_doc());
        credTemp.setPassward(emp.getPassward());
        credVector.push_back(credTemp);
    }
    fin.close();
    int id;
    char pass[30];
    cout << "Login ID (Number Only) : ";
    cin >> id;
    cin.ignore();
    cout << "Password: ";
    cin.getline(pass,30);
	cin.ignore();
    Credential userCredential(id, pass);
    bool SUCCESS = false;
    int SESSION = -1;
    for (vector<Credential>::iterator itr = credVector.begin(); itr != credVector.end(); ++itr)
    {
        if (userCredential == *itr)
        {
            cout << "Authentication successful" << endl << endl;
            SUCCESS = true;
            SESSION = userCredential.ID;
            EmployeeAccess(SESSION);
        }
    }
    if (!SUCCESS)
    {
        cout << "Authentication unsuccessful" << endl;
    }
}
void Controller::EmployeeAccess(const int SESSION)           //Employee portal when they get access
{
    while (1)
    {
        cout << "1. Add Customer" << endl;
        cout << "2. Modify Customer" << endl;
        cout << "3. View Customers(DEFAULT CHRONOLOGICAL)" << endl;
        cout << "4. View Customers by" <<endl;
        cout << "5. Deposit Money to Customer account" <<endl;
        cout << "6. Withdraw Money from Customer account" << endl;
        cout << "7. Logout and return to mainmenu" << endl;
        int ch;
        cin >> ch;
        bool running = true;
        switch (ch)
        {
        case 1:
            Controller::addCustomer();
            break;
        case 2:
            Controller::editCustomerinfo();
            break;
        case 3:
            Controller::showCustomers();
            break;
        case 4:
            Controller::showCustomersBy();
            break;
      
        case 5:
            Controller::deposit();
            break;
        case 6:
            Controller::withdraw();
            break;
        case 7:
            running = false;
            break;
        default:
            cout << "Invalid Option" << endl;
        }
        if (!running)
            break;
    }
}
void Controller::AdminBlock()            
{ 
    bool running = true; //Master function which has all liberty to edit information
    while (1)
    {
        cout << "\tADMIN PORTAL" << endl;
        cout << "1. Add Employee\n2. Modify Employee\n3. Display Employees\n4. Delete Employees\n5. Add customer\n6. Modify Customer\n7. Display Customers\n8. Delete Customer\n9. Deposit to Customer A/C\n10. Withdraw from Customer A/C\n11. Logout to mainmenu\n";
        int ch;
        cout << "Choose any option: ";
        cin >> ch;
        switch (ch) {
        case 1:
            Controller::addEmployee();
            break;
        case 2:
            Controller::editEmployeeinfo();
            break;
        case 3:
            Controller::showEmployees();
            break;
        case 4:
            Controller::RemoveEmployee();
            break;
        case 5:
            Controller::addCustomer();
            break;
        case 6:
            Controller::editCustomerinfo();
            break;
        case 7:
            Controller::showCustomers();
            break;
        case 8:
            Controller::removeCustomer();
            break;
        case 9:
            Controller::deposit();
            break;
        case 10:
            Controller::withdraw();
            break;
        case 11:
            running = false;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
        if (!running)
            break;
    }

}
void Controller::Projectinfo()   //Project info
{
    system("CLS");
    cout << "\t\tBMS - Banking Management System" << endl;
    cout << "BEE-11C. CS-212 (OBJECT ORIENTED PROGRAMMING) (2nd Sem)"<<endl;
	cout<<"NUST Islamabad,Pakistan" << endl;
    char buff[10];
    cout << "Y to Continue" << endl;
    cin >> buff;
}


void Controller::addCustomer()
{
    vector<Customer> custVector;
    fstream fin("customer.dat", ios::binary | ios::in);
    Customer customer;
    while (fin.read((char*)&customer, sizeof(Customer))) {
        custVector.push_back(customer);
    }
    fin.close();
    int id;
    cout << "Enter Customer ID ";
    cin >> id;
    cin.ignore();
    bool flag = true;
    // a check to confirm that ID exists in data base
    for (vector<Customer>::iterator itr = custVector.begin(); itr != custVector.end(); ++itr)
    {
        if (itr->getIdentity_doc() == id)
        {
            flag = false;
            break;
        }
    }
    if (flag) // if record doesnt exists, then we can write data into file
    {

        char name[N], address[N], pass[N];
        int  f_phone;
		int s_phone;
        char dob[N];
        float bal;
        cout << "Enter Customer Name " << endl;
        cin.getline(name,N);
        cin.ignore();
        cout << "Enter address " << endl;
        cin.getline(address,N);
        cin.ignore();
        cout << "Enter first three digits of phone number " << endl;
        cin >> f_phone;
        cout<<"Enter remaining 8 digits of phone number"<<endl;
		cin>> s_phone;
        cin.ignore();
        cout << "Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] ";
        cin.getline(dob,N);
        cout << "Enter Password ";
        cin.getline(pass,N);
		cin.ignore();
        cout << "Enter Balance ";
        cin >> bal;
        cin.ignore();
		Customer cust(id, name, address, f_phone,s_phone, dob, pass, bal);
        fstream fout("customer.dat", ios::binary | ios::out | ios::app);
        fout.write((char*)&cust, sizeof(Customer));
        fout.close();
    }
    else {
        cout << "Operation unsuccessful. Record with similar ID already exists." << endl;
    }
}
void Controller::editCustomerinfo()
{
    vector<Customer> custVector;                         //Same Mechanism with file handling and object reading
    Customer cust;
    fstream fin("customer.dat", ios::binary | ios::in);
    while (fin.read((char*)&cust, sizeof(Customer)))
    {
        custVector.push_back(cust);
    }

    showCustomers();

    int id;
    cout << "Enter the ID of the customer to be modified ";
    cin >> id;
    // check to confirm data exists in database
    bool flag = false;
    int count = 0;
    for (vector<Customer>::iterator itr = custVector.begin();
        itr != custVector.end(); ++itr, ++count)
    {
        if (itr->getIdentity_doc() == id)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cin.ignore();
        char name[N], address[N], pass[N] ,dob[N];
        int s_phone,f_phone;
        float bal;
        cout << "Enter Customer Name: " << endl;
        
		cin.getline(name,N);
        cin.ignore();
		cout << "Enter address " << endl;
        cin.getline(address,N);
        cin.ignore();
		cout << "Enter first 3 digits of phone number " << endl;
        cin >> f_phone;
		cout<<"Enter remaining 8 digits of phone number"<<endl;
		cin>>s_phone;
        cin.ignore();
        cout << "Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] "; 
	    cin.getline(dob,N);
        cin.ignore();
	    cout << "Enter Password ";
        cin.getline(pass,N);
		cin.ignore();
        cout << "Enter Balance ";
        cin >> bal;
		Customer cust(id, name, address, f_phone,s_phone, dob, pass, bal);
        custVector.at(count) = cust;

        //File handling to write data into our file
        fstream fout("customer.dat", ios::binary | ios::out | ios::trunc);
        for (unsigned int i = 0; i < custVector.size(); i++)
        {
            fout.write((char*)&custVector.at(i), sizeof(Customer));
        }
        fout.close();
    }
    else {
        cout << "Customer account that is to be modified doesnot exist" << endl;
    }
}
void Controller::showCustomers()
{
    
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.dat", ios::binary | ios::in);          //Same Mechanism with file handling and object reading
    while (fin.read((char*)&cust, sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    cout << setw(20)<<"ID"<<setw(20)<<"NAME"<< setw(20)<<"ADDRESS"<<"\t\tPHONE"<<setw(20)<<"DOB"<<setw(20)<<"PASSWORD"<< setw(20)<<"BALANCE" << endl;
    for (vector<Customer>::iterator itr = custVector.begin();
        itr != custVector.end(); ++itr)
    {
        cout << setw(20) << itr->getIdentity_doc() << setw(20) << itr->getName() << setw(20) << itr->getAddress() << "\t\t"
            << itr->gets_Phone() << itr->getf_Phone() << setw(20) << (itr->getDateofbirth()) << setw(20) << itr->getPassward() <<
            setw(20) << itr->getAmount() << endl;
    }
    cout << endl;
}
void Controller::removeCustomer() {
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.dat", ios::binary | ios::in);       //Same Mechanism with file handling and object reading
    while (fin.read((char*)&cust, sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    int id;
    cout << "Enter the ID of the customer to be deleted ";
    cin >> id;
    for (unsigned int i = 0; i < custVector.size(); i++)
    {
        if (custVector[i].getIdentity_doc() == id)
        {
            custVector.erase(custVector.begin() + i);
        }
    }
    //Writing data into our file
    fstream fout("customer.dat", ios::binary | ios::out | ios::trunc);
    for (unsigned int i = 0; i < custVector.size(); ++i)
    {
        fout.write((char*)&custVector[i], sizeof(Customer));
    }
    fout.close();
}
void Controller::showCustomersBy() {
    vector<Customer> custVector;                                   //Same Mechanism with file handling and object reading
    Customer cust;
    fstream fin("customer.dat", ios::binary | ios::in);
    while (fin.read((char*)&cust, sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    int ch;
    cout << "1. Sort by ID " << endl;
    cout << "2. Sort by Name " << endl;
    cout << "3. Sort by Date of Birth " << endl;
    cout << "4. Sort by Balance " << endl;
    cin >> ch;
    //Functions for data sorting
    switch (ch)
    {
    case 1:
        std::sort(custVector.begin(), custVector.end(), Cust_sortingby_id);
        break;
    case 2:
        std::sort(custVector.begin(), custVector.end(), Cust_sortingby_name);
        break;
    case 3:
        std::sort(custVector.begin(), custVector.end(), Cust_sortingby_dateofbirth);
        break;
    case 4:
        std::sort(custVector.begin(), custVector.end(), Cust_sortingby_balance);
        break;
    }
    cout << "ID\tNAME\tADDRESS\tPHONE\t\tDOB\tPASSWORD\tBALANCE" << endl;
    for (vector<Customer>::iterator itr = custVector.begin();
        itr != custVector.end(); ++itr)
    {
		cout << itr->getIdentity_doc() << "\t" << itr->getName() << "\t" << itr->getAddress() << "\t"<< itr->getf_Phone() << "\t" << itr->gets_Phone()<<"\t"
 << (itr->getDateofbirth()) << "\t" << itr->getPassward() <<
            "\t" << itr->getAmount() << endl;
    }
    cout << endl;
}
void Controller::addEmployee()
{
    vector<Employee> empVector;                                       //Same Mechanism with file handling and object reading
    fstream fin("employee.dat", ios::binary | ios::in);
    Employee employee;
    while (fin.read((char*)&employee, sizeof(Employee))) {
        empVector.push_back(employee);
    }
    fin.close();
    int id;
    cout << "Enter Employee ID ";
    cin >> id;    bool flag = true;
    //Data validation through database
    for (vector<Employee>::iterator itr = empVector.begin(); itr != empVector.end(); ++itr)
    {
        if (itr->getIdentity_doc() == id)
        {
            flag = false;
            break;
        }
    }
    if (flag) 
    {
        cin.ignore();
        char name[N], address[N], pass[N];
        int f_phone,s_phone;
        char dob[N];
        float salary;
        cout << "Enter Employee Name: " << endl;
        cin.getline(name,N);
        cout << "Enter address :" << endl;
        cin.getline(address,N);
        cout << "Enter first 3 digits of phone number : " << endl;
        cin >> f_phone;
		cout<<"Enter remaining 8 digits of phone number : "<<endl;
        cin>>s_phone;
		cin.ignore();
        cout << "Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] " << endl;
        cin.getline(dob,N);
        cout << "Enter Password ";
		cin.getline(pass,N);
		cin.ignore();
        cout << "Enter Salary ";
        cin >> salary;
		Employee emp(id, name, address, f_phone,s_phone, dob, pass, salary);
        fstream fout("employee.dat", ios::binary | ios::out | ios::app);
        fout.write((char*)&emp, sizeof(Employee));
        fout.close();
    }
    else {
        cout << "Operation unsuccessful. Record with similar ID already exists." << endl;
    }
}
void Controller::editEmployeeinfo()
{
    vector<Employee> empVector;
    Employee emp;
    fstream fin("employee.dat", ios::binary | ios::in);
    while (fin.read((char*)&emp, sizeof(Employee)))
    {
        empVector.push_back(emp);
    }
    fin.close();

    showEmployees();

     int id;
    cout << "Enter the ID of the employee to be modified ";
    cin>>id;
    // Validating data through database
    bool flag = false;
    int count = 0;
    for (vector<Employee>::iterator itr = empVector.begin();
        itr != empVector.end(); ++itr, ++count)
    {
        if (itr->getIdentity_doc() == id)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        char name[N], address[N], pass[N];
         int f_phone,s_phone;
        char dob[N];
        float salary;
        cin.ignore();
        cout << "Enter Employee Name: " << endl;
	    cin.getline(name,N);
		cin.ignore();
        cout << "Enter address " << endl;
        cin.getline(address,N);
		cin.ignore();
        cout << "Enter first 3 digits of phone number " << endl;
        cin >> f_phone;
		cout<<"Enter remaining 8 digits of phone number"<<endl;
		cin>>s_phone;
        cin.ignore();
        cout << "Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] ";
	    cin.getline(dob,N);
        cin.ignore();
		cout << "Enter Password ";
		cin.getline(pass,N);
        cin.ignore();
		cout << "Enter Salary ";
        cin >> salary;
		Employee emp(id, name, address, f_phone,s_phone, dob, pass, salary);
        empVector.at(count) = emp;
        //storing data to database
        fstream fout("employee.dat", ios::binary | ios::out | ios::trunc);
        for (unsigned int i = 0; i < empVector.size(); i++)
        {
            fout.write((char*)&empVector.at(i), sizeof(Employee));
        }
        fout.close();
    }
    else {
        cout << "Customer account that is to be modified doesnot exist" << endl;
    }
}
void Controller::showEmployees()
{
    vector<Employee> empVector;
    Employee emp;
    fstream fin("employee.dat", ios::binary | ios::in);
    while (fin.read((char*)&emp, sizeof(Employee)))
    {
        empVector.push_back(emp);
    }
    fin.close();
    cout << setw(20) << "ID" << setw(20) << "NAME" <<  "\t\tADDRESS" << setw(20) << "PHONE" << setw(20) << "DOB" << setw(20) << "PASSWORD" << setw(20) << "SALARY" << endl;

    for (vector<Employee>::iterator itr = empVector.begin();
        itr != empVector.end(); ++itr)
    {
        cout << setw(20)<< itr->getIdentity_doc() << setw(20)<<  itr->getName() << setw(20)<<  itr->getAddress() << "\t\t"
			 <<itr->gets_Phone()  << itr->getf_Phone() << setw(20) << (itr->getDateofbirth()) << setw(20)<< itr->getPassward() <<
            setw(20) << itr->getincome() << endl;
    }
    cout << endl;
}
void Controller::RemoveEmployee()
{
    vector<Employee> empVector;
    Employee emp;
    fstream fin("employee.dat", ios::binary | ios::in);
    while (fin.read((char*)&emp, sizeof(Employee)))
    {
        empVector.push_back(emp);
    }
    fin.close();
    int id;
    cout << "Enter the ID of the employee to be deleted ";
    cin>>id;
	for (unsigned int i = 0; i < empVector.size(); i++)
    {
        if (empVector[i].getIdentity_doc() == id)
        {
            empVector.erase(empVector.begin() + i);
        }
    }
    // storing data to database
    fstream fout("employee.dat", ios::binary | ios::out | ios::trunc);
    for (unsigned int i = 0; i < empVector.size(); ++i)
    {
        fout.write((char*)&empVector[i], sizeof(Employee));
    }
    fout.close();
}
void Controller::deposit() {
    vector<Customer> custVector;
    Customer cust;                                                                        //Same Mechanism with file handling and object reading
    fstream fin("customer.dat", ios::binary | ios::in);
    while (fin.read((char*)&cust, sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    cout << "Deposit Window" << endl;
    int id;
    float money;
    cout << "Enter the ID that you want the money to be deposited ";
    cin>>id;
    cout << "Enter the amount to deposited ";
    cin >> money;
    bool SUCCESS = false;
    for (vector<Customer>::iterator itr = custVector.begin(); itr != custVector.end(); ++itr)
    {
        if (itr->getIdentity_doc() == id)
        {
            itr->deposit_amount(money);
            SUCCESS = true;
            break;
        }
    }
    //storing data to our database
    fstream fout("customer.dat", ios::binary | ios::out | ios::trunc);
    for (unsigned int i = 0; i < custVector.size(); i++)
    {
        fout.write((char*)&custVector.at(i), sizeof(Customer));
    }
    fout.close();
    if (SUCCESS)
        cout << "Successfully deposited Rs. " << money << endl;
    else
        cout << "Transaction could not be completed. Please contact the nearest Branch." << endl;
}
void Controller::withdraw()
{
    //Same Mechanism with file handling and object reading
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.dat", ios::binary | ios::in);
    while (fin.read((char*)&cust, sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    cout << "Withdraw Window" << endl;
    int id;
    float money;
    cout << "Enter the ID that you want the money to be withdrawn from ";
    cin>>id;
    cout << "Enter the amount to withdraw ";
    cin >> money;
    bool SUCCESS = false;
    for (vector<Customer>::iterator itr = custVector.begin(); itr != custVector.end(); ++itr)
    {
        if (itr->getIdentity_doc() == id)
        {
            itr->withdraw_amount(money);
            SUCCESS = true;
            break;
        }
    }
    //FLushing data to our database
    fstream fout("customer.dat", ios::binary | ios::out | ios::trunc);
    for (unsigned  int i = 0; i < custVector.size(); i++)
    {
        fout.write((char*)&custVector.at(i), sizeof(Customer));
    }
    fout.close();
    if (SUCCESS)
        cout << "Successfully withdrawn Rs. " << money << endl;
    else
        cout << "Transaction could not be completed. Please contact the nearest Branch." << endl;
}
void Controller::changeCustomerPassword(const int SESSION)
{
    //Same Mechanism with file handling and object reading
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.dat", ios::binary | ios::in);
    while (fin.read((char*)&cust, sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    cin.ignore();
    char prevpass[N], newpass[N];
    cout << "CHANGE PASSWORD" << endl;
    cout << "Enter the previous password ";
	cin.getline(prevpass,N);
    cin.ignore();
    cout << "Enter new password ";
	cin.getline(newpass,N);
    cin.ignore();

	bool SUCCESS = false;
    for (vector<Customer>::iterator itr = custVector.begin();
        itr != custVector.end(); ++itr)
    {
        if ((itr->getIdentity_doc() == SESSION)&& (strcmp(itr->getPassward(), prevpass) == 0))
        {
                itr->setPassward(newpass);
                SUCCESS = true;
                break;
        }
    }
    if (SUCCESS)
        cout << "Successfully changed your password. Kindly dont share your password with anyone else." << endl;
    else {
        cout << "Could not process your request. Please visit the nearest branch." << endl;
        cout << "Possibly, you have entered wrong previous password." << endl;
    }
    // storing data to our database
    fstream fout("customer.dat", ios::binary | ios::out | ios::trunc);
    for (unsigned int i = 0; i < custVector.size(); i++)
    {
        fout.write((char*)&custVector.at(i), sizeof(Customer));
    }
    fout.close();
}
void Controller:: Instructions()
{
	cout<<"Read the Instructions carefully to use the software"<<endl;
	cout<<"1. Please Use the Admin Block first to add customers and Employees in the bank"<<endl;
	cout<<"2. Admin id is N and the admin passward is also N"<<endl;
	cout<<"3. After adding Customers and Employees through admin block you can use the Customer and Employee Block"<<endl;
	cout<<"4. Customer and Employee block would facilitate you for different services as per their job"<<endl;
}


//Sorting data algorithms
bool Controller::Cust_sortingby_name(const Customer& c1, const Customer& c2)
{
    if ((c1.getName()== c2.getName()) )
        return true;
    else return false;
}
bool Controller::Cust_sortingby_dateofbirth(const Customer& c1, const Customer& c2)
{
    if (c1.getDateofbirth() < c2.getDateofbirth())
        return true;
    else return false;
}
bool Controller::Cust_sortingby_id(const Customer& c1, const Customer& c2)

{
    if (c1.getIdentity_doc() < c2.getIdentity_doc())
        return true;
    else return false;
}
bool Controller::Cust_sortingby_balance(const Customer& c1, const Customer& c2)
{
    if (c1.getAmount() < c2.getAmount())
        return true;
    else return false;
}
