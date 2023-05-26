#pragma once
#include "User.h"
#include "University.h"

class Admin : public User {
	public:
		// Constructor
		Admin();
		Admin(string name, string email, string password);

		// Methods
		void displayMenu();
		void manageUser();
		void modifyUserDetail(User* user);
		void deleteUserAccounts(User* user);
		void readFeedback();
		void replyFeedback(string message);
		void summarizeUniversities();
		bool login();
};

