#include <iostream>

using namespace std;

void selMenu();

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);



    cout << "Hello, World!" << "\n";
    return 0;
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
}