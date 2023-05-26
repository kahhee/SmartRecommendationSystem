#pragma once
#include "Feedback.h"

class FeedbackList {
    public:
        const int pageSize;

        struct FeedbackNode {
            Feedback feedback;
            FeedbackNode* previous;
            FeedbackNode* next;

            FeedbackNode(Feedback feedback)
                : feedback(feedback), previous(nullptr), next(nullptr) {}
        };

        FeedbackList();
        void addFeedbackToFront(Feedback* feedback);
        Feedback* getPreviousFeedback(Feedback* currentFeedback);
        Feedback* getNextFeedback(Feedback* currentFeedback);
        Feedback* getFirstFeedback();
        bool isEmpty();
        ~FeedbackList();

    private:
        FeedbackNode* head;
        FeedbackNode* tail;
};