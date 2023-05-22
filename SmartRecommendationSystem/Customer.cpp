#include "Customer.h"
#include <iostream>
#include "Global.h"

Customer::Customer() {
	Customer::FavouriteUniversity;
	Customer::lastLoggedInDate;
}

Customer::Customer(string name, string email, string password) {
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->CUSTOMER_ROLE);

	Customer::FavouriteUniversity;
	Customer::lastLoggedInDate;

}


void Customer::displayCustomerMenu()
{
	cout << "TEST TEST" << endl;
}


string Customer::saveFavouriteUniversity()
{
	return "Success";
}

void Customer::descendingOrderByARScoreFSRatioERScore()
{
}

void Customer::sendFeedback(string message)
{
}

void Customer::readFeedbackReply()
{
}

string Customer::login()
{
	// get inputs
	string name;
	string password;
	cout << "Enter Name : ";
	cin >> name;
	cout << endl << "Enter Password : ";
	cin >> password;
	setName(name);
	setPassword(password);

	// login with customer list
	bool result = customerList.loginCustomer(name, password);
	if (result) return "Success"; 
	else return "Failed";

}
