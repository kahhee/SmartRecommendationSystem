#include "UniversityList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Global.h"
using namespace std;

UniversityList::UniversityList() : maxLines(1422), pageSize(10)
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

void UniversityList::displayUni(int pageNumber) 
{
    int startIndex = (pageNumber - 1) * pageSize;
    int endIndex = min(startIndex + pageSize, maxLines);

    for (int j = startIndex; j < endIndex; j++)
    {
        // Split the line into individual data elements
        istringstream iss(uniArray[j]);
        string dataElement;
        while (getline(iss, dataElement, ','))
        {
            cout << dataElement << " ";
        }
        cout << endl;
    }
}

void UniversityList::displayUniPaging()
{
    int totalPages = (maxLines + pageSize - 1) / pageSize;
    int currentPage = 1;

    while (true)
    {
        cout << "Page " << currentPage << ":" << endl;
        displayUni(currentPage);

        cout << endl;
        cout << "Total Pages: " << totalPages << endl;
        cout << "Enter page number (0 to exit): ";

        int inputPage;
        cin >> inputPage;

        if (inputPage == 0)
            break;

        if (inputPage >= 1 && inputPage <= totalPages)
            currentPage = inputPage;
        else
            cout << "Invalid page number. Please try again." << endl;

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
