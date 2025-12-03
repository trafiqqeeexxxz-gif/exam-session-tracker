#include "filters.h"
#include <algorithm>

using namespace std;

vector<StudentSession> filterByHistoryBelarus(const vector<StudentSession>& sessions) {
    vector<StudentSession> result;
    for (const auto& session : sessions) {
        if (session.discipline == "History of Belarus") {
            result.push_back(session);
        }
    }
    return result;
}

vector<StudentSession> filterByGradeAbove7(const vector<StudentSession>& sessions) {
    vector<StudentSession> result;
    for (const auto& session : sessions) {
        if (session.grade > 7) {
            result.push_back(session);
        }
    }
    return result;
}