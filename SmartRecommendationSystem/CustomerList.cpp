#include "CustomerList.h"
#include <iostream>
#include "Global.h"
using namespace std;

CustomerList::CustomerList() {
	head = nullptr;
}

void CustomerList::addCustomer(Customer customer) {
	CustomerNode* newNode = new CustomerNode(customer);
	if (head == nullptr) {
	    head = newNode;
	} else {
	    CustomerNode* current = head;
	    while (current->next != nullptr) {
	        current = current->next;
	    }
	    current->next = newNode;
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
	while (current != nullptr) {
		if (current->customer.getID() == userID) {
			return &(current->customer);
		}
		current = current->next;
	}
	return nullptr;
}

CustomerList::CustomerNode* CustomerList::getHead() {
	return head;
}

bool CustomerList::loginCustomer(string name, string password) {
	if (head == nullptr) {
		return false;
	}
	CustomerNode* current = head;
	while (current != nullptr) {
		if (current->customer.getName()._Equal(name) &&
			current->customer.getPassword()._Equal(password) ) {

			currentCustomer.setEmail(current->customer.getEmail());
			currentCustomer.setName(current->customer.getName());
			currentCustomer.setPassword(current->customer.getPassword());
			currentCustomer.setUserRole(currentCustomer.CUSTOMER_ROLE);
			currentCustomer.setFavouriteUniversity(current->customer.getFavouriteUniversity());

			return true;
		}
		current = current->next;
	}
	return false;
}

bool CustomerList::isEmpty() {
	return head == nullptr;
}

CustomerList::~CustomerList() {
	CustomerNode* current = head;
    while (current != nullptr) {
        CustomerNode* temp = current;
        current = current->next;
        delete temp;
    }
}
