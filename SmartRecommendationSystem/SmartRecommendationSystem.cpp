// SmartRecommendationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Admin.h"
#include "Guest.h"
#include "Customer.h"
#include "Global.h"
using namespace std;

// declaration for Global variables
// dont declare anywhere else, Error will occur : duplicate symbol,
// can only modify the variable
bool isMenu = false;
CustomerList customerList = CustomerList();
UniversityList uniList = UniversityList();
Customer currentCustomer = Customer();
Guest guest = Guest();

int main()
{
    // initiation of university data
    uniList.initUniversity();
    //uniList.displayUniPaging();

    // global variables
    int role;
    Admin admin;
    cout << "Welcome to Smart Recommendation System!" << endl;
    do {
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
        }
        catch (exception e) {
            role = 0;
        }

        switch (role) {
            // Admin
            case 1: {
                bool result = admin.login();
                if (result) {
                    admin.displayMenu();
                } else {
                    cout << endl << "Invalid Credentials. Please try again." << endl << endl;
                }
                break;
            }
            // Customer
            case 2: { 
                bool result = currentCustomer.login();
                if (result) {
                    currentCustomer.displayCustomerMenu();
                } else {
                    cout << endl << "Invalid Credentials. Please try again." << endl << endl;
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
                cout << "Invalid input! Please enter a valid input!" << endl;
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
