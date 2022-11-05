#include <iostream>
#include <vector>

#include "Date.h"
#include "Recipe.h"

#ifndef PROBLEM1_PLAN_H
#define PROBLEM1_PLAN_H

using namespace std;

class Plan{
private:
    Date date;
    vector<Recipe> meals(3);

public:
    Plan(Date date, Recipe Breakfast, Recipe Lunch, Recipe Dinner){
        this->date = date;
        this->meals[0] = Breakfast;
        this->meals[1] = Lunch;
        this->meals[2] = Dinner;
    }

    Recipe getBreakfast(){
        // This Function is Breakfast Getter.
    }

    Recipe getLunch(){
        // This Function is Lunch Getter.
    }

    Recipe getDinner(){
        // This Function is Dinner Getter.
    }

    Date getDate(){
        // This Function is Date Getter.
    }

    void setBreakfast(Recipe recipe){
        // This Function is Breakfast Setter.
    }

    void setLunch(Recipe recipe){
        // This Function is Lunch Setter.
    }

    void setDinner(Recipe recipe){
        // This Function is Dinner Setter.
    }

    void setDate(Date date){
        // This Function is Date Setter.
    }
};

#endif