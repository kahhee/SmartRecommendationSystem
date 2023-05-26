#include "Feedback.h"

Feedback::Feedback() {
	timestamp = chrono::system_clock::now();
}

void Feedback::sendFeedback(string message) {
}

void Feedback::readFeedbackReply() {
}

void Feedback::replyFeedback(Feedback* feedback) {
}
