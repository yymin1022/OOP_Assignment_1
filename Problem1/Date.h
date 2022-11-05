#include <iostream>

#ifndef PROBLEM1_DATE_H
#define PROBLEM1_DATE_H

using namespace std;

class Date{
private:
    int year;
    int month;
    int day;
    string annotation;

public:
    Date(int year, int month, int day){
        this->year = year;
        this->month = month;
        this->day = day;
    }

    string getAnnotation(){
        // This Function is Annotation Getter.
    }

    int getDay(){
        // This Function is Day Getter.
    }

    int getMonth(){
        // This Function is Month Getter.
    }

    int getYear(){
        // This Function is Year Getter.
    }

    void setAnnotation(string annotation){
        // This Function is Annotation Setter.
    }

    void setDay(int day){
        // This Function is Day Setter.
    }

    void setMonth(int month){
        // This Function is Month Setter.
    }

    void setYear(int year){
        // This Function is Year Setter.
    }
};

#endif