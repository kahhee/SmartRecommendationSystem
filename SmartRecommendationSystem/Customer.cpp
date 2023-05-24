#include "Customer.h"
#include <iostream>
#include "Global.h"
#include <string>

using namespace std;

int Customer::nextId = 1;

Customer::Customer() {
    FavouriteUniversity = new UniversityList();
    lastLoggedInDate = "";
}

Customer::Customer(string name, string email, string password) {
    id = "CTM" + to_string(nextId++);

    setID(id);
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->CUSTOMER_ROLE);

    FavouriteUniversity = new UniversityList();
    lastLoggedInDate = "";
}

void Customer::displayCustomerMenu()
{
    int choice;
    do
    {
        cout << endl << "Welcome " << currentCustomer.getName() << " !" << endl;
        cout << "1. Display sorted universities" << endl;
        cout << "2. Search Universities" << endl;
        cout << "3. View favourite university" << endl;
        cout << "4. Send Feedback" << endl;
        cout << "5. Read Feedback Reply" << endl;
        cout << "6. Logout" << endl;
        cout << "Enter your choice: ";
        string choiceStr;
        cin >> choiceStr;
        try {
            choice = stoi(choiceStr);
        }
        catch (exception e) {
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            // Display universities in sort format
            descendingOrderByARScoreFSRatioERScore();
            break;
        case 2:
            // Search university
            searchUniversity();
            break;
        case 3:
            // View university
            viewFavouriteUniversity();
            break;
        case 4:
            // Send Feedback
            sendFeedback();
            break;
        case 5:
            // read feedback
            readFeedbackReply();
            break;
        case 6:
            // logout
            logout();
            break;
        default:
            cout << "Invalid input! Please enter a valid input!" << endl;
            isMenu = false;
            break;
        }
    } while (choice != 6 && !isMenu);
}

void Customer::saveFavouriteUniversity(int uniNumber)
{
    favouriteUniversity->addFavouriteUniversity(uniNumber);
}

void Customer::viewFavouriteUniversity()
{
    favouriteUniversity->displayFavouriteUni();
}

void Customer::descendingOrderByARScoreFSRatioERScore()
{
    // temp
    uniList.displayUniPaging();
}

void Customer::sendFeedback()
{
}

void Customer::readFeedbackReply()
{
}

void Customer::searchUniversity()
{
    uniList.searchUni();
}

bool Customer::login()
{
	// get inputs
	cout << "Login as Customer" << endl;
	string name;
	string password;
	cout << "Enter Name : ";
	cin >> name;
	cout << "Enter Password : ";
	cin >> password;

	// login with customer list
	bool result = customerList.loginCustomer(name, password);
	return result;

}
