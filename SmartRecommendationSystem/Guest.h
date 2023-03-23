#pragma once
#include "User.h"
class Guest :public User
{
public:
	Guest();
	void displayAllUniversity();
	void sortUniversityAscByName();
	void searchUniversity(string searchInput);
	void registerAsCustomer(string name, string email, string password);
};

