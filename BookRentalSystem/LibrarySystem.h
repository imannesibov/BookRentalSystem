#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <vector>
#include "Person.h"
using namespace std;

class LibrarySystem {
private:
    vector<Person> people; // list of all people in the library system


public:

    // Member function declaration
    bool addPerson(const Person& person);
    Person* findPersonById(int id);
    Person* findPersonByFullname(const string& name, const string& surname);
    bool displayAllPeople(bool showBooks = true);



    // Adds a book to a person's borrowedBooks list
    bool addBookToPerson(int personId,  Book& book);

    // Removes a book from a person's borrowedBooks list 
    bool removeBookFromPerson(int personId, int bookId);

};


#endif

