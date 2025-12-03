#pragma once
#include <vector>
#include "student_session.h"

using namespace std;

typedef int (*ComparatorFunc)(const StudentSession*, const StudentSession*);

void insertionSort(vector<StudentSession*>& sessions, ComparatorFunc comparator);
void mergeSort(vector<StudentSession*>& sessions, ComparatorFunc comparator);
