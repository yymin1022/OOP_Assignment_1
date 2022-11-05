#include <iostream>

#ifndef ASSIGNMENT1_STUDENT_H
#define ASSIGNMENT1_STUDENT_H

using namespace std;

class Student{
private:
    string birthYear;
    string dept;
    string name;
    string studentID;
    string telNum;

public:
    Student(const string &name, const string &studentID, const string &birthYear, const string &dept, const string &telNum);

    string getBirth(){return this->birthYear;};
    string getDept(){return this->dept;};
    string getName(){return this->name;};
    string getID(){return this->studentID;};
    string getTel(){return this->telNum;};

    void printStudent();
};

void Student::printStudent(){
    cout.width(16);
    cout.fill(' ');
    cout << this->name << " ";
    cout.width(11);
    cout.fill(' ');
    cout << this->studentID << " ";
    cout.width(20);
    cout.fill(' ');
    cout << this->dept << " ";
    cout.width(12);
    cout.fill(' ');
    cout << this->birthYear << " ";
    cout.width(12);
    cout.fill(' ');
    cout << this->telNum << "\n";
}

Student::Student(const string &name, const string &studentID, const string &birthYear, const string &dept,
                 const string &telNum) {
    this->birthYear = birthYear;
    this->dept = dept;
    this->name = name;
    this->studentID = studentID;
    this->telNum = telNum;
}

#endif