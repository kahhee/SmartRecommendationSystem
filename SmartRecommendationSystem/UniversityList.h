#pragma once
#include "University.h"

class UniversityList {

public:
    const int maxLines = 1450;
    const int pageSize;
    struct UniversityNode {
        University university;
        UniversityNode* next;
        UniversityNode(University university)
            : university(university), next(nullptr) {};
    };
    UniversityList();

    void initUniversity();
    void displayUni(int pageNumber);
    void displayUniPaging();
    void searchUni();
    void linearSearch(const string& keyword);
    void binarySearch(const string& keyword);
    void merge(string arr[], int left, int mid, int right);
    void mergeSort(string arr[], int left, int right);
    ~UniversityList();
    string* uniArray;
    UniversityNode* head;
};