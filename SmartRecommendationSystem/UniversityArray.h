#pragma once
#include "University.h"

class UniversityArray {

public:
    const int maxLines;
    const int pageSize;

    string* uniArray; // data structure to store Universities

    UniversityArray();

    void initUniversity();
    void displayUni(int pageNumber);
    void displayUniPaging();
    University* displayUniForFeedback();
    void searchUni();
    void linearSearch(const string& keyword);
    void binarySearch(const string& keyword);
    void merge(string arr[], int low, int mid, int high);
    void mergeSort(string arr[], int low, int high);
    bool containsOnlyWordsAndSpaces(const string& str);
};

