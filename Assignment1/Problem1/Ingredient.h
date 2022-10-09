#include <iostream>

#ifndef PROBLEM1_INGREDIENT_H
#define PROBLEM1_INGREDIENT_H

using namespace std;

class Ingredient{
private:
    int amount;  // Variable for Ingredient Amount
    string name; // Variable for Ingredient Name

public:
    Ingredient(string name, int amount){
        this->amount = amount;
        this->name = name;
    }

    int getAmount(){
        // This Function is Ingredient Amount Getter.
    }

    string getName(){
        // This Function is Ingredient Name Getter.
    }

    void setAmount(int amount){
        // This Function is Ingredient Amount Setter.
    }

    void setName(string name){
        // This Function is Ingredient Name Setter.
    }
};

#endif