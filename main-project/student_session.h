#pragma once
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct StudentSession {
    string lastName;
    string firstName;
    string middleName;
    Date examDate;
    int grade;
    string discipline;
};
