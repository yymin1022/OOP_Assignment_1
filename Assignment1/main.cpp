#include <iostream>

using namespace std;

void insertStudent();
void searchStudent();
void sortStudent();
void selMenu();

bool isExit;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    while(!isExit){
        selMenu();
    }

    return 0;
}

class Student{
private:
    string birthYear;
    string dept;
    string name;
    string studentID;
    string telNum;

public:
    void initStudent(string name, string studentID, string birthYear, string dept, string telNum){
        this->birthYear = birthYear;
        this->dept = dept;
        this->name = name;
        this->studentID = studentID;
        this->telNum = telNum;
    };

     void printStudent(){
         cout << this->name << " ";
         cout << this->studentID << " ";
         cout << this->birthYear << " ";
         cout << this->dept << " ";
         cout << this->telNum << "\n";
     }
};

void insertStudent(){
    string name, studentID, birthYear, dept, telNum;
    while(true){
        cout << "Name ?" << " ";
        cin >> name;

        if(name.size() <= 15){
            break;
        }
        cout << "Name must be up to 15 digits." << "\n";
    }

    while(true){
        cout << "Student ID (10 digits)?" << " ";
        cin >> studentID;

        if(studentID.size() == 10){
            break;
        }
        cout << "Student ID must be 10 digits." << "\n";
    }

    while(true){
        cout << "Birth Year (4 digits)?" << " ";
        cin >> birthYear;

        if(birthYear.size() == 4){
            break;
        }
        cout << "Birth Year must be 4 digits." << "\n";
    }

    cout << "Department ?" << " ";
    cin >> dept;

    while(true){
        cout << "Tel ?" << " ";
        cin >> telNum;

        if(telNum.size() <= 12){
            break;
        }
        cout << "Tel Number must be up to 12 digits." << "\n";
    }

    Student newStudent;
    newStudent.initStudent(name, studentID, birthYear, dept, telNum);
}

void searchStudent(){

}

void sortStudent(){

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