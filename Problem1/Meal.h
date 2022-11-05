#include <iostream>
#include <vector>

#include "Recipe.h"

#ifndef PROBLEM1_MEAL_H
#define PROBLEM1_MEAL_H

using namespace std;

class Meal{
private:
    int people;
    vector<Recipe> mealMenus;

public:
    Meal(int people){
        this->people = people;
    }

    void addMenu(Recipe recipe){
        // This Function is for Adding Menu to Meal.
    }

    void delMenu(int idx){
        // This Function is for Deleting Specific Meal Menu.
    }

    vector<Recipe> getMenu(){
        // This Function is Meal Menus Getter.
    }

    int getPeople(){
        // This Function is Meal People Getter.
    }

    void setPeople(int people){
        // This Function is Meal People Setter.
    }
};

#endif