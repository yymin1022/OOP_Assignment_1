#include <iostream>
#include <fstream>
#include <algorithm>

#include "Student.h"
#include "VerifyData.h"

#ifndef ASSIGNMENT1_FILE_H
#define ASSIGNMENT1_FILE_H

using namespace std;

void loadDB(const string& fileName, vector<Student> *ptrStudentData){
    ifstream dbFile;
    dbFile.open(fileName);

    if(dbFile.is_open()){
        string name, studentID, birthYear, dept, telNum;

        while(!dbFile.eof()){
            getline(dbFile, name);
            if(name == "-----"){continue;}
            getline(dbFile, studentID);
            if(studentID == "-----"){continue;}
            getline(dbFile, birthYear);
            if(birthYear == "-----"){continue;}
            getline(dbFile, dept);
            if(dept == "-----"){continue;}
            getline(dbFile, telNum);
            if(telNum == "-----"){continue;}

            string divider;
            getline(dbFile, divider);

            if(!name.empty()){
                Student newStudent(name, studentID, birthYear, dept, telNum);
                ptrStudentData->push_back(newStudent);
            }
        }

        sort(ptrStudentData->begin(), ptrStudentData->end(), compareStudentName);

        dbFile.close();
    }else{
        ofstream dbFileNew;
        dbFileNew.open(fileName);
        dbFileNew.close();
    }
}

void saveDB(const string& fileName, vector<Student> *ptrStudentData){
    ofstream dbFile;
    dbFile.open(fileName);

    if(dbFile.is_open()){
        for(auto iter: *ptrStudentData){
            string name, studentID, birthYear, dept, telNum;
            name = iter.getName() + "\n";
            studentID = iter.getID() + "\n";
            birthYear = iter.getBirth() + "\n";
            dept = iter.getDept() + "\n";
            telNum = iter.getTel() + "\n";

            dbFile.write(name.c_str(), name.size());
            dbFile.write(studentID.c_str(), studentID.size());
            dbFile.write(birthYear.c_str(), birthYear.size());
            dbFile.write(dept.c_str(), dept.size());
            dbFile.write(telNum.c_str(), telNum.size());
            dbFile.write("-----\n", 6);
        }

        dbFile.close();
    }


}

#endif