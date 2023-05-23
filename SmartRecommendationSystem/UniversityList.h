#pragma once
#include "University.h"

class UniversityList {

public:
    const int maxLines = 1450;
    struct UniversityNode {
        University university;
        UniversityNode* next;
        UniversityNode(University university)
            : university(university), next(nullptr) {};
    };
    UniversityList();

    void initUniversity();
    void displayUni();
    ~UniversityList();
    string* uniArray;
    UniversityNode* head;
};