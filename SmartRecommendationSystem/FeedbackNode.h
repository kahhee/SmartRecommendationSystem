#pragma once
#include "Feedback.h"
struct FeedbackNode
{
	Feedback feedback;
	FeedbackNode* nextFeedbackNode;
	FeedbackNode* prevFeedbackNode;
};