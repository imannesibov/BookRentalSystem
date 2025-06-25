#include "LibrarySystem.h"
#include <iostream>
#include <cstdlib>

using namespace std;

bool LibrarySystem::addPerson(const Person& newPerson) {
    if (findPersonById(newPerson.id) != nullptr) {
        std::cout << "Person with ID " << newPerson.id << " already exists.\n";
        return false;
    }
    people.push_back(newPerson);
    std::cout << "Person added: " << newPerson.name << " " << newPerson.surname << std::endl;
    return true;
}



  
Person* LibrarySystem::findPersonById(int id) {
    for (auto& person : people) {
        if (person.id == id) {
            return &person; // return pointer to found person
        }
    }
    return nullptr;
}

Person* LibrarySystem::findPersonByFullname(const string& name, const string& surname) {
    for (auto& person : people) {
        if (person.name == name && person.surname == surname) {
            return &person;
        }
    }
    return nullptr;
}



// Adds a book to a person's borrowedBooks list
bool LibrarySystem::addBookToPerson(int personId, Book& book) {
    Person* person = findPersonById(personId);
    if (person) {
        book.isBorrowed = true;  // mark book as borrowed
        person->borrowedBooks.push_back(book);
        cout << "Book " << book.title << " added to " << person->name << " " << person->surname << endl;
        return true;
    }
    cout << "Person with ID " << personId << " not found.\n";
    return false;
}

bool LibrarySystem::removeBookFromPerson(int personId, int bookId) {
    Person* person = findPersonById(personId);
    if (person) {
        auto& books = person->borrowedBooks;
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == bookId) {
                it->isBorrowed = false;  // mark book as not borrowed
                books.erase(it);
                cout << "Book with id = " << bookId << " removed from " << person->name << " " << person->surname << endl;
                return true;
            }
        }
        cout << "Book with ID " << bookId << " not found.\n";
        return false;
    }
    else
    {
        cout << "Person with ID " << personId << " not found.\n";
        return false;
    }
}

bool LibrarySystem::displayAllPeople(bool showBooks) {
    if (people.empty())
    {
        cout << "There are no records" << endl;
        return false;
    }

    // Clear the screen
    system("cls");

    for (const auto& person : people) {

        std::cout << "---------------------------\n";
        std::cout << "Person ID: " << person.id << endl << "Name: " << person.name <<endl <<"Surname: " << person.surname << std::endl;
        if (showBooks)
        {
            std::cout << "Borrowed Books:\n";
            if (person.borrowedBooks.empty()) {
                std::cout << "  None\n";
            }
            else {
                for (const auto& book : person.borrowedBooks) {
                    book.displayBookInfo();
                    cout << "--------------------" << endl;
                }
               
            }
        }
        std::cout << "---------------------------\n";
    }
 
    return true;
}
 