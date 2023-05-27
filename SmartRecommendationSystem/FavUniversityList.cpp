#include "Global.h"
#include "FavUniversityList.h"
#include <iostream>
#include "Printer.h"
#include <string>
using namespace std;

FavUniversityList::FavUniversityList() {
	head = NULL;
	tail = NULL;
}

FavUniversityList::~FavUniversityList() {
    FavUniversityNode* current = head;
    while (current != NULL) {
        FavUniversityNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void FavUniversityList::addFavouriteUniversity(int uniNumber) {
    University uni = University(universityArray.uniArray[uniNumber]);

    // check if it unique
    if (contains(uni)) {
        cout << endl << "Already Favourited University !" << endl << endl;
        return;
    }

    FavUniversityNode* newNode = new FavUniversityNode(uni);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << endl << uni.institution << " has been added to Favourite!" << endl;
    Printer::printEnter();
}

University* FavUniversityList::displayFavouriteUniForFeedback() {
    cout << "Favourite Universities :" << endl;
    FavUniversityNode* current = head;
    bool isMenu = true;
    while (isMenu) {

        string choice;

        if (head == NULL) {
            cout << "\nNo Favourite Universities. \n";
            return NULL;
        }

        while (current != NULL) {
            // header here ->
            current->university.toString();
            cout << endl;
            current = current->next;
        }
        cout << "Enter University Number (0 to exit):" << endl;
        cin >> choice;
        int choiceInt;
        try {
            choiceInt = stoi(choice);
        } 
        catch (exception e) {
            cout << "Invalid University Number. Please try again" << endl << endl;
            continue;
        }


        if (choiceInt == 0)
            break;

        else if (choiceInt != 0 && choiceInt >= 1) {
            FavUniversityNode* currentUni = head;
            while (currentUni != NULL) {
                if (currentUni->university.rank == choiceInt)
                    return &currentUni->university;
                
                currentUni = currentUni->next;
            }
            cout << "Invalid University Number. Please try again" << endl << endl;
        }
    }
    return NULL;
}

void FavUniversityList::displayFavouriteUni() {
    cout << "Favourite Universities :" << endl;
    FavUniversityNode* current = head;
    while (current != NULL) {
        // header here ->
        current->university.toString();
        cout << endl;
        current = current->next;
    }
}

bool FavUniversityList::contains(University& uni) {
    FavUniversityNode* current = head;
    while (current != NULL) {
        if (current->university.rank == uni.rank) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void FavUniversityList::remove(University& uni) {
    FavUniversityNode* current = head;
    while (current != NULL) {
        if (current->university.rank == uni.rank) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
            else if (current == tail) {
                tail = current->prev;
                tail->next = NULL;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }


            delete current;
            break;
        }
        current = current->next;
    }
}
