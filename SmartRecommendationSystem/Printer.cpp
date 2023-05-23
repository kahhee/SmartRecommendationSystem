#include "Printer.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Printer::printLine(int lineLength, char lineChar) {
    cout << setw(lineLength) << setfill(lineChar) << "" << endl;
}
