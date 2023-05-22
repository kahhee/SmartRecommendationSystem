#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Guest.h"
#include "Customer.h"
using namespace std;

struct CustomerNode {
    string name;
    string email;
    string password;
    CustomerNode* next;

    CustomerNode(string name, string email, string password)
        : name(name), email(email), password(password), next(nullptr)
    {
    }
};

class CustomerList {
private:
    CustomerNode* head;

public:
    CustomerList() : head(nullptr)
    {
    }

    void addCustomer(string name, string email, string password)
    {
        CustomerNode* newNode = new CustomerNode(name, email, password);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            CustomerNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Customer registered: " << name << endl;
    }

    void displayCustomers()
    {
        cout << "Customer Details:" << endl;

        CustomerNode* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << endl;
            cout << "Email: " << current->email << endl;
            cout << "Password: " << current->password << endl;
            cout << endl;

            current = current->next;
        }
    }

    ~CustomerList()
    {
        CustomerNode* current = head;
        while (current != nullptr) {
            CustomerNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

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

    CustomerList customerList;
	customerList.addCustomer(name, email, password);
}
