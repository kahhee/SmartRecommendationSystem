#pragma once
#include "Feedback.h"

class FeedbackList {

public:
    const int pageSize;
    struct FeedbackNode {
        Feedback feedback;
        FeedbackNode* next;
        FeedbackNode(Feedback feedback)
            : feedback(feedback), next(nullptr) {};
    };
    FeedbackList();

    void displayFeedback();
    void displayFeedbackPaging();
    ~FeedbackList();
    FeedbackNode* head;
};