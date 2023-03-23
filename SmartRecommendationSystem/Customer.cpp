#include "Customer.h"

Customer::Customer() {}

Customer::Customer(string name, string email, string password) {
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->CUSTOMER_ROLE);
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
