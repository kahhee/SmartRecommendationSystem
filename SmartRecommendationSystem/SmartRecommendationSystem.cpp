// SmartRecommendationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Admin.h"
#include "Guest.h"
#include "Customer.h"
#include "Global.h"
#include "Printer.h"
using namespace std;

// declaration for Global variables
// dont declare anywhere else, Error will occur : duplicate symbol,
// can only modify the variable
bool isMenu = false;
CustomerList customerList = CustomerList();
UniversityArray universityArray = UniversityArray();
Customer currentCustomer = Customer();
FeedbackList feedbackList = FeedbackList();
Guest guest = Guest();

int main() {
    // initiation of university data
    universityArray.initUniversity();

    Customer jackson = Customer("Jackson", "jackson@gmail.com", "123");
    Customer daniel = Customer("Daniel", "daniel@gmail.com", "456");
    Customer john = Customer("John", "john@gmail.com", "123");
    customerList.addCustomer(jackson);
    customerList.addCustomer(daniel);
    customerList.addCustomer(john);

    // Create dummy feedbacks
    Feedback feedback1 = Feedback();
    feedback1.id = "1";
    feedback1.customer = &jackson;
    University university1 = University();
    feedback1.university = &university1;
    feedback1.message = "This is the first feedback.";

    Feedback feedback2 = Feedback();
    feedback2.id = "2";
    feedback2.customer = &daniel;
    University university2 = University();
    feedback2.university = &university2;
    feedback2.message = "This is the second feedback.";

    Feedback feedback3 = Feedback();
    feedback3.id = "3";
    feedback3.customer = &john;
    University university3 = University();
    feedback3.university = &university3;
    feedback3.message = "This is the third feedback.";

    // Add feedbacks to the feedback list
    feedbackList.addFeedbackToFront(&feedback1);
    feedbackList.addFeedbackToFront(&feedback2);
    feedbackList.addFeedbackToFront(&feedback3);


    // dummy data for favourite universities
    jackson.saveFavouriteUniversity(1);
    jackson.saveFavouriteUniversity(2);
    jackson.saveFavouriteUniversity(3);
    jackson.saveFavouriteUniversity(4);
    jackson.saveFavouriteUniversity(5);
    jackson.saveFavouriteUniversity(6);
    jackson.saveFavouriteUniversity(7);
    jackson.saveFavouriteUniversity(8);
    jackson.saveFavouriteUniversity(9);
    jackson.saveFavouriteUniversity(10);
    
    daniel.saveFavouriteUniversity(1);
    daniel.saveFavouriteUniversity(11);
    daniel.saveFavouriteUniversity(12);
    daniel.saveFavouriteUniversity(2);
    daniel.saveFavouriteUniversity(13);
    daniel.saveFavouriteUniversity(14);
    daniel.saveFavouriteUniversity(15);
    daniel.saveFavouriteUniversity(16);
    daniel.saveFavouriteUniversity(17);
    daniel.saveFavouriteUniversity(18);
    
    john.saveFavouriteUniversity(19);
    john.saveFavouriteUniversity(1);
    john.saveFavouriteUniversity(3);
    john.saveFavouriteUniversity(2);
    john.saveFavouriteUniversity(5);
    john.saveFavouriteUniversity(7);
    john.saveFavouriteUniversity(18);
    john.saveFavouriteUniversity(90);
    john.saveFavouriteUniversity(8);
    john.saveFavouriteUniversity(99);
    



    int role;
    Admin admin;
    cout << "Welcome to Smart Recommendation System!" << endl;
    do {
        cout << endl << ">> Main Menu" << endl;
        Printer::printLine();
        cout << "Please select your role: " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Guest" << endl;
        cout << "4. Exit" << endl;
        
        cout << "Enter your role : ";
        string option;
        cin >> option;
        try {
            role = stoi(option);
        } catch (exception e) {
            role = 0;
        }

        switch (role) {
            // Admin
            case 1: {
                bool result = admin.login();
                if (result) {
                    cout << endl << "Login successfull!" << endl;
                    admin.displayMenu();
                } else {
                    cout << endl << "Invalid Credentials. Please try again." << endl;
                }
                break;
            }
            // Customer
            case 2: { 
                bool result = currentCustomer.login();
                if (result) {
                    cout << endl << "Login successfull!" << endl;
                    currentCustomer.displayCustomerMenu();
                } else {
                    cout << endl << "Invalid Credentials. Please try again." << endl;
                }
                break;
            }
            // Guest
            case 3:
                Guest().displayGuestMenu();
                break;
            // Exit
            case 4:
                cout << "Thank you for using!" << endl;
                break;
            default:
                cout << endl << "Invalid input! Please enter a valid input!" << endl;
                isMenu = false;
                break;
        }
    } while (role != 4 && !isMenu);
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
