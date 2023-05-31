#include "UniversityArray.h"
#include <iostream>
#include <string>
#include <chrono>
#include <cctype>
#include <fstream>
#include <sstream>
#include "Global.h"
#include "Printer.h"
using namespace std;

UniversityArray::UniversityArray() : maxLines(1423), pageSize(10) {
    uniArray = NULL;
    delete[] uniArray;
    delete[] tempArray;
    delete[] cleanUniArray;
}

void UniversityArray::initUniversity() {
    // Load university data set from CSV to array
    uniArray = new string[maxLines]; // Dynamically allocate array
    tempArray = new string[maxLines]; // Declare temporary array
    cleanUniArray = new string*[maxLines]; // Declare sorted array
    string line;
    int i = 0;

    ifstream file("2023 QS World University Rankings.csv");
    if (file.is_open()) {
        // Skip the header line
        getline(file, line);

        while (getline(file, line) && i < maxLines) {
            // Read lines until maximum or end of file

            // Extract the university name from the line and store in tempArray
            istringstream iss(line);
            string field;
            string combinedField;

            for (int j = 0; j < 2; j++) {
                getline(iss, field, ',');
                // check if start of qouted field
                if (field.front() == '"' && field.back() != '"') {
                    // set combined field to current field
                    combinedField = field;
                    while (getline(iss, field, ',')) {
                        // concantenate field
                        combinedField += "," + field;
                        // if end of field, reassign and break
                        if (field.back() == '"')
                            field = combinedField;
                            break;
                    }
                }
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

    // create 2d array for university data
    for (int i = 0; i < maxLines - 1; i++) {
        string* temp = new string[30];
        string* line = &uniArray[i];
        istringstream iss(*line);
        string field;
        int j = 0;
        bool inQoute = false;
        string combinedField;
        while (getline(iss, field, ',')) {
            // data cleaning
            if (field == "601+") {
                field = "601";
            }
            else if (field == "501+") {
                field = "501";
            }
            else if (field.empty() || field == "-") {
                field = "0";
            }
            if (field.front() == '"' && field.back() != '"') {
                // set combined field to current field and set qoute to true
                combinedField = field;  
                inQoute = true;
                continue;
            }
            if (inQoute && field.back() != '"') {
                // concantenate field
                combinedField += "," + field;
                continue;
            }
            if (inQoute && field.back() == '"') {
                // if end of field, concat and clear and set qoute to false
                field = combinedField +','+field;
                inQoute = false;
                combinedField.clear(); 
            }
            //remove qoutes from field before storing
            if (field.front() == '"' && field.back() == '"') {
                field = field.substr(1, field.length() - 2);
            }
            // remove leading spaces before storing
            if (field.front() == ' ') {
                field = field.erase(0, field.find_first_not_of(' '));
            }
            // put field inside temp array (string array) and increase j
            temp[j] = field;
            j++;
        }
        // put string array inside sorted array
        cleanUniArray[i] = temp;
    }
}



void UniversityArray::sortByLength(string arr[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        // Move the largest element to the right
        for (int i = start; i < end; i++) {
            if (arr[i].length() > arr[i + 1].length() ||
                (arr[i].length() == arr[i + 1].length() && arr[i] > arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                swap(uniArray[i], uniArray[i + 1]); // Update uniArray as well
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }

        // Move the smallest element to the left
        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (arr[i].length() > arr[i + 1].length() ||
                (arr[i].length() == arr[i + 1].length() && arr[i] > arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                swap(uniArray[i], uniArray[i + 1]); // Update uniArray as well
                swapped = true;
            }
        }
        start++;
    }
}


void UniversityArray::displayUni(int pageNumber) {
    int startIndex = (pageNumber - 1) * pageSize;
    int endIndex = min(startIndex + pageSize, maxLines);

    for (int i = startIndex; i < endIndex; i++) {
        for (int j = 0; j < 21; j++) {
            cout << cleanUniArray[i][j];
            if (j != 20) {
                cout << "  ";
            }
        }
        cout << " " << endl;
    }
}

void UniversityArray::displayCustomerUni(int pageNumber, string** arr) {
    int startIndex = (pageNumber - 1) * pageSize;
    int endIndex = min(startIndex + pageSize, maxLines);

    for (int i = startIndex; i < endIndex; i++) {
        for (int j = 0; j < 21; j++) {
            cout << arr[i][j];
            if (j != 20) {
                cout << "  ";
            }
        }
        cout << " " << endl;
    }
}

void UniversityArray::displayUniPaging(bool isCustomerSorted) {
    int totalPages = (maxLines + pageSize - 1) / pageSize;
    int currentPage = 1;
    bool isCustomer = currentCustomer.getUserRole() == currentCustomer.CUSTOMER_ROLE;

    if (isCustomerSorted) {
        //declare copy of sortedArray
        sortedUniArray = new string * [maxLines];
        for (int i = 0; i < maxLines - 1; i++) {
            sortedUniArray[i] = new string[21];
            for (int j = 0; j < 21; j++) {
                sortedUniArray[i][j] = cleanUniArray[i][j];
            }
        }
    // sort the data based on academic reputation (AR), faculty student ratio (FSR), employer reputation (ER)
    sortCustomerUniDesc(sortedUniArray, 0, maxLines - 2, 6); // ER score sort
    sortCustomerUniDesc(sortedUniArray, 0, maxLines - 2, 8); // FSR score sort
    sortCustomerUniDesc(sortedUniArray, 0, maxLines - 2, 4); // AR score sort
    }



    while (true) {
        cout << "Page " << currentPage << ":" << endl;
        Printer::printHeader();

        if (isCustomerSorted) {
            // display sorted data for customer
            displayCustomerUni(currentPage, sortedUniArray);
        }
        else {
            // display original data for guest
			displayUni(currentPage);
		}

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
            cout << "Enter University Rank (0 to exit): ";
            cin >> uniNumberStr;

            try {
                uniNumber = stoi(uniNumberStr);
            }
            catch (exception e) {
                cout << endl << "Invalid University Rank. Please try again" << endl << endl;
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
                cout << endl << "Invalid University Rank. Please try again." << endl << endl;
                continue;
            }
        }

        if (inputPageInt >= 1 && inputPageInt <= totalPages)
            currentPage = inputPageInt;
        else
            cout << endl << "Invalid page number. Please try again." << endl;

        cout << endl;
    }

    if (isCustomerSorted) {
        // Free the memory of the temporary arrays
        for (int k = 0; k < maxLines - 1; k++) {
            delete[] sortedUniArray[k];
        }
        delete[] sortedUniArray;
    }
}

University* UniversityArray::displayUniForFeedback() {
    int totalPages = (maxLines + pageSize - 1) / pageSize;
    int currentPage = 1;

    while (true)
    {
        cout << "Page " << currentPage << ":" << endl;
        Printer::printHeader();
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

void UniversityArray::searchUni() {
    string keyword;
    bool validInput = false;

    do {
        cout << "Enter the keyword to search (0 to exit): ";
        // Clear the newline character from the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Linear search executed in " << duration.count() << " microseconds." << endl;
                    validInput = true;
                }
                else if (option == 2) {
                    auto start = chrono::steady_clock::now();
                    sortByLength(tempArray, maxLines); // Sort tempArray based on length
                    binarySearch(keyword);
                    auto end = chrono::steady_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Binary search executed in " << duration.count() << " microseconds." << endl;
                    validInput = true;
                }
                else {
                    cout << endl << "Invalid option selected!" << endl;
                }
            }
            else if (keyword == "0")
                break;
            else {
                cout << endl << "Invalid keyword. Please enter only words and spaces." << endl;
            }
        }

    } while (!validInput);
}

void UniversityArray::sortUniAscByName() {
    bool validInput = false;
    int option;

    do {
        cout << endl << "Select the sorting algorithm:" << endl;
        cout << "1. Merge Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "Enter your option: " << endl;
        string optionStr;
        cin >> optionStr;
        try {
			option = stoi(optionStr);
		}
        catch (exception e) {
			cout << endl << "Invalid option! Please try again." << endl;
			continue;
		}

        if (option == 1) {
            validInput = true;
            // declare copy of sortedArray
            sortedUniArray = new string*[maxLines];
            for (int i = 0; i < maxLines - 1; i++) {
                sortedUniArray[i] = new string[21];
                for (int j = 0; j < 21; j++) {
                    sortedUniArray[i][j] = cleanUniArray[i][j];
                }
            }

            // timer for sorting process
            auto start = chrono::steady_clock::now();
            mergeSort(sortedUniArray, 0, maxLines - 2); // merge sort
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

            // display results
            printSortedUni(sortedUniArray);
            cout << "Merge sort executed in " << duration.count() << " microseconds." << endl;

            // Free the memory of the temporary arrays
            for (int k = 0; k < maxLines - 1; k++) {
				delete[] sortedUniArray[k];
			}
            delete[] sortedUniArray;
        }
        else if (option == 2) {
            validInput = true;
            // declare copy of sortedArray
            sortedUniArray = new string*[maxLines];
            for (int i = 0; i < maxLines - 1; i++) {
                sortedUniArray[i] = new string[21];
                for (int j = 0; j < 21; j++) {
                    sortedUniArray[i][j] = cleanUniArray[i][j];
                }
            }

            // timer for sorting process
            auto start = chrono::steady_clock::now();
            insertionSort(sortedUniArray); // insertion sort
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

            // display results
            printSortedUni(sortedUniArray);
            cout << "Insertion sort executed in " << duration.count() << " microseconds." << endl;

            // Free the memory of the temporary arrays
            for (int k = 0; k < maxLines - 1; k++) {
                delete[] sortedUniArray[k];
            }
            delete[] sortedUniArray;
        }
        else {
			cout << "Invalid option! Please try again." << endl;
		}

    } while (!validInput);

}


void UniversityArray::linearSearch(const string& keyword)
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

void UniversityArray::binarySearch(const string& keyword)
{

    int low = 0;
    int high = maxLines - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (tempArray[mid] == keyword) {
            // Match found
            int index = getIndexFromUniArray(tempArray[mid]);
            cout << "Match found: " << uniArray[index] << endl;
            found = true;
            break;
        }
        else if (tempArray[mid].size() < keyword.size()) {
            low = mid + 1;
        }
        else if (tempArray[mid].size() > keyword.size()) {
            high = mid - 1;
        }
        else {
            // Sizes are the same, compare alphabetically in ascending order
            if (tempArray[mid] < keyword) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
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


void UniversityArray::merge(string** arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Create temporary arrays to hold the divided portions
    string** leftArr = new string*[leftSize];
    string** rightArr = new string*[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge the two temporary arrays back into arr
    int i = 0;    // Index of the left array
    int j = 0;    // Index of the right array
    int k = left; // Index of the merged array

    while (i < leftSize && j < rightSize) {
        // Compare the university names
        if (leftArr[i][1] <= rightArr[j][1]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the memory of the temporary arrays
    delete[] leftArr;
    delete[] rightArr;
}


void UniversityArray::mergeSort(string** arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the two halves recursively
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void UniversityArray::insertionSort(string** arr) {
    for (int i = 1; i < maxLines - 1; i++) {
        string key = arr[i][1]; // Store the value of university name as key
        string* currentRow = arr[i]; // Store the current row for later placement

        // Compare with university name of previous row
        // Move element to one position ahead until correct position of key is found
        int j = i - 1;
        while (j >= 0 && (arr[j][1] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the current row at the correct position
        arr[j + 1] = currentRow;
    }
}

void UniversityArray::printSortedUni(string** arr) {
    // Print the sorted array
    for (int i = 0; i < maxLines - 1; i++) {
        for (int j = 0; j < 21; j++) {
            cout << arr[i][j];
            if (j != 20) {
				cout << "   ";
			}
        }
        cout << " " << endl;
    }
}

void UniversityArray::mergeCustomerUniDesc(string** arr, int left, int mid, int right, int columnIndex) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Create temporary arrays to hold the divided portions
    string** leftArr = new string * [leftSize];
    string** rightArr = new string * [rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge the two temporary arrays back into arr
    int i = 0;    // Index of the left array
    int j = 0;    // Index of the right array
    int k = left; // Index of the merged array

    while (i < leftSize && j < rightSize) {
        // Compare the data in the specified column
        if (compareStrings(leftArr[i][columnIndex], rightArr[j][columnIndex], columnIndex) >= 0) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the memory of the temporary arrays
    delete[] leftArr;
    delete[] rightArr;
}

void UniversityArray::sortCustomerUniDesc(string** arr, int left, int right, int columnIndex) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the two halves recursively
        sortCustomerUniDesc(arr, left, mid, columnIndex);
        sortCustomerUniDesc(arr, mid + 1, right, columnIndex);

        // Merge the sorted halves
        mergeCustomerUniDesc(arr, left, mid, right, columnIndex);
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

int UniversityArray::compareStrings(const string& str1, const string& str2, int columnIndex) {
    // Compare strings as doubles when column sepecified is 0 or more than 4
    if (columnIndex == 0 || columnIndex >= 4) {
        double double1 = stod(str1);
        double double2 = stod(str2);
        if (double1 < double2) {
            return -1;
        }
        else if (double1 > double2) {
            return 1;
        }
        else {
            return 0;
        }
    }

    // Compare strings normally when column specified is 1 to 3
    return str1.compare(str2);
}
