#include <bits/stdc++.h>
#include "File.h"
#include "ManageData.h"
#include "Student.h"
#include "VerifyData.h"

using namespace std;
bool selMenu(vector<Student>*);

int main(int argc, char *argv[]){
    cout.setf(ios::left);
    vector<Student> studentData;

    if(argc > 0){
        loadDB(argv[1], &studentData);
    }

    while(selMenu(&studentData));

    if(argc > 0) {
        saveDB(argv[1], &studentData);
    }

    return 0;
}

bool selMenu(vector<Student> *ptrStudentData){
    cout << "1. Insertion" << "\n";
    cout << "2. Search" << "\n";
    cout << "3. Sorting Option" << "\n";
    cout << "4. Exit" << "\n";
    cout << ">" << " ";

    int selNum;
    cin >> selNum;

    switch(selNum){
        case 1:
            insertStudent(ptrStudentData);
            break;
        case 2:
            searchStudent(ptrStudentData);
            break;
        case 3:
            sortStudent(ptrStudentData);
            break;
        case 4:
            return false;
    }

    return true;
}