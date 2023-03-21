#include <string>
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
	string registerUserAsCustomer(string name, string email, string password);
	string login(string email, string password);
	void logout();
};

