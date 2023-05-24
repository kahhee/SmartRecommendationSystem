#pragma once
#include <string>
using namespace std;

struct University
{
	// Data Members
	int rank;
	string institution;
	string locationCode;
	string location;

	double academicReputationScore;
	double academicReputationRank;

	double employerScore;
	double employerRank;

	double faculty_student_Ratio;
	double faculty_student_Rank;

	double citationsPerFacultyRatio;
	double citationsPerFacultyRank;

	double internationalFacultyRatio;
	double internationalFacultyRank;

	double internationalStudentRatio;
	double internationalStudentRank;

	double internationalResearchNetworkRatio;
	double internationalResearchNetworkRank;

	double employmentOutcomeRatio;
	double employmentOutcomeRank;

	double scoreScaled;

	string* stringArr;

	const int fieldCount = 21;

	// Constructor
	University();
	University(string stringArr);
	// Methods
	string* SerializeUniversity(string uniString);
	void toString();
	University* readCSV();
	University* ascendingUniversityName();
	University* searchUniversity(string searchInput);
};





// all return types are not finale, might need to make changes in future
