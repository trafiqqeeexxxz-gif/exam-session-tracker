#include "comparators.h"

int compareByLastName(const StudentSession* a, const StudentSession* b) {
    if (a->lastName < b->lastName) return -1;
    if (a->lastName > b->lastName) return 1;
    return 0;
}

int compareByDisciplineAndGrade(const StudentSession* a, const StudentSession* b) {
    if (a->discipline < b->discipline) return -1;
    if (a->discipline > b->discipline) return 1;

    // If disciplines are equal, sort by grade (descending)
    if (a->grade > b->grade) return -1;
    if (a->grade < b->grade) return 1;
    return 0;
}