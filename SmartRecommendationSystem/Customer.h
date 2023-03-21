
#include "User.h"
class Customer : public User
{
public:
	// Constructor
	Customer();
	Customer(string name, string email, string password);

	// Methods
	string saveFavouriteUniversity();

};

