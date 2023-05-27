#include "FeedbackList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Global.h"

using namespace std;

FeedbackList::FeedbackList() : pageSize(10) {
    head = nullptr;
    tail = nullptr;
}

void FeedbackList::addFeedbackToFront(Feedback* feedback) {
    FeedbackNode* newNode = new FeedbackNode(*feedback);

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
}

Feedback* FeedbackList::getPreviousFeedback(Feedback* currentFeedback) {
    if (!head || !currentFeedback) {
        return nullptr;
    }

    FeedbackNode* currentNode = head;

    while (currentNode && &(currentNode->feedback) != currentFeedback) {
        currentNode = currentNode->next;
    }

    if (currentNode && currentNode->previous) {
        return &(currentNode->previous->feedback);
    } else {
        return nullptr;
    }
}

Feedback* FeedbackList::getNextFeedback(Feedback* currentFeedback) {
    if (!head || !currentFeedback) {
        return nullptr;
    }

    FeedbackNode* currentNode = head;

    while (currentNode && &(currentNode->feedback) != currentFeedback) {
        currentNode = currentNode->next;
    }

    if (currentNode && currentNode->next) {
        return &(currentNode->next->feedback);
    } else {
        return nullptr;
    }
}   

Feedback* FeedbackList::getFirstFeedback() {
    return head ? &(head->feedback) : nullptr;
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