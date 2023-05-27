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
    } while (stoi(option) != 4 &&!isMenu);
}

void Admin::viewUser() {
    CustomerList::CustomerNode* current = customerList.getHead();

    if (current == nullptr) {
        cout << "No user found." << endl << endl;
        return;
    }

    while (current != nullptr) {
        Customer customer = current->customer;
        cout << "ID: " << customer.getID() << endl;
        cout << "Name: " << customer.getName() << endl;
        cout << "Email: " << customer.getEmail() << endl << endl;
        current = current->next;
    }
}

void Admin::manageUser() {
    bool stopProcess = false;
    bool modifyUser = false;
    bool displayCustomerDetails = true;

    while (!stopProcess) {
        if (displayCustomerDetails) {
            cout << endl << ">> Admin Menu > Manage user" << endl;
            Printer::printLine();
            viewUser();
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
    FeedbackList::FeedbackNode* currentNode = feedbackList.getHead();
    if (currentNode != nullptr) {
        bool isMenu = true;
        string option;
        bool isFeedbackPrinted = false; // Flag variable to track if feedback has been printed

        cout << "\\ Enter 0 to go back" << endl;
        cout << "1) Newer Feedback" << endl;
        cout << "2) Older Feedback" << endl;
        cout << "3) Reply to Feedback";

        do {
            if (!isFeedbackPrinted) {
                cout << endl;
                Printer::printLine(40, '-');
                cout << endl << "ID        : " << currentNode->feedback.id << endl;

                auto currentTime = chrono::system_clock::now();
                auto timestamp = chrono::system_clock::to_time_t(currentNode->feedback.date);
                tm localTime;
                localtime_s(&localTime, &timestamp);

                cout << "Posted on : " << put_time(&localTime, "%F %T") << std::endl;
                cout << "Customer  : " << currentNode->feedback.customer->getName() << endl;
                cout << "University: " << currentNode->feedback.university->institution << endl;
                cout << "Message   : " << currentNode->feedback.message << endl;
                cout << "Reply     : " << currentNode->feedback.adminReply << endl << endl;
                isFeedbackPrinted = true;
            }

            cout << "Enter your choice: ";
            cin >> option;
            if (!isdigit(option[0])) {
                cout << "Invalid option. Please try again." << endl;
                continue;
            }

            switch (stoi(option)) {
                case 1: {
                    FeedbackList::FeedbackNode* previousNode = currentNode->previous;
                    if (previousNode != nullptr) {
                        currentNode = previousNode;
                        isFeedbackPrinted = false; // Reset the flag when moving to the previous feedback
                    } else {
                        cout << "You have reached the latest feedback." << endl;
                    }
                    break;
                }
                case 2: {
                    FeedbackList::FeedbackNode* nextNode = currentNode->next;
                    if (nextNode != nullptr) {
                        currentNode = nextNode;
                        isFeedbackPrinted = false; // Reset the flag when moving to the next feedback
                    } else {
                        cout << "You have reached the oldest feedback." << endl;
                    }
                    break;
                }
                case 3:
                    replyFeedback(&(currentNode->feedback));
                    isFeedbackPrinted = false; // Reset the flag when adding a reply
                    break;
                case 0:
                    isMenu = false;
                    break;
                default:
                    cout << "Invalid input! Please enter a valid input!" << endl;
                    break;
            }
        } while (isMenu);
    } else {
        cout << "There are currently no feedbacks submitted by any customer." << endl;
    }
}

void Admin::replyFeedback(Feedback* feedback) {
    string reply;
    cout << "Enter your reply: ";
    cin.ignore(); // Ignore the newline character in the input buffer
    getline(cin, reply);

    feedback->adminReply = reply;
    cout << endl << "Reply added successfully." << endl;
}

void Admin::summarizeUniversities() {
}

bool Admin::login() {
    cout << endl << ">> Main Menu > Login (Admin)" << endl;
    Printer::printLine();

    string adminEmail = "admin";
    string adminPassword = "123";

    string userEmail, userPassword;

    cout << "Enter your email: ";
    cin >> userEmail;

    cout << "Enter your password: ";
    cin >> userPassword;

    return userEmail == adminEmail && userPassword == adminPassword;
}

