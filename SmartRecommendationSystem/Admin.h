#pragma once
#include "User.h"
#include "University.h"

class Admin : public User
{
public:
	// Constructor
	Admin();
	Admin(string name, string email, string password);

	// Methods
	void displayMenu();
	User* displayAllRegisteredUsersDetails();
	string modifyUserDetail(User user);
	void deleteUserAccounts();
	void readFeedback();
	void previousFeedback();
	void nextFeedback();
	void replyFeedback(string message);
	void summarizeUniversities();
	bool login();
	
};

