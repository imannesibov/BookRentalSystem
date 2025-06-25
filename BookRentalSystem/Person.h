#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include "Book.h"

using namespace std; 

struct Person {
    string name;
    string surname;
    int id; // unique identifier

    Person() {
    this->id = rand() % 999 + 1;  // generates number between 1 and 999
    }

    vector<Book> borrowedBooks; // list of borrowed books

    // Member function declaration
    void displayBorrowedBooks() const;  // const because it won't modify the object

    void displayPersonInfo(bool showBooks = true) const;

};


#endif
