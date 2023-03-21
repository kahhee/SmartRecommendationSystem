#include "Admin.h"

Admin::Admin() {}

Admin::Admin(string name, string email, string password)
{
	this->setName(name);
	this->setEmail(email);
	this->setPassword(password);
	this->setUserRole(this->ADMIN_ROLE);
}

string Admin::login()
{
	return "Success";
}

User* Admin::displayAllRegisteredUsersDetails()
{
	return nullptr;
}

string Admin::modifyUserDetail(User user)
{
	return "Success";
}

void Admin::deleteUserAccounts()
{
}

void Admin::replyFeedback(string message)
{
}

void Admin::summarizeUniversities()
{
}
