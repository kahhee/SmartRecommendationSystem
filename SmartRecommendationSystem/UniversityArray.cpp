#include "UniversityArray.h"
#include <iostream>
#include <string>
#include <chrono>
#include <cctype>
#include <fstream>
#include <sstream>
#include "Global.h"
using namespace std;

UniversityArray::UniversityArray() : maxLines(1423), pageSize(10) {
    uniArray = NULL;
    delete[] uniArray;
    delete[] tempArray;
}

void UniversityArray::initUniversity()
{
    // Load university data set from CSV to array
    uniArray = new string[maxLines]; // Dynamically allocate array
    tempArray = new string[maxLines]; // Declare temporary array
    string line;
    int i = 0;

    ifstream file("2023 QS World University Rankings.csv");
    if (file.is_open()) {
        // Skip the header line
        getline(file, line);

        while (getline(file, line) && i < maxLines) {
            // Read lines until maximum or end of file

            // Extract the university name from the line and store in tempArray
            stringstream ss(line);
            string field;
            for (int j = 0; j < 2; j++) {
                getline(ss, field, ',');
            }
            tempArray[i] = field;

            uniArray[i] = line;
            i++;
        }
        file.close();
    }
    else {
        cout << "Unable to open file";
    }
}



void UniversityArray::sortByLength(string arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].length() > arr[j + 1].length()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void UniversityArray::displayUni(int pageNumber) {
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

void UniversityArray::displayUniPaging() {
    int totalPages = (maxLines + pageSize - 1) / pageSize;
    int currentPage = 1;
    bool isCustomer = currentCustomer.getUserRole() == currentCustomer.CUSTOMER_ROLE;

    while (true)
    {
        cout << "Page " << currentPage << ":" << endl;
        displayUni(currentPage);

        cout << endl;
        cout << "Total Pages: " << totalPages << endl;
        if (isCustomer) {
            cout << "Enter page number (0 to exit, -1 to Favourite): ";
        }
        else {
            cout << "Enter page number (0 to exit): ";
        }


        string inputPage;
        string uniNumberStr;
        int inputPageInt;
        int uniNumber;


        cin >> inputPage;

        try {
            inputPageInt = stoi(inputPage);
        }
        catch (exception e) {
            cout << endl << "Invalid page number. Please try again" << endl << endl;
            continue;
        }


        if (inputPageInt == 0)
            break;
        
        // if customer choose favourite
        if (isCustomer && inputPageInt == -1) {
            cout << "Enter University number (0 to exit): ";
            cin >> uniNumberStr;

            try {
                uniNumber = stoi(uniNumberStr);
            }
            catch (exception e) {
                cout << endl << "Invalid University Number. Please try again" << endl << endl;
                continue;
            }

            if (uniNumber == 0) {
                continue;
            }
            else if (uniNumber != 0 && uniNumber >= 1) {
                currentCustomer.getFavouriteUniversity()->addFavouriteUniversity(uniNumber);
                cout << endl << endl;
                continue;
            }
            else {
                cout << endl << "Invalid University number. Please try again." << endl << endl;
                continue;
            }
        }

        if (inputPageInt >= 1 && inputPageInt <= totalPages)
            currentPage = inputPageInt;
        else
            cout << endl << "Invalid page number. Please try again." << endl;

        cout << endl;
    }
}

University* UniversityArray::displayUniForFeedback() {
    int totalPages = (maxLines + pageSize - 1) / pageSize;
    int currentPage = 1;

    while (true)
    {
        cout << "Page " << currentPage << ":" << endl;
        displayUni(currentPage);

        cout << endl;
        cout << "Total Pages: " << totalPages << endl;
        cout << "Enter page number (0 to exit, -1 to Select): ";

        string inputPage;
        string uniNumberStr;
        int inputPageInt;
        int uniNumber;

        cin >> inputPage;

        try {
            inputPageInt = stoi(inputPage);
        }
        catch (exception e) {
            cout << "Invalid page number. Please try again." << endl;
            continue;
        }


        if (inputPageInt == 0)
            break;

        // if select option
        if (inputPageInt == -1) {
            cout << "Enter University number (0 to return): ";

            cin >> uniNumberStr;
            try {
                uniNumber = stoi(uniNumberStr);
            }
            catch (exception e) {
                cout << "Invalid University number. Please try again." << endl;
                continue;
            }
            if (uniNumber == 0) {
                continue;
            }
            else if (uniNumber != 0 && uniNumber >= 1) {
                return new University(uniArray[uniNumber]);
            }
            else {
                cout << "Invalid University number. Please try again." << endl;
                continue;
            }
        }

        if (inputPageInt >= 1 && inputPageInt <= totalPages)
            currentPage = inputPageInt;
        else
            cout << "Invalid page number. Please try again." << endl;

        cout << endl;
    }
    return NULL;
}

void UniversityArray::searchUni()
{
    string keyword;
    bool validInput = false;
    cout << "Enter the keyword to search: ";

    do {
        getline(cin, keyword);

        if (!keyword.empty()) {
            if (containsOnlyWordsAndSpaces(keyword)) {
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
                    sortByLength(tempArray, maxLines); // Sort tempArray based on length
                    binarySearch(keyword);
                    auto end = chrono::steady_clock::now();
                    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
                    cout << "Binary search executed in " << duration.count() << " milliseconds." << endl;
                    validInput = true;
                }
                else {
                    cout << endl << "Invalid option selected." << endl;
                }
            }
            else {
                cout << endl << "Invalid keyword. Please enter only words and spaces." << endl;
            }
        }
    } while (!validInput);
}


void UniversityArray::linearSearch(const string& keyword)
{
    bool found = false;

    for (int i = 0; i < maxLines; i++) {
        if (containsOnlyWordsAndSpaces(keyword) && (uniArray[i].find(keyword) != string::npos)) {
            cout << "Match found: " << uniArray[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching universities found." << endl;
    }
}

void UniversityArray::binarySearch(const string& keyword)
{
    // Sort the tempArray before performing binary search
    mergeSort(tempArray, 0, maxLines - 1);

    int low = 0;
    int high = maxLines - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (containsOnlyWordsAndSpaces(keyword) && tempArray[mid] == keyword) {
            // Retrieve the index of the matched university in uniArray
            int index = getIndexFromUniArray(tempArray[mid]);
            cout << "Match found: " << uniArray[index] << endl;
            found = true;
            break;
        }

        if (containsOnlyWordsAndSpaces(keyword)) {
            if (tempArray[mid] < keyword) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            cout << "Invalid keyword. Please enter only words and spaces." << endl;
            break;
        }
    }

    if (!found) {
        cout << "No matching universities found." << endl;
    }
}
int UniversityArray::getIndexFromUniArray(const string& universityName)
{
    // Iterate through uniArray to find the index of the matched university name
    for (int i = 0; i < maxLines; i++) {
        if (uniArray[i].find(universityName) != string::npos) {
            return i;
        }
    }
    return -1; // Return -1 if the university name is not found
}

void UniversityArray::merge(string arr[], int low, int mid, int high)
{
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    // Create temporary arrays
    string* leftArr = new string[leftSize];
    string* rightArr = new string[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[low + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = low; // Initial index of merged subarray

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Deallocate temporary arrays
    delete[] leftArr;
    delete[] rightArr;
}

void UniversityArray::mergeSort(string arr[], int low, int high)
{
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Sort the left and right halves recursively
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}


bool UniversityArray::containsOnlyWordsAndSpaces(const string& str)
{
    for (char c : str) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}
