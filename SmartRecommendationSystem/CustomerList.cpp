#include "CustomerList.h"
#include <iostream>
#include "Global.h"
using namespace std;

CustomerList::CustomerList() {
	head = NULL;
}

void CustomerList::addCustomer(Customer customer) {
	CustomerNode* newNode = new CustomerNode(customer);
	if (head == NULL) {
	    head = newNode;
	} else {
	    CustomerNode* current = head;
	    while (current->next != NULL) {
	        current = current->next;
	    }
	    current->next = newNode;
	}
}

void CustomerList::displayCustomers() {
	cout << "Customer Details:" << endl;
	
	CustomerNode* current = head;
	while (current != NULL) {
	    cout << "ID: " << current->customer.getID() << endl;
	    cout << "Name: " << current->customer.getName() << endl;
	    cout << "Email: " << current->customer.getEmail() << endl;
	    cout << "Password: " << current-> customer.getPassword() << endl;
	    cout << endl;
	
	    current = current->next;
	}
}

void CustomerList::deleteCustomer(Customer customer) {
	if (head == nullptr) {
		cout << "No customers found." << endl;
		return;
	}

	CustomerNode* current = head;
	CustomerNode* previous = nullptr;

	while (current != nullptr) {
		if (current->customer.getID() == customer.getID()) {
			if (previous == nullptr) {
				// Deleting the first node
				head = current->next;
			} else {
				previous->next = current->next;
			}
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}

	cout << "User account not found." << endl;
}

Customer* CustomerList::findCustomerById(string userID) {
	CustomerNode* current = head;
	while (current != NULL) {
		if (current->customer.getID() == userID) {
			return &(current->customer);
		}
		current = current->next;
	}
	return nullptr;
}

bool CustomerList::loginCustomer(string name, string password) {
	if (head == NULL) {
		return false;
	}
	CustomerNode* current = head;
	while (current != NULL) {
		if (current->customer.getName()._Equal(name) &&
			current->customer.getPassword()._Equal(password) ) {

			currentCustomer.setEmail(current->customer.getEmail());
			currentCustomer.setName(current->customer.getName());
			currentCustomer.setPassword(current->customer.getPassword());
			currentCustomer.setUserRole(currentCustomer.CUSTOMER_ROLE);

			return true;
		}
		current = current->next;
	}
	return false;
}

CustomerList::~CustomerList() {
	CustomerNode* current = head;
    while (current != NULL) {
        CustomerNode* temp = current;
        current = current->next;
        delete temp;
    }
}
