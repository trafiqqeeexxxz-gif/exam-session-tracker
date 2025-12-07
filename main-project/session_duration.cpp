#include "session_duration.h"
#include <algorithm>


int dateToDays(const Date& date) {
    return date.year * 365 + date.month * 31 + date.day;
}

int calculateSessionDuration(const vector<StudentSession>& sessions) {
    if (sessions.empty()) {
        return 0;
    }

    int minDays = dateToDays(sessions[0].examDate);
    int maxDays = minDays;

    for (size_t i = 1; i < sessions.size(); ++i) {
        int currentDays = dateToDays(sessions[i].examDate);

        if (currentDays < minDays) {
            minDays = currentDays;
        }

        if (currentDays > maxDays) {
            maxDays = currentDays;
        }
    }

    return maxDays - minDays;
}