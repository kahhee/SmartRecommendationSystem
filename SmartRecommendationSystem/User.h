#include <string>
#include "University.h"
using namespace std;

class User
{	
private:
	// Data Members
	string name;
	string email;
	string password;
	string userRole;

public:
    // Constants
    const string ADMIN_ROLE = "ADMIN";
    const string CUSTOMER_ROLE = "CUSTOMER";
    const string GUEST_ROLE = "GUEST";
    
	// Get / Set
    string getName();
    string getEmail();
    string getPassword();
    string getUserRole() const;
    void setName(string newName);
    void setEmail(string newEmail);
    void setPassword(string newPassword);
    void setUserRole(const string newRole);

	// Methods
    University* searchUniversity(string searchInput);
    void login(string email, string password);
	void logout();
};

