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
		std::chrono::system_clock::time_point date;

		// Constructor
		Feedback();

		// Methods
		void sendFeedback(string message);
		void readFeedbackReply();
		void replyFeedback(Feedback* feedback);
};

