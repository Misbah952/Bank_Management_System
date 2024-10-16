#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include"Controller.h"
int main()
{
   
    while (1)
    {
		Controller::Introduction();
        cout << "Press any key to continue";
        getchar();
        Controller::MainMenu();
    }
    return EXIT_SUCCESS;
}