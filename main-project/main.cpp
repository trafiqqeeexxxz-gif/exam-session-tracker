#include <iostream>
#include "file_reader.h"

using namespace std;

int main() {
    cout << "Exam Session Results" << endl;
    cout << "Variant: Session Results" << endl;
    cout << "Author: Krivonosog Gleb" << endl;
    cout << "Group: 25Pinj1D" << endl;

    auto sessions = readDataFromFile("data.txt");
    cout << "\nRecords loaded: " << sessions.size() << endl;

    return 0;
}
