#pragma once
#include <string>
#include "Customer.h"
#include "University.h"
#include <chrono>

using namespace std;

struct Feedback {

public:
	// Data Members
	static int nextId;
	string id;
	Customer* customer;
	University* university;
	string message;
	std::chrono::system_clock::time_point date;

	// Constructor
	Feedback();
	Feedback(University* uni, Customer* customer, string message);
};

