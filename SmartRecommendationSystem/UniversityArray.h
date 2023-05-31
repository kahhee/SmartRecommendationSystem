#pragma once
#include "University.h"

class UniversityArray {

public:
    const int maxLines;
    const int pageSize;

    string* uniArray; // data structure to store Universities
    string* tempArray;
    string** sortedArray;
    string** sortedArrayCopy;

    UniversityArray();

    void initUniversity();
    void displayUni(int pageNumber);
    void displayCustomerUni(int pageNumber, string** arr);
    void displayUniPaging(bool isCustomerSorted);
    University* displayUniForFeedback();
    void searchUni();
    void sortUniAscByName();
    void linearSearch(const string& keyword);
    void binarySearch(const string& keyword);
    void merge(string** arr, int left, int mid, int right);
    void mergeSort(string** arr, int left, int right);
    void insertionSort(string** arr);
    void printSortedUni(string** arr);
    void mergeCustomerUniDesc(string** arr, int left, int mid, int right, int columnIndex);
    void sortCustomerUniDesc(string** arr, int left, int right, int columnIndex);
    int getIndexFromUniArray(const string& universityName);
    void sortByLength(string arr[], int size);
    bool containsOnlyWordsAndSpaces(const string& str);
    int compareStrings(const string& str1, const string& str2, int columnIndex);
};

