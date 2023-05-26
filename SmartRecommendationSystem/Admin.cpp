#pragma once
#include "Admin.h"
#include "Global.h"
#include <iostream>
#include <iomanip>
#include "Printer.h"

Admin::Admin() {}

Admin::Admin(string name, string email, string password) {
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->ADMIN_ROLE);
}

void Admin::displayMenu() {
    string option;
    do {
        cout << endl << ">> Admin Menu" << endl;
        Printer::printLine();
        cout << "1. Manage user" << endl;
        cout << "2. Feedback" << endl;
        cout << "3. Report" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter your choice: ";

        cin >> option;
        if (!isdigit(option[0])) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        switch (stoi(option)) {
            case 1:
                manageUser();
                break;
            case 2:
                cout << endl << ">> Admin Menu > Feedback" << endl;
                Printer::printLine();
                readFeedback();
                break;
            case 3:
                cout << endl << ">> Admin Menu > Report" << endl;
                Printer::printLine();
                summarizeUniversities();
                break;
            case 4:
                logout();
                break;
            default:
                cout << "Invalid input! Please enter a valid input!" << endl;
                isMenu = false;
                break;
        }
    } while (!isMenu);
}

void Admin::manageUser() {
    bool stopProcess = false;
    bool modifyUser = false;
    bool displayCustomerDetails = true;

    while (!stopProcess) {
        if (displayCustomerDetails) {
            cout << endl << ">> Admin Menu > Manage user" << endl;
            Printer::printLine();
            customerList.displayCustomers();
            cout << "\\ Enter 0 to go back" << endl;
            displayCustomerDetails = false;
        }

        string userId;
        cout << "Enter the User ID to modify or delete: ";
        cin >> userId;
        if (userId == "0") {
            return;
        }
        User* foundUser = customerList.findCustomerById(userId);
        if (foundUser == nullptr) {
            cout << "Invalid User ID. Please try again." << endl;
            continue;
        }

        // Display user details
        cout << endl << "User Details" << endl;
        Printer::printLine(40, '-');
        cout << "ID      : " << foundUser->getID() << endl;
        cout << "Name    : " << foundUser->getName() << endl;
        cout << "Email   : " << foundUser->getEmail() << endl;
        cout << "Password: " << foundUser->getPassword() << endl;
        cout << endl << "1) Modify user details" << endl;
        cout << "2) Delete user" << endl;

        // Prompt for manage user action
        string option;
        while (true) {
            cout << "Select an option for the user: ";
            cin >> option;

            if (option == "0") {
                stopProcess = true;
                break;
            }
            if (!isdigit(option[0])) {
                cout << "Invalid option. Please try again." << endl;
                continue;
            }

            switch (stoi(option)) {
                case 1:
                    modifyUserDetail(foundUser);
                    modifyUser = true;
                    break;
                case 2:
                    deleteUserAccounts(foundUser);
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
                    continue;
            }
            break;
        }

         // Display customer details in the next iteration
        if (modifyUser) {
            displayCustomerDetails = true;  
            modifyUser = false;
            continue;
        }

        // If not modifying user, return to the "Admin Menu"
        break;
    }
}

void Admin::modifyUserDetail(User* user) {
    string option;

    cout << endl << ">> Admin Menu > Manage user > Modify user" << endl;
    Printer::printLine(45);
    cout << "1) Name" << endl;
    cout << "2) Email" << endl;
    cout << "3) Password" << endl;

    while (true) {
        cout << "Enter the option to modify: ";
        cin >> option;

        if (option == "0") {
            return;
        }
       
        if (!isdigit(option[0])) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        string field;
        switch (stoi(option)) {
            case 1:
                field = "name";
                cout << "Enter the new name: ";
                break;
            case 2:
                field = "email";
                cout << "Enter the new email: ";
                break;
            case 3:
                field = "password";
                cout << "Enter the new password: ";
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                continue;
        }

        string newValue;
        cin >> newValue;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid " << field << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (stoi(option) == 1) {
            user->setName(newValue);
        } else if (stoi(option) == 2) {
            user->setEmail(newValue);
        } else if (stoi(option) == 3) {
            user->setPassword(newValue);
        }

        cout << endl << "User " << field << " modified successfully." << endl;
        return;
    }
}

