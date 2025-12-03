#include <iostream>
#include "file_reader.h"
#include <iomanip>

using namespace std;

void printSession(const StudentSession& session) {
    cout << session.lastName << " " << session.firstName << " " << session.middleName << " | "
        << setw(2) << setfill('0') << session.examDate.day << "."
        << setw(2) << setfill('0') << session.examDate.month << "."
        << setw(2) << setfill('0') << session.examDate.year << " | "
        << "Grade: " << session.grade << " | "
        << "Discipline: " << session.discipline
        << endl;
}

int main() {
    cout << "Exam Session Results" << endl;
    cout << "Variant: Session Results" << endl;
    cout << "Author: Krivonosog Gleb" << endl;
    cout << "Group: 25Pinj1D" << endl;

    auto sessions = readDataFromFile("data.txt");
    cout << "\nRecords loaded: " << sessions.size() << endl;

    for (const auto& session : sessions) {
        printSession(session);
    }

    return 0;
}
