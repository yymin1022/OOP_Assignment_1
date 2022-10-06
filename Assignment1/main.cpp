#include <bits/stdc++.h>
#include "File.h"
#include "Student.h"
#include "VerifyData.h"

using namespace std;

void insertStudent();
void searchStudent();
void sortStudent();
void selMenu();

bool isExit;
vector<Student> studentData;

int main(int argc, char *argv[]){
    cout.setf(ios::left);

    if(argc){
        loadDB(argv[1], studentData);
    }

    while(!isExit){
        selMenu();
    }

    if(argc) {
        saveDB(argv[1], studentData);
    }

    return 0;
}

void insertStudent(){
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

    if(!checkDuplicate(studentID, studentData)){
        Student newStudent(name, studentID, birthYear, dept, telNum);
        studentData.push_back(newStudent);
    }else{
        cout << "Error : Already inserted" << "\n";
    }
}

void searchStudent(){
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
            for(auto iter: studentData){
                if(iter.getName() == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 2:
            for(auto iter: studentData){
                if(iter.getID() == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 3:
            for(auto iter: studentData){
                if(iter.getID().substr(0, 4) == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 4:
            for(auto iter: studentData){
                if(iter.getDept() == searchData){
                    iter.printStudent();
                }
            }
            break;
        case 5:
            for(auto iter: studentData){
                iter.printStudent();
            }
            break;
    }
}

void sortStudent(){
    cout << "1. Sort by Name" << "\n";
    cout << "2. Sort by Student ID" << "\n";
    cout << "3. Sort by Admission Year" << "\n";
    cout << "4. Sort by Department name" << "\n";
    cout << ">" << " ";

    int selNum;
    cin >> selNum;

    switch(selNum){
        case 1:
            sort(studentData.begin(), studentData.end(), compareStudentName);
            break;
        case 2:
        case 3:
            sort(studentData.begin(), studentData.end(), compareStudentID);
            break;
        case 4:
            sort(studentData.begin(), studentData.end(), compareStudentDept);
            break;
    }
}

void selMenu(){
    cout << "1. Insertion" << "\n";
    cout << "2. Search" << "\n";
    cout << "3. Sorting Option" << "\n";
    cout << "4. Exit" << "\n";
    cout << ">" << " ";

    int selNum;
    cin >> selNum;

    switch(selNum){
        case 1:
            insertStudent();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            sortStudent();
            break;
        case 4:
            isExit = true;
            break;
    }
}