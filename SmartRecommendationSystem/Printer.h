#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Printer {
public:
    static void printLine(int lineLength = 40, char lineChar = '=');

    static void printEnter();

    static void printHeader();
};
