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

void Guest::displayGuestMenu()
{
    //cout << "TEST TEST" << endl;
    int choice;
    do
    { 
        cout << "1. Display all universities" << endl;
        cout << "2. Sort universities in ascending order by name" << endl;
        cout << "3. Search university" << endl;
        cout << "4. Register as customer" << endl;
        cout << "5. Go back" << endl;
        cout << "Enter your choice: ";
        string choiceStr;
        cin >> choiceStr;
        try {
            choice = stoi(choiceStr);
        }
        catch (exception e) {
            choice = 0;
        }

        switch (choice)
        {
            case 1:
				// Display all universities
				displayAllUniversity();
				break;
            case 2:
                // Sort universities in ascending order by name
                sortUniversityAscByName();
                break;
            case 3:
                // Search university
                searchUniversity();
                break;
            case 4:
                // Register as customer
                registerAsCustomer();
                break;
            case 5:
                // Go back to main menu
                //mainMenu();
                break;
            default:
                cout << "Invalid input! Please enter a valid input!" << endl;
                isMenu = false;
                break;
        }
    } while (choice != 5 && !isMenu);
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

void Guest::searchUniversity()
{
}

void Guest::registerAsCustomer()
{
    string name, email, password;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your email: ";
    cin >> email;

    cout << "Enter your password: ";
    cin >> password;

    Customer customer = Customer(name, email, password);
    customerList.addCustomer(customer);
}
