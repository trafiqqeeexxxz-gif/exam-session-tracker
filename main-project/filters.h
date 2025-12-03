#pragma once
#include <vector>
#include "student_session.h"

using namespace std;

vector<StudentSession> filterByHistoryBelarus(const vector<StudentSession>& sessions);
vector<StudentSession> filterByGradeAbove7(const vector<StudentSession>& sessions);
