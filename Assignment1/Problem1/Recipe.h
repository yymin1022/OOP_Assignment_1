#include <iostream>
#include <vector>

#include "Ingredient.h"

#ifndef PROBLEM1_RECIPE_H
#define PROBLEM1_RECIPE_H

using namespace std;

class Recipe{
private:
    int recipeID;                         // Variable for Recipe ID
    int recipeTime;                       // Variable for Recipe Taken Time
    string recipeName;                    // Variable for Recipe Name
    vector<Ingredient> recipeIngredients; // Variable for Recipe Ingredients
    vector<string> recipeStep;            // Variable for Recipe Steps

public:
    Recipe(recipeID){
        this->recipeID = recipeID;
    }

    void addIngredient(Ingredient ing){
        // This Function is for Adding Ingredient.
    }

    void delIngredient(int idx){
        // This Function is for Deleting Specific Ingredient.
    }

    void printRecipe(){
        // This Function is for Printing Recipe Data.
    }

    void getRecipeID(){
        // This Function is Recipe ID Getter.
    }

    void getRecipeName(){
        // This Function is Recipe Name Getter.
    }

    void getRecipeTime(){
        // This Function is Recipe Time Getter.
    }

    void setRecipeID(int recipeID){
        // This Function is Recipe ID Setter.
    }

    void setRecipeName(string recipeName){
        // This Function is Recipe Name Setter.
    }

    void setRecipeTime(int recipeTime){
        // This Function is Recipe Time Setter.
    }
};

#endif