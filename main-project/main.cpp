#include <iostream>
#include "file_reader.h"
#include <iomanip>
#include "filters.h"

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

void printSessions(const vector<StudentSession>& sessions, const string& title) {
    cout << "\n=== " << title << " (" << sessions.size() << " records) ===" << endl;
    for (const auto& session : sessions) {
        printSession(session);
    }
}

int main() {
    cout << "Exam Session Results" << endl;
    cout << "Variant: Session Results" << endl;
    cout << "Author: Krivonosog Gleb" << endl;
    cout << "Group: 25Pinj1D" << endl;

    auto sessions = readDataFromFile("data.txt");

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Show all records\n";
        cout << "2. Filter: History of Belarus\n";
        cout << "3. Filter: Grades above 7\n";
        cout << "4. Sort records\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printSessions(sessions, "All Records");
            break;
        case 2:
            printSessions(filterByHistoryBelarus(sessions), "History of Belarus");
            break;
        case 3:
            printSessions(filterByGradeAbove7(sessions), "Grades above 7");
            break;
        case 4:
            break;
        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
