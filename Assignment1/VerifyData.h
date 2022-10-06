#include <bits/stdc++.h>
#include "Student.h"

#ifndef ASSIGNMENT1_VERIFYDATA_H
#define ASSIGNMENT1_VERIFYDATA_H

using namespace std;

bool checkDuplicate(const string& studentID, vector<Student> *ptrStudentData){
    for(auto iter: *ptrStudentData){
        if(iter.getID() == studentID){
            return true;
        }
    }

    return false;
}

bool compareStudentDept(Student stu1, Student stu2){
    return stu1.getDept() < stu2.getDept();
}

bool compareStudentID(Student stu1, Student stu2){
    return stu1.getID() < stu2.getID();
}

bool compareStudentName(Student stu1, Student stu2){
    return stu1.getName() < stu2.getName();
}

#endif