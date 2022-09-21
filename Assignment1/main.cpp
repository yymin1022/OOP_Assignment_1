#include <iostream>
#include <vector>

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

bool checkDuplicate(string);
void insertStudent();
void searchStudent();
void sortStudent();
void selMenu();

bool isExit;
vector<Student> studentData;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    while(!isExit){
        selMenu();
    }

    return 0;
}

bool checkDuplicate(string studentID){
    for(int i = 0; i < studentData.size(); i++){
        if(studentData[i].getID() == studentID){
            return true;
        }
    }

    return false;
}

void insertStudent(){
    string name, studentID, birthYear, dept, telNum;
    while(true){
        cout << "Name ?" << " ";
        cin >> name;

        if(name.size() <= 15 && !name.empty()){
            break;
        }
        cout << "Name must be up to 15 digits." << "\n";
    }

    while(true){
        cout << "Student ID (10 digits)?" << " ";
        cin >> studentID;

        if(studentID.size() == 10 && !studentID.empty()){
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
        cin >> searchData;
    }

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
    cout << this->name << " ";
    cout << this->studentID << " ";
    cout << this->birthYear << " ";
    cout << this->dept << " ";
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
