#include "filters.h"

bool checkByHistoryBelarus(StudentSession* element) {
    return element->discipline == "History of Belarus";
}

bool checkByGradeAbove7(StudentSession* element) {
    return element->grade > 7;
}

StudentSession** filterData(
    StudentSession* array[],
    int size,
    bool (*check)(StudentSession*),
    int& result_size
) {
 
    StudentSession** temp = new StudentSession * [size];
    result_size = 0;
    
    for (int i = 0; i < size; i++) {
        if (check(array[i])) {
            temp[result_size++] = array[i];
        }
    }
    
  
    StudentSession** result = new StudentSession * [result_size];
    for (int i = 0; i < result_size; i++) {
        result[i] = temp[i];
    }
    
    delete[] temp;
    return result;
}
