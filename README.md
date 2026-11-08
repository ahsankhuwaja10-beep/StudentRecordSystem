# Student Record Management System

A GUI-based Student Record Management System built in C++ using MFC (Visual Studio 2022).
Made for SW112 Programming Fundamentals at MUET Khairpur.

## Features
- Add a new student record
- Update an existing record (Roll Number is the unique identifier)
- Delete a record
- Navigate through records with the Next button
- Clear button to go back to Add mode
- Validation: empty fields, duplicate Roll Number, GPA range (0 to 4)

## Data Storage
Records are saved in `records.txt`, one student per line, separated by commas:
Name,RollNumber,FatherName,Caste,District,GPA

## Tools Used
- C++
- Microsoft Visual Studio 2022
- MFC (Microsoft Foundation Classes)

## How to Run
1. Open `Student Record System.sln` in Visual Studio 2022.
2. Press Ctrl+F5 to build and run.

## Author
Ahsan Khuwaja
Department of Software Engineering, MUET Khairpur
