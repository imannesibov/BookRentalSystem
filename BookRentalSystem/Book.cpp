#include "Book.h"
#include <iostream>

using namespace std;

void Book::displayBookInfo() const {
	cout << "Title: " << this->title << endl
		<< "Author: " << this->author << endl
		<< "Year: " << this->publicationYear << endl
		<< "ID: " << this->id << endl
		<< (this->isBorrowed ? " [Borrowed]" : "") << endl;
}
