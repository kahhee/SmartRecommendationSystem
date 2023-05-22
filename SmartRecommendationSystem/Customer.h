#pragma once
#include "User.h"
#include "University.h"
#include "UniversityNode.h"
class Customer : public User
{
public:
	UniversityNode* FavouriteUniversity;
	string lastLoggedInDate;

	// Constructor
	Customer();
	Customer(string name, string email, string password);

	// Methods
	string saveFavouriteUniversity();
	void descendingOrderByARScoreFSRatioERScore();
	void sendFeedback(string message);
	void readFeedbackReply();

};
