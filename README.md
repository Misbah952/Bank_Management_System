# BMS -  Bank_Management_System



## Introduction

This project is a **Banking Management System (BMS)** built in C++ exploiting the concepts of hierarchy and abstraction. It is designed to manage banking operations through various interfaces for administrators, employees, and customers. The system is intended to be run in **fullscreen mode** for optimal visualization of the data.  This is console-only project without any GUI support. It exploits the concepts of hierarchy and abstraction. 


The project uses a class-based design and provides a user-friendly command-line interface for different functionalities such as:

- **Admin Block**: Access and manage administrative functionalities.
- **Employee Block**: Functions for employees of the bank.
- **Customer Block**: Services available to bank customers.
- **Instructions**: Details on how to use the system.

## Features

- **Main Menu**: The main menu appears after each successful function execution. It contains options to navigate through the different blocks of the system:
  - Instructions
  - Admin Block
  - Employee Block
  - Customer Block
  - Credits
  - Exit

- **Clear Screen**: The interface clears the console screen between operations for better readability and user experience using `system("CLS")`.

## Requirements

- A C++ compiler (like g++)
- The following C++ standard libraries are used:
  - `<iostream>`
  - `<fstream>`
  - `<vector>`
  - `<cstdlib>`
  - `<algorithm>`
  - `<limits>`
  - `<iomanip>`

## How to Run

1. Clone this repository or download the code files.
2. Compile the program using a C++ compiler. For example, using g++:
   ```bash
   g++ -o main.cpp 

**Note**: The project was organized to include a seprate directory for cpp and header files. In order to run the project smoothly, create a temporary directory and copy all the cpp and header files in one directory and then follow How to Run section to execute  the main program.
