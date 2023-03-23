#include "Admin.h"
#include "Global.h"

Admin::Admin() {}

Admin::Admin(string name, string email, string password)
{
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->ADMIN_ROLE);
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
	// at customer logout, set last logged in date to more than 1 year
	// alt approach : at customer logout, start a timer, after 1 min, // set last logged in date to more than 1 year
}

void Admin::replyFeedback(string message)
{
}

void Admin::summarizeUniversities()
{
}

void Admin::previousFeedback()
{
}

void Admin::nextFeedback()
{
}
