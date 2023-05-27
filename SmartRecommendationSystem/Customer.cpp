#include "Customer.h"
#include <iostream>
#include "Global.h"
#include "Printer.h"
#include <string>
#include <limits>

using namespace std;

int Customer::nextId = 1;

Customer::Customer() {
    favouriteUniversity = new FavUniversityList();
    lastLoggedInDate = "";
}

Customer::Customer(string name, string email, string password) {
    id = "CTM" + to_string(nextId++);

    setID(id);
	setName(name);
	setEmail(email);
	setPassword(password);
	setUserRole(this->CUSTOMER_ROLE);
    favouriteUniversity = new FavUniversityList();
    lastLoggedInDate = "";
}

void Customer::displayCustomerMenu() {
    int choice;
    do
    {
        cout << endl << "Welcome " << currentCustomer.getName() << endl;
        Printer::printLine(40, '=');
        cout << ">> Customer Menu" << endl;
        Printer::printLine(40, '=');
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
            cout << endl <<">> Customer Menu > Send Feedback" << endl;
            Printer::printLine();
            // Send Feedback
            sendFeedback();
            break;
        case 5:
            cout << ">> Customer Menu > Read Feedback" << endl;
            Printer::printLine();
            // read feedback
            readFeedbackReply();
            break;
        case 6:
            // logout
            logout();
            break;
        default:
            cout << endl << "Invalid input! Please enter a valid input!" << endl;
            isMenu = false;
            break;
        }
    } while (choice != 6 && !isMenu);
}

void Customer::saveFavouriteUniversity(int uniNumber) {
    favouriteUniversity->addFavouriteUniversity(uniNumber);
}

void Customer::viewFavouriteUniversity() {
    cout << endl << ">> Customer Menu > View Favourite Universities" << endl;
    Printer::printLine();
    favouriteUniversity->displayFavouriteUni();
}

void Customer::descendingOrderByARScoreFSRatioERScore() {
    // temp
    cout << endl << ">> Customer Menu > Display Universities" << endl;
    Printer::printLine();
    universityArray.displayUniPaging();
}

void Customer::sendFeedback() {
    University* selectedUni = new University();

    bool isMenu = true;
    string choice;
    string message;
    // select a university first
    while (isMenu) {
        cout << endl << "Select a University";
        cout << endl << "1. From All Universities";
        cout << endl << "2. From Favourites";
        cout << endl << "3. Return to menu";
        cout << endl << "Enter your choice: ";
        cin >> choice;

        if (!isdigit(choice[0])) {
            cout << endl << "Invalid option. Please try again." << endl;
            continue;
        }

        switch (stoi(choice)) {
            case 1: {
                selectedUni = universityArray.displayUniForFeedback();
                isMenu = selectedUni == NULL ? true : false;
                break;
            }
            case 2: {
                selectedUni = currentCustomer.
                    favouriteUniversity->displayFavouriteUniForFeedback();
                isMenu = selectedUni == NULL ? true : false;
                break;
            }
            case 3: {
                isMenu = false;
                break;
            }
            default :
                cout << endl << "Invalid input! Please enter a valid input!" << endl;
                break;
        }
    }

    // input the message
    if (!selectedUni->institution.empty()) {
        cout << endl << "Type in your feedback below:" << endl;
        cin.ignore();
        getline(cin, message);
        // send feedback
        Customer* customer = new Customer(currentCustomer);
        Feedback feedback = Feedback(selectedUni, customer, message);
        feedbackList.addFeedbackToFront(&feedback);
        cout << endl << endl << "Feedback Successfully Submitted!" << endl;
    }
}

void Customer::readFeedbackReply() {
    Feedback* currentFeedback = feedbackList.getFirstFeedback();
    string space;
    do
    {
        if (currentFeedback->customer->getID() == currentCustomer.getID()) {
            cout << endl << "Admin Reply for the latest feedback:" << endl;
            Printer::printLine();
            cout << endl << "University  : " << currentFeedback->university->institution;
            cout << endl << "Message     : " << currentFeedback->message;
            if(currentFeedback->adminReply.empty())
                cout << endl << "Admin Reply : No Reply Yet";
            else 
                cout << endl << "Admin Reply : " << currentFeedback->adminReply;
            Printer::printEnter();
            break;
        }
        
        Feedback* nextFeedback = feedbackList.getNextFeedback(currentFeedback);
        currentFeedback = nextFeedback;

    } while (currentFeedback != NULL);
}

void Customer::searchUniversity() {
    cout << endl << ">> Customer Menu > Search Universities" << endl;
    Printer::printLine();
    universityArray.searchUni();
}

FavUniversityList* Customer::getFavouriteUniversity() {
    return favouriteUniversity;
}

void Customer::setFavouriteUniversity(FavUniversityList* favUniList) {
    favouriteUniversity = favUniList;
}

bool Customer::login() {
    cout << endl << ">> Main Menu > Login (Customer)" << endl;
    Printer::printLine();

	// get inputs
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
