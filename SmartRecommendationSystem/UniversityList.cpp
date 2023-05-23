#include "UniversityList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Global.h"
using namespace std;

UniversityList::UniversityList()
{
	head = NULL;
    uniArray = NULL;
}

void UniversityList::initUniversity()
{
    //load university data set from CSV to array 
    uniArray = new string[maxLines]; // Dynamically allocate array
    string line;
    int i = 0;

    ifstream file("2023 QS World University Rankings.csv");
    if (file.is_open()) {
        while (getline(file, line) && i < maxLines) { 
            // Read lines until maximum or end of file
            uniArray[i] = line;
            i++;
        }
        file.close();

        //delete[] uniArray; // Deallocate the dynamically allocated array
    }
    else {
        cout << "Unable to open file";
    }

}

void UniversityList::displayUni() 
{
    for (int j = 0; j < maxLines; j++) {
        // Split the line into individual data elements
        istringstream iss(uniArray[j]);
        string dataElement;
        while (getline(iss, dataElement, ',')) {
            cout << dataElement << " ";
        }
        cout << endl;
    }
}

UniversityList::~UniversityList()
{
    UniversityNode* current = head;
    while (current != NULL) {
        UniversityNode* temp = current;
        current = current->next;
        delete temp;
    }
}
