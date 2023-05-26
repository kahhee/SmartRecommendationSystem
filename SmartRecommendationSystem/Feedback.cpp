#include "Feedback.h"
#include "Global.h"
#include <iostream>
using namespace std;
using namespace std::chrono;

int Feedback::nextId = 1;

Feedback::Feedback() {
	id = "";
	customer = NULL;
	university = NULL;
	message = "";
	date = system_clock::now();
}

Feedback::Feedback(University* uni, Customer* cust, string msg) {
	id = "FBK" + to_string(nextId++);
	customer = cust;
	university = uni;
	message = msg;
	date = system_clock::now();
}

void Feedback::sendFeedback(Feedback* feedback) {
	feedbackList.addFeedbackToFront(feedback);
}

void Feedback::readFeedbackReply() {
}

void Feedback::replyFeedback(Feedback* feedback) {
}
