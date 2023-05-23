#include "UniversityList.h"
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include "Global.h"
using namespace std;

UniversityList::UniversityList() : maxLines(1423), pageSize(10)
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

void UniversityList::searchUni()
{
    string keyword;
    bool validInput = false;

    do {
        cout << "Enter the keyword to search: ";
        cin >> keyword;

        int option;
        cout << "Select the search algorithm:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "Enter your option: ";
        cin >> option;

        // Clear the newline character from the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (option == 1) {
            auto start = chrono::steady_clock::now();
            linearSearch(keyword);
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Linear search executed in " << duration.count() << " milliseconds." << endl;
            validInput = true;
        }
        else if (option == 2) {
            auto start = chrono::steady_clock::now();
            binarySearch(keyword);
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Binary search executed in " << duration.count() << " milliseconds." << endl;
            validInput = true;
        }
        else {
            cout << "Invalid option selected." << endl;
            cout << "Do you want to retry? (y/n): ";
            char retry;
            cin >> retry;

            // Clear the newline character from the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (retry != 'y' && retry != 'Y') {
                validInput = true; // Exit the loop
            }
        }
    } while (!validInput);
}

void UniversityList::linearSearch(const string& keyword)
{
    bool found = false;

    for (int i = 0; i < maxLines; i++) {
        if (uniArray[i].find(keyword) != string::npos) {
            cout << "Match found: " << uniArray[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching universities found." << endl;
    }
}

void UniversityList::binarySearch(const string& keyword)
{
    // Sort the uniArray before performing binary search
    // Sort the uniArray using merge sort
    mergeSort(uniArray, 0, maxLines - 1);

    int low = 0;
    int high = maxLines - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (uniArray[mid].find(keyword) == string::npos) {
            if (uniArray[mid] < keyword) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            cout << "Match found: " << uniArray[mid] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No matching universities found." << endl;
    }
}

void UniversityList::merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays dynamically
    string* L = new string[n1];
    string* R = new string[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Deallocate the temporary arrays
    delete[] L;
    delete[] R;
}

void UniversityList::mergeSort(string arr[], int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right values
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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
