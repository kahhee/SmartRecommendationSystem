#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Guest.h"
#include "Customer.h"
#include "CustomerList.h"
#include "Global.h"
using namespace std;

Guest::Guest() {
	setUserRole(GUEST_ROLE);
}

void Guest::displayAllUniversity()
{
    //load university data set from CSV to array 
    const int maxLines = 1450; // Maximum number of lines to read
    string* arr = new string[maxLines]; // Dynamically allocate array
    string line;
    int i = 0;

    ifstream file("2023 QS World University Rankings.csv");
    if (file.is_open()) {
        while (getline(file, line) && i < maxLines) { // Read lines until maximum or end of file
            arr[i] = line;
            i++;
        }
        file.close();

        // Display the contents of the array
        for (int j = 0; j < i; j++) {
            // Split the line into individual data elements
            istringstream iss(arr[j]);
            string dataElement;
            while (getline(iss, dataElement, ',')) {
                cout << dataElement << " ";
            }
            cout << endl;
        }

        delete[] arr; // Deallocate the dynamically allocated array
    }
    else {
        cout << "Unable to open file";
    }
}
void Guest::sortUniversityAscByName()
{
}

void Guest::searchUniversity(string searchInput)
{
}

void Guest::registerAsCustomer()
{
    string name, email, password;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your password: ";
    getline(cin, password);

    Customer customer = Customer(name, email, password);
    customerList.addCustomer(customer);
}
