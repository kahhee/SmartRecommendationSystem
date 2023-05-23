#include "Customer.h"
#include <iostream>
#include "Global.h"
#include <string>

using namespace std;


Customer::Customer() {
	Customer::FavouriteUniversity;
	Customer::lastLoggedInDate;
}

Customer::Customer(string name, string email, string password) {
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->CUSTOMER_ROLE);

	Customer::FavouriteUniversity;
	Customer::lastLoggedInDate;

}


void Customer::displayCustomerMenu()
{
	//cout << "TEST TEST" << endl;
    int choice;
    do
    {
        cout << endl << "Welcome " << currentCustomer.getName() << " !" << endl;
        cout << "1. Display sorted universities" << endl;
        cout << "2. Search Universities" << endl;
        cout << "3. Save favourite university" << endl;
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
            // Search university
            saveFavouriteUniversity();
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
            currentCustomer.logout();
            break;
        default:
            cout << "Invalid input! Please enter a valid input!" << endl;
            isMenu = false;
            break;
        }
    } while (choice != 6 && !isMenu);
}

void Customer::saveFavouriteUniversity()
{

}

void Customer::descendingOrderByARScoreFSRatioERScore()
{
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
