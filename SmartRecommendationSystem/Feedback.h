#pragma once
#include <string>
#include "Customer.h"
#include "University.h"
#include <chrono>

struct Feedback {

	// Data Members
	static int nextId;
	string id;
	Customer* customer;
	University* university;
	string message;
	string adminReply;
	std::chrono::system_clock::time_point date;

	// Constructor
	Feedback();
	Feedback(University* uni, Customer* customer, string message);
};

