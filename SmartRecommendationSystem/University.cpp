#pragma once
#include "University.h"
#include <sstream>
#include <iostream>
using namespace std;

University::University() {
	rank = 0;

	institution = "";
	locationCode = "";
	location = "";

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

University::University(string uniString) {
	stringArr = SerializeUniversity(uniString);

	rank = stoi(stringArr[0]);

	institution = stringArr[1];
	locationCode = stringArr[2];
	location = stringArr[3];

	academicReputationScore = stoi(stringArr[4]);
	academicReputationRank = stoi(stringArr[5]);

	employerScore = stoi(stringArr[6]);
	employerRank = stoi(stringArr[7]);

	faculty_student_Ratio = stoi(stringArr[8]);
	faculty_student_Rank = stoi(stringArr[9]);

	citationsPerFacultyRatio = stoi(stringArr[10]);
	citationsPerFacultyRank = stoi(stringArr[11]);

	internationalFacultyRatio = stoi(stringArr[12]);
	internationalFacultyRank = stoi(stringArr[13]);

	internationalStudentRatio = stoi(stringArr[14]);
	internationalStudentRank = stoi(stringArr[15]);

	internationalResearchNetworkRatio = stoi(stringArr[16]);
	internationalResearchNetworkRank = stoi(stringArr[17]);

	employmentOutcomeRatio = stoi(stringArr[18]);
	employmentOutcomeRank = stoi(stringArr[19]);

	scoreScaled = stoi(stringArr[20]);
}

string* University::SerializeUniversity(string uniString) {
	istringstream iss(uniString);
	string element;
	bool inQoutes = false;
	string combinedField;
	string* stringArr = new string[fieldCount];
	int i = 0;

	while (getline(iss, element, ','))
	{
		if (element.empty()) {
			element = "0";
			stringArr[i] = element;
			i++;
		}
		else {
			if (!inQoutes) {
				// check if it start of a qouted field
				if (element.front() == '"' && element.back() != '"') {
					inQoutes = true;
					combinedField = element;
				}
				// if not, add into string Arr
				else {
					// if element is -, set the element to 0
					if (element.front() == '-') 
						element = "0";
					stringArr[i] = element;
					i++;
				}
			}
			// if it is in qoutes, combine the fields until end of qouted field
			else {
				combinedField += "," + element;
				if (element.back() == '"') {
					inQoutes = false;
					stringArr[i] = combinedField;
					combinedField.clear();
					i++;
				}
			}
		}
	}
	return stringArr;
}

void University::toString() {
	for (int i = 0;i < fieldCount;i++) {
		cout << stringArr[i] << "\t";
	}
}
