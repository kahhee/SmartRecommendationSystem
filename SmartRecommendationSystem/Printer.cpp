#include "Printer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

void Printer::printLine(int lineLength, char lineChar) {
    cout << setw(lineLength) << setfill(lineChar) << "" << endl;
}

void Printer::printEnter() {
    string temp;
    cout << endl << endl << "Press Enter to Continue";
    getline(cin, temp);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void Printer::printHeader() {
    // header
    cout << left << "Rank\t"
        << "Institution\t\t"
        << "LocationCode\t"
        << "Location\t"
        << "ArScore\t"
        << "ArRank\t"
        << "ErScore\t"
        << "ErRank\t"
        << "FsrScore\t"
        << "FsrRank\t"
        << "CpfScore\t"
        << "CpfRank\t"
        << "IfrScore\t"
        << "IfrRank\t"
        << "IsrScore\t"
        << "IsrRank\t"
        << "IrnScore\t"
        << "IrnRank\t"
        << "GerScore\t"
        << "GerRank\t"
        << "ScoreScaled\t"
        << endl;
}