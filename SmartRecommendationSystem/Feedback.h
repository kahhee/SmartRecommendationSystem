#pragma once
#include <string>
#include "Customer.h"
#include "University.h"
#include <chrono>

using namespace std;

struct Feedback {
	public:
		// Data Members
		string id;
		Customer* customer;
		University* university;
		string message;
		chrono::system_clock::time_point timestamp;

		// Constructor
		Feedback();

		// Methods
		void sendFeedback(string message);
		void readFeedbackReply();
		void replyFeedback(Feedback* feedback);
};

