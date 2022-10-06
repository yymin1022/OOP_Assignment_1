#include <bits/stdc++.h>
#include "Student.h"
#include "VerifyData.h"

#ifndef ASSIGNMENT1_MANAGEDATA_H
#define ASSIGNMENT1_MANAGEDATA_H

using namespace std;

void insertStudent(vector<Student> *ptrStudentData){
    cin.ignore();
    string name, studentID, birthYear, dept, telNum;

    while(true){
        cout << "Name ?" << " ";
        getline(cin, name);

        if(name.size() <= 15 && !name.empty()){
            break;
        }
        cout << "Name must be up to 15 digits." << "\n";
    }

    while(true){
        cout << "Student ID (10 digits)?" << " ";
        getline(cin, studentID);

        if(studentID.size() == 10 && !studentID.empty()){
            break;
        }
        cout << "Student ID must be 10 digits." << "\n";
    }

    while(true){
        cout << "Birth Year (4 digits)?" << " ";
        getline(cin, birthYear);

        if(birthYear.size() == 4){
            break;
        }
        cout << "Birth Year must be 4 digits." << "\n";
    }

    cout << "Department ?" << " ";
    getline(cin, dept);

    while(true){
        cout << "Tel ?" << " ";
        getline(cin, telNum);

        if(telNum.size() <= 12){
            break;
        }
        cout << "Tel Number must be up to 12 digits." << "\n";
    }

    if(!checkDuplicate(studentID, ptrStudentData)){
        Student newStudent(name, studentID, birthYear, dept, telNum);
        ptrStudentData->push_back(newStudent);
    }else{
        cout << "Error : Already inserted" << "\n";
    }
}

void searchStudent(vector<Student> *ptrStudentData){
    cout << "1. Search by name" << "\n";
    cout << "2. Search by student ID (10 numbers)" << "\n";
    cout << "3. Search by admission year (4 numbers)" << "\n";
    cout << "4. Search by department name" << "\n";
    cout << "5. List All" << "\n";
    cout << ">" << " ";

    int selNum;
    cin >> selNum;

    string searchData;
    if(selNum != 5){
        cin.ignore();
        getline(cin, searchData);
    }

    cout.width(16);
    cout.fill(' ');
    cout << "Name" << " ";
    cout.width(11);
    cout.fill(' ');
    cout << "StudentID" << " ";
    cout.width(20);
    cout.fill(' ');
    cout << "Dept" << " ";
    cout.width(12);
    cout.fill(' ');
    cout << "Birth Year" << " ";
    cout.width(12);
    cout.fill(' ');
    cout << "Tel" << "\n";

    switch(selNum){
        case 1:
            for(auto iter: *ptrStudentData){
                if(iter.getName() == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 2:
            for(auto iter: *ptrStudentData){
                if(iter.getID() == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 3:
            for(auto iter: *ptrStudentData){
                if(iter.getID().substr(0, 4) == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 4:
            for(auto iter: *ptrStudentData){
                if(iter.getDept() == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 5:
            for(auto iter: *ptrStudentData){
                iter.printStudent();
            }
            break;
    }
}

void sortStudent(vector<Student> *ptrStudentData){
    cout << "1. Sort by Name" << "\n";
    cout << "2. Sort by Student ID" << "\n";
    cout << "3. Sort by Admission Year" << "\n";
    cout << "4. Sort by Department name" << "\n";
    cout << ">" << " ";

    int selNum;
    cin >> selNum;

    switch(selNum){
        case 1:
            sort(ptrStudentData->begin(), ptrStudentData->end(), compareStudentName);
            break;
        case 2:
        case 3:
            sort(ptrStudentData->begin(), ptrStudentData->end(), compareStudentID);
            break;
        case 4:
            sort(ptrStudentData->begin(), ptrStudentData->end(), compareStudentDept);
            break;
    }
}

#endif //ASSIGNMENT1_MANAGEDATA_H
