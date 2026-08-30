# Pharmacy Control System

A console-based Pharmacy Control System developed in C to manage pharmacy staff accounts, medicine inventory, and staff information.

## 📌 Project Overview

The Pharmacy Control System is designed for pharmacy staff to manage medicine stock and staff records through a simple menu-driven interface.

The system includes user authentication, medicine inventory management, stock shortage checking, and staff management. Data is stored using text files so that records can be accessed across program sessions.

## ✨ Features

### 🔐 User Authentication
- Login using username and password
- Create a new staff account
- Name validation
- Phone number validation
- Username validation
- Password validation
- Stores user credentials in a text file

### 💊 Medicine Stock Management
- Add new medicines
- Edit medicine information
- Delete medicines
- View complete medicine stock
- Check medicines with low stock
- Store medicine ID, name, quantity, cost price, and selling price

### 👨‍⚕️ Staff Management
- Recruit new staff
- Remove/fire staff
- View all staff information
- Store staff ID, name, age, post, and experience

### 💾 File Handling
The system uses text files to store information:

- `users.txt` — user login information
- `stock.txt` — medicine stock records
- `staff.txt` — staff information

Temporary file handling is also used when editing or deleting records.

## 🛠️ Technologies Used

- C Programming Language
- Structures
- Functions
- File Handling
- String Manipulation
- Conditional Statements
- Loops
- Menu-driven Programming

## 🧠 C Concepts Used

### Structures

The project uses structures to organize medicine and staff information.

```c
struct Medicine {
    int id;
    char name[30];
    int quantity;
    int price1;
    int price2;
};

struct Staff {
    int id;
    char name[30];
    int age;
    char post[30];
    int experience;
};
File Handling

The project uses file operations such as:

fopen()
fclose()
fprintf()
fscanf()
remove()
rename()
Functions

Separate functions are used for input validation, including:

namecheck()
numbercheck()
usercheck()
checkpassword()
📋 Main Functionalities
Medicine Management

The medicine module provides options to:

Add Medicine
Edit Medicine
Delete Medicine
View Stock
Check Stock Shortage

Medicines with a quantity below 20 are displayed in the stock shortage section.

Staff Management

The staff module provides options to:

Recruit Staff
Fire Staff
View All Staff
▶️ How to Run
Using GCC

Compile the program:

gcc pharmacy_management_system.c -o pharmacy_management_system

Run the program:

./pharmacy_management_system
Windows

If using a Windows-based C IDE such as Code::Blocks, open the source file and build/run the project from the IDE.

📁 Project Structure
Pharmacy-Control-System/
│
├── pharmacy_management_system.c
├── users.txt
├── stock.txt
├── staff.txt
└── README.md

The text files are used to store the application's data.

🔄 System Flow
Start
  │
  ▼
Login / Create Account
  │
  ▼
Authentication
  │
  ▼
Main Menu
  │
  ├── Medicine Stock
  │      ├── Add Medicine
  │      ├── Edit Medicine
  │      ├── Delete Medicine
  │      ├── View Stock
  │      └── Stock Shortage
  │
  └── Staff Management
         ├── Recruit Staff
         ├── Fire Staff
         └── View Staff
🎯 Learning Outcomes

Through this project, I practiced:

Designing a menu-driven C application
Working with structures
Implementing file-based data storage
Reading and writing records using files
Creating reusable functions
Input validation
Managing and updating stored records
Building a multi-feature console application
🚀 Future Improvements

Possible improvements for future versions include:

Replace text-file storage with a database
Improve password security using password hashing
Add medicine search functionality
Add sales and billing management
Add expiry-date tracking
Add medicine supplier management
Improve input validation and error handling
Replace the console interface with a graphical or web-based interface
👩‍💻 Author

Humayra Binte Islam

Computer Science & Engineering Student

⭐ This project was developed as part of my C programming practice and focuses on applying fundamental C programming concepts to a practical management system.
