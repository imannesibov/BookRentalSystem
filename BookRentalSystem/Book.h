#pragma once
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int publicationYear;
    bool isBorrowed = false; // status
    int id;// unique identifier

    void displayBookInfo() const;
};

