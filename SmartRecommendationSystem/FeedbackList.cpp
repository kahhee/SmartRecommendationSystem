#include "FeedbackList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Global.h"
using namespace std;

FeedbackList::FeedbackList() : pageSize(10)
{
	head = NULL;
}

void FeedbackList::displayFeedback()
{
}

void FeedbackList::displayFeedbackPaging()
{
}

FeedbackList::~FeedbackList()
{
    FeedbackNode* current = head;
    while (current != NULL) {
        FeedbackNode* temp = current;
        current = current->next;
        delete temp;
    }
}
