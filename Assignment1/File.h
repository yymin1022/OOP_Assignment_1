#include <bits/stdc++.h>
#include "Student.h"
#include "VerifyData.h"

#ifndef ASSIGNMENT1_FILE_H
#define ASSIGNMENT1_FILE_H

using namespace std;

void loadDB(const string& fileName, vector<Student> studentData){
    ifstream dbFile;
    dbFile.open(fileName);

    if(dbFile.is_open()){
        string name, studentID, birthYear, dept, telNum;

        while(!dbFile.eof()){
            getline(dbFile, name);
            getline(dbFile, studentID);
            getline(dbFile, birthYear);
            getline(dbFile, dept);
            getline(dbFile, telNum);

            if(!name.empty()){
                Student newStudent(name, studentID, birthYear, dept, telNum);
                studentData.push_back(newStudent);
            }
        }

        sort(studentData.begin(), studentData.end(), compareStudentName);

        dbFile.close();
    }else{
        ofstream dbFileNew;
        dbFileNew.open(fileName);
        dbFileNew.close();
    }
}

void saveDB(const string& fileName, vector<Student> studentData){
    ofstream dbFile;
    dbFile.open(fileName);

    if(dbFile.is_open()){
        for(auto iter: studentData){
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
        }

        dbFile.close();
    }


}

#endif //ASSIGNMENT1_FILE_H
