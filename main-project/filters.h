#pragma once
#include "student_session.h"


bool checkByHistoryBelarus(StudentSession* element);
bool checkByGradeAbove7(StudentSession* element);


StudentSession** filterData(
    StudentSession* array[],      
    int size,                    
    bool (*check)(StudentSession*), 
    int& result_size             
);
