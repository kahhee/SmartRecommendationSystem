#pragma once
#include "User.h"
#include "University.h"
#include "Feedback.h"

class Admin : public User {
	public:
		// Constructor
		Admin();
		Admin(string name, string email, string password);

		// Methods
		void displayMenu();
		void viewUser();
		void manageUser();
		void modifyUserDetail(User* user);
		void deleteUserAccounts(User* user);
		void readFeedback();
		void replyFeedback(Feedback* feedback);
		void summarizeUniversities();
		bool login();
};

