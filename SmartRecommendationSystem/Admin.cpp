#pragma once
#include "Admin.h"
#include "Global.h"
#include <iostream>

Admin::Admin() {}

Admin::Admin(string name, string email, string password)
{
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->ADMIN_ROLE);
}

void Admin::displayMenu() {
    int choice;
    do
    {
        cout << endl << "Admin Menu" << endl;
        cout << "1. Display registered users" << endl;
        cout << "2. Modify user details" << endl;
        cout << "3. Delete user" << endl;
        cout << "4. Feedback" << endl;
        cout << "5. Report" << endl;
        cout << "6. Logout" << endl;
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
                displayAllRegisteredUsersDetails();
                break;
            case 2:
                //modifyUserDetail();
                break;
            case 3:
                deleteUserAccounts();
                break;
            case 4:
                readFeedback();
                break;
            case 5:
                summarizeUniversities();
                break;
            case 6:
                currentCustomer.logout();
                break;
            default:
                cout << "Invalid input! Please enter a valid input!" << endl;
                isMenu = false;
                break;
        }
    } while (choice != 6 && !isMenu);
}

User* Admin::displayAllRegisteredUsersDetails()
{
	customerList.displayCustomers();
	return nullptr;
}

string Admin::modifyUserDetail(User user)
{
	return "Success";
}

void Admin::deleteUserAccounts()
{
	// at customer logout, set last logged in date to more than 1 year
	// alt approach : at customer logout, start a timer, after 1 min, // set last logged in date to more than 1 year
	
}

void Admin::readFeedback() {

}

void Admin::previousFeedback()
{
}

void Admin::nextFeedback()
{
}

void Admin::replyFeedback(string message)
{
}

void Admin::summarizeUniversities()
{
}

bool Admin::login()
{
    string adminEmail = "admin";
    string adminPassword = "123";

    string userEmail, userPassword;

    cout << "Enter your email: ";
    cin >> userEmail;

    cout << "Enter your password: ";
    cin >> userPassword;

    return userEmail == adminEmail && userPassword == adminPassword;
}
