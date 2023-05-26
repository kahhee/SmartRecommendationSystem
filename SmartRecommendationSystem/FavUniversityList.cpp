#include "Global.h"
#include "FavUniversityList.h"
#include <iostream>
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
    University uni = University(uniList.uniArray[uniNumber]);

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
    cout << endl << uni.institution << " has been added to Favourite!" << endl << endl;
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
