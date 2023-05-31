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
    cout << left << "Rank  "
        << "Institution  "
        << "LocationCode  "
        << "Location  "
        << "ArScore  "
        << "ArRank  "
        << "ErScore  "
        << "ErRank  "
        << "FsrScore  "
        << "FsrRank  "
        << "CpfScore  "
        << "CpfRank  "
        << "IfrScore  "
        << "IfrRank  "
        << "IsrScore  "
        << "IsrRank  "
        << "IrnScore  "
        << "IrnRank  "
        << "GerScore  "
        << "GerRank  "
        << "ScoreScaled  "
        << endl;
}