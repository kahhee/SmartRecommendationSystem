#pragma once
#include "User.h"
#include "University.h"
#include "UniversityList.h"
class Customer : public User
{
private:
	static int nextId;
	string id;

public:
	UniversityList* favouriteUniversity;
	string lastLoggedInDate;

	// Constructor
	Customer();
	Customer(string name, string email, string password);

	// Methods
	void displayCustomerMenu();
	void saveFavouriteUniversity(int uniNumber);
	void viewFavouriteUniversity();
	void descendingOrderByARScoreFSRatioERScore();
	void searchUniversity();
	void sendFeedback();
	void readFeedbackReply();
	bool login();
};
