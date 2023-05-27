#include "FeedbackList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Global.h"

using namespace std;

FeedbackList::FeedbackList() {
    head = nullptr;
    tail = nullptr;
}

FeedbackList::FeedbackNode* FeedbackList::getHead() {
    return head;
}

FeedbackList::FeedbackNode* FeedbackList::getTail() {
    return tail;
}

void FeedbackList::addFeedbackToFront(Feedback* feedback) {
    FeedbackNode* newNode = new FeedbackNode(*feedback);

    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
}

bool FeedbackList::isEmpty() {
    return head == nullptr;
}

FeedbackList::~FeedbackList() {
    FeedbackNode* current = head;
    while (current != nullptr) {
        FeedbackNode* temp = current;
        current = current->next;
        delete temp;
    }
}