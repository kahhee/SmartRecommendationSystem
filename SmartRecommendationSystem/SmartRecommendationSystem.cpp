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

bool isMenu = false;
CustomerList customerList = CustomerList();
Customer currentCustomer = Customer();

void initData() {
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

int main()
{
    // global variables
    int role;
    Admin admin;
    do
    {
        cout << "Welcome to Smart Recommendation System!" << endl;
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
        case 1:
            // Admin
            //cout << "Admin" << endl;
            break;
        case 2:
            // Customer
            //cout << "Customer" << endl;
        {
            string result = Customer().login();
            if (result == "Success")
            {
                currentCustomer.displayCustomerMenu();
            }
            else 
            {
                cout << "failed";
            }
            break;
        }
        case 3:
            // Guest
            //cout << "Guest" << endl;
            break;
        case 4:
            // Exit
            cout << "Thank you for using!" << endl;
            break;
        default:
            cout << "Invalid input! Please enter a valid input!" << endl;
            isMenu = false;
            break;
        }
    } while (role != 4 && !isMenu);
    //initData();
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
