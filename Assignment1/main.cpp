#include <bits/stdc++.h>

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

    string getDept(){return this->dept;};
    string getName(){return this->name;};
    string getID(){return this->studentID;};

    void printStudent();
};

bool checkDuplicate(string);
bool compareStudentDept(Student, Student);
bool compareStudentID(Student, Student);
bool compareStudentName(Student, Student);

void loadDB(string);
void saveDB(string);
void insertStudent();
void searchStudent();
void sortStudent();
void selMenu();

bool isExit;
vector<Student> studentData;

int main() {
    cout.setf(ios::left);

    loadDB("file2.txt");

    while(!isExit){
        selMenu();
    }

    return 0;
}

bool checkDuplicate(string studentID){
    for(auto iter: studentData){
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

void loadDB(string fileName){
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

            Student newStudent(name, studentID, birthYear, dept, telNum);
            studentData.push_back(newStudent);
        }

        sort(studentData.begin(), studentData.end(), compareStudentName);

        dbFile.close();
    }else{
        ofstream dbFileNew;
        dbFileNew.open(fileName);
        dbFileNew.close();
    }
}

void saveDB(string fileName){
    ofstream dbFile;
    dbFile.open(fileName);

    for(auto iter: studentData){
        string name, studentID, birthYear, dept, telNum;
        name = iter.getName();
        studentID = iter.getID();
        birthYear = iter.getBirth();
        dept = iter.getDept();
        telNum = iter.getTel();

        dbFile.write(name.c_str(), name.size());
        dbFile.write(studentID.c_str(), studentID.size());
        dbFile.write(birthYear.c_str(), birthYear.size());
        dbFile.write(dept.c_str(), dept.size());
        dbFile.write(telNum.c_str(), telNum.size());
    }
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

    if(!checkDuplicate(studentID)){
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