void Admin::deleteUserAccounts(User* user) {
    cout << endl << "Are you sure you want to delete this user? (Press Enter to confirm)" << endl;
    cin.ignore();
    cin.get();

    if (user->getUserRole() == User::CUSTOMER_ROLE) {
        Customer* customer = static_cast<Customer*>(user);
        customerList.deleteCustomer(*customer);
        cout << "User account deleted successfully." << endl;
    }
    else {
        cout << "Failed to delete user account. User is not a customer." << endl;
    }
}

void Admin::readFeedback() {
    Feedback* currentFeedback = feedbackList.getFirstFeedback();
    if (currentFeedback != nullptr) {
        bool isMenu = true;
        string option;
        bool feedbackPrinted = false;  // Track if the feedback has been printed

        cout << "\\ Enter 0 to go back" << endl;
        cout << "1) Previous Feedback" << endl;
        cout << "2) Next Feedback" << endl;
        while (isMenu) {
            if (!feedbackPrinted) {
                // Display the feedback only if it hasn't been printed before
                Printer::printLine(40, '-');
                cout << endl << "ID        : " << currentFeedback->id << endl;
      
                auto currentTime = chrono::system_clock::now();
                auto timestamp = chrono::system_clock::to_time_t(currentFeedback->timestamp);
                tm localTime;
                localtime_s(&localTime, &timestamp);

                cout << "Posted on : " << put_time(&localTime, "%F %T") << std::endl;
                cout << "Customer  : " << currentFeedback->customer->getName() << endl;
                cout << "University: " << currentFeedback->university->institution << endl;
                cout << "Message   : " << currentFeedback->message << endl << endl;
                feedbackPrinted = true;
            }

            cout << "Enter your choice: ";
            cin >> option;
            if (!isdigit(option[0])) {
                cout << "Invalid option. Please try again." << endl;
                feedbackPrinted = true;  // Set the flag to indicate that feedback is already printed
                continue;
            }

            switch (stoi(option)) {
                case 1: {
                    Feedback* previousFeedback = feedbackList.getPreviousFeedback(currentFeedback);
                    if (previousFeedback != nullptr) {
                        currentFeedback = previousFeedback;
                        feedbackPrinted = false;  // Reset the flag to print the new feedback
                    } else {
                        cout << "This is the latest feedback, no previous feedback available.";
                        feedbackPrinted = true;  // Set the flag to indicate that feedback is already printed
                    }
                    break;
                }
                case 2: {
                    Feedback* nextFeedback = feedbackList.getNextFeedback(currentFeedback);
                    if (nextFeedback != nullptr) {
                        currentFeedback = nextFeedback;
                        feedbackPrinted = false;  // Reset the flag to print the new feedback
                    } else {
                        cout << "This is the oldest feedback, no next feedback available.";
                        feedbackPrinted = true;  // Set the flag to indicate that feedback is already printed
                    }
                    break;
                }
                case 0:
                    isMenu = false;
                    break;
                default:
                    cout << "Invalid input! Please enter a valid input!" << endl;
                    feedbackPrinted = true;  // Set the flag to indicate that feedback is already printed
                    break;
            }
            cout << endl;
        }
    } else {
        cout << "There are currently no feedbacks submitted by any customer." << endl;
    }
}

void Admin::replyFeedback(string message) {
}

void Admin::summarizeUniversities() {
}

bool Admin::login() {
    string adminEmail = "admin";
    string adminPassword = "123";

    string userEmail, userPassword;

    cout << "Enter your email: ";
    cin >> userEmail;

    cout << "Enter your password: ";
    cin >> userPassword;

    return userEmail == adminEmail && userPassword == adminPassword;
}

