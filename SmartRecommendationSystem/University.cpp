#include "University.h"
#include <iostream>
using namespace std;

University::University() {
	rank = 0;

	academicReputationScore = 0;
	academicReputationRank = 0;

	employerScore = 0;
	employerRank = 0;

	faculty_student_Ratio = 0;
	faculty_student_Rank = 0;

	citationsPerFacultyRatio = 0;
	citationsPerFacultyRank = 0;

	internationalFacultyRatio = 0;
	internationalFacultyRank = 0;

	internationalStudentRatio = 0;
	internationalStudentRank = 0;

	internationalResearchNetworkRatio = 0;
	internationalResearchNetworkRank = 0;

	employmentOutcomeRatio = 0;
	employmentOutcomeRank = 0;

	scoreScaled = 0;
}

University* University::readCSV()
{
	// read csv code
};

University* University::ascendingUniversityName()
{
	// sorting code
	// need to implement two different sorting algorithm
};

University* University::searchUniversity(string searchInput)
{
	// search code
	// need to implement two different search algorithm
}
