#pragma once
#include "Feedback.h"

class FeedbackList {
    public:
        struct FeedbackNode {
            Feedback feedback;
            FeedbackNode* previous;
            FeedbackNode* next;

            FeedbackNode(Feedback feedback)
                : feedback(feedback), previous(nullptr), next(nullptr) {}
        };

        FeedbackList();
        FeedbackNode* getHead();
        FeedbackNode* getTail();
        void addFeedbackToFront(Feedback* feedback);
        bool isEmpty();
        ~FeedbackList();

    private:
        FeedbackNode* head;
        FeedbackNode* tail;
};