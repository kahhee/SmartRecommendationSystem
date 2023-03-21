#include "Customer.h"

Customer::Customer() {}

Customer::Customer(string name, string email, string password) {
	this->setName(name);
	this->setEmail(email);
	this->setPassword(password);
	this->setUserRole(this->CUSTOMER_ROLE);
}

string Customer::saveFavouriteUniversity()
{
	return "Success";
}