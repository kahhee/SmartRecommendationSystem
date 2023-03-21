#include "User.h"
#include "University.h"

class Admin : public User
{
public:
	// Constructor
	Admin();
	Admin(string name, string email, string password);

	// Methods
	string login();
	User* displayAllRegisteredUsersDetails();
	string modifyUserDetail(User user);
	void deleteUserAccounts();
	void replyFeedback(string message);
	void summarizeUniversities();
};

