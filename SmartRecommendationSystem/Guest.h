#pragma once
#include "User.h"

class Guest :public User {
public:
	Guest();
	void displayGuestMenu();
	void displayAllUniversity();
	void sortUniversityAscByName();
	void searchUniversity();
	void registerAsCustomer();
};

