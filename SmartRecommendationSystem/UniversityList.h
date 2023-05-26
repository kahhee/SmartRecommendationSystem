#pragma once
#include "University.h"

class UniversityList {

public:
    const int maxLines;
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
    void addFavouriteUniversity(int uniNumber);
    void displayFavouriteUni();
    void searchUni();
    void linearSearch(const string& keyword);
    void binarySearch(const string& keyword);
    void merge(string arr[], int low, int mid, int high);
    void mergeSort(string arr[], int low, int high);
    bool containsOnlyWordsAndSpaces(const string& str);
    ~UniversityList();
    string* uniArray;
    UniversityNode* head;
};