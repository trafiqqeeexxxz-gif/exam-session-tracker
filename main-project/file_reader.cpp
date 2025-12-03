#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "constants.h"

using namespace std;

Date parseDate(const string& dateStr) {
    Date d;
    char delimiter;
    stringstream ss(dateStr);
    ss >> d.day >> delimiter >> d.month >> delimiter >> d.year;
    return d;
}

vector<StudentSession> readDataFromFile(const char* filename) {
    vector<StudentSession> sessions;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return sessions;
    }

    string line;
    while (getline(file, line) && sessions.size() < MAX_RECORDS) {
        stringstream ss(line);
        StudentSession session;

        ss >> session.lastName >> session.firstName >> session.middleName;

        string dateStr;
        ss >> dateStr >> session.grade;

        session.examDate = parseDate(dateStr);

        getline(ss, session.discipline);
        if (!session.discipline.empty() && session.discipline[0] == ' ') {
            session.discipline.erase(0, 1);
        }

        sessions.push_back(session);
    }

    file.close();
    return sessions;
}