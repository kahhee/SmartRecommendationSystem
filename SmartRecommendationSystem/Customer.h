#pragma once
#include "User.h"
#include "University.h"
#include "UniversityArray.h"
#include "FavUniversityList.h"
class Customer : public User {
private:
	static int nextId;
	string id;
	FavUniversityList* favouriteUniversity;
	string lastLoggedInDate;

public:
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
	void setFavouriteUniversity(FavUniversityList* favUniList);
	FavUniversityList* getFavouriteUniversity();
	bool login();
};
