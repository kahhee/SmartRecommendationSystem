#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Guest.h"
#include "Customer.h"
#include "CustomerList.h"
#include "Global.h"
#include "Printer.h"
using namespace std;

Guest::Guest() {
	setUserRole(GUEST_ROLE);
}

void Guest::displayGuestMenu() {
    int choice;
    do {
        cout << endl << ">> Main Menu > Guest Menu" << endl;
        Printer::printLine();
        cout << "1. Display all universities" << endl;
        cout << "2. Sort universities in ascending order by name" << endl;
        cout << "3. Search university" << endl;
        cout << "4. Register as customer" << endl;
        cout << "5. Main menu" << endl;
        cout << "Enter your choice: ";
        string choiceStr;
        cin >> choiceStr;
        try {
            choice = stoi(choiceStr);
        } catch (exception e) {
            choice = 0;
        }

        switch (choice) {
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
                break;
            default:
                cout << "Invalid input! Please enter a valid input!" << endl;
                isMenu = false;
                break;
        }
    } while (choice != 5 && !isMenu);
}

void Guest::displayAllUniversity() {
    universityArray.displayUniPaging(false);
}

void Guest::sortUniversityAscByName() {
	universityArray.sortUniAscByName();
}

void Guest::searchUniversity() {
    universityArray.searchUni();
}

void Guest::registerAsCustomer() {
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
