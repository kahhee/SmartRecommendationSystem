#include "Global.h"
#include "FavUniversityList.h"
#include <iostream>
#include "Printer.h"
#include <string>
using namespace std;

FavUniversityList::FavUniversityList() {
	head = nullptr;
	tail = nullptr;
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
    University uni = University(universityArray.uniArray[uniNumber - 1]);

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

FavUniversityList::FavUniversityNode* FavUniversityList::getHead() {
    return head;
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
