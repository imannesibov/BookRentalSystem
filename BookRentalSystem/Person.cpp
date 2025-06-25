#ifndef BOOK_H
#define BOOK_H

#include "Person.h"
#include <iostream>



void Person::displayBorrowedBooks() const {
    cout << "Borrowed Books :\n";

    if (borrowedBooks.empty()) {
        cout << "  No books borrowed.\n";
        return;
    }

    for (const auto& book : borrowedBooks) {
          book.displayBookInfo();
          cout << "--------------------" << endl;
    }
}

void Person::displayPersonInfo(bool showBooks ) const {
    
    system("cls"); 

    cout << "Name : " << this->name << endl;
    cout << "Surname : " << this -> surname << endl;
    cout << "ID : " << this->id << "\n\n";

    if (showBooks)
    {
        this->displayBorrowedBooks();
    }
}


#endif
