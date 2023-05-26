#pragma once
#include "University.h"

class FavUniversityList {
public:
    struct FavUniversityNode {
        University university;
        FavUniversityNode* next;
        FavUniversityNode* prev;
        FavUniversityNode(University university)
            : university(university), next(nullptr), prev(nullptr) {};
    };
    FavUniversityList();
    ~FavUniversityList();
    void addFavouriteUniversity(int uniNumber);
    University* displayFavouriteUniForFeedback();
    void displayFavouriteUni();
    bool contains(University& uni);
    void remove(University& uni);
private:
    FavUniversityNode* head;
    FavUniversityNode* tail;
};