#include <string>
#include "Customer.h"
#include "University.h"

using namespace std;

struct Feedback
{
public:
	// Data Members
	Customer customer;
	University uni;
	string message;
	Feedback* nextFeedback;

	// Constructor
	Feedback();

	// Methods
	void sendFeedback(string message);
	void readFeedbackReply();
	void replyFeedback(Feedback* feedback);
	Feedback previousFeedback(Feedback* currentFeedback);
	Feedback nextFeedback(Feedback* currentFeedback);
};

