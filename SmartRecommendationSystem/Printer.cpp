#include "Printer.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Printer::printLine(int lineLength, char lineChar) {
    cout << setw(lineLength) << setfill(lineChar) << "" << endl;
}

void Printer::printEnter() {
    string temp;
    cout << endl << "Press Enter to Continue";
    getline(cin, temp);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}
