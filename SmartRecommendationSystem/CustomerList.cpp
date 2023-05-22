#include "CustomerList.h"
#include <iostream>
#include "Global.h"
using namespace std;

CustomerList::CustomerList()
{
	head = NULL;
}


void CustomerList::addCustomer(Customer customer)
{
	CustomerNode* newNode = new CustomerNode(customer);
	if (head == NULL) {
	    head = newNode;
	}
	else {
	    CustomerNode* current = head;
	    while (current->next != NULL) {
	        current = current->next;
	    }
	    current->next = newNode;
	}
	
	cout << "Customer registered: " << customer.getName() << endl;
}

void CustomerList::displayCustomers()
{
	cout << "Customer Details:" << endl;
	
	CustomerNode* current = head;
	while (current != NULL) {
	    cout << "Name: " << current->customer.getName() << endl;
	    cout << "Email: " << current->customer.getEmail() << endl;
	    cout << "Password: " << current-> customer.getPassword() << endl;
	    cout << endl;
	
	    current = current->next;
	}
}

bool CustomerList::loginCustomer(string name, string password)
{
	if (head == NULL) return false;
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


CustomerList::~CustomerList()
{
	CustomerNode* current = head;
    while (current != NULL) {
        CustomerNode* temp = current;
        current = current->next;
        delete temp;
    }
}
