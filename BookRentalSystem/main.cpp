// Project: Book Rental System (C++)
// Author: Iman Nasibov
// Date Created: June 21, 2025
// Last Updated: June 24, 2025


#include <iostream>
#include "Book.h"
#include "Person.h"
#include "LibrarySystem.h" 
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>


using namespace std;

void showMenu();
void handleChoice(char choice, LibrarySystem& library);
void pauseScreen();
string formatName(const string& input);
bool isValidName(const string& input);
int getCurrentYear();

const int MIN_PUBLICATION_YEAR = 1450;  // Around when the printing press was invented (Gutenberg) — good for historical books



int main() {

    LibrarySystem library;
    srand(time(0));  // Initialize random for Book ID
    char choice;

    while (true) {
        showMenu();
        cin >> choice;
        if (choice == '6') break;
        handleChoice(choice, library);
    }

    return 0;
}



void showMenu() {
    cout << "\n--- Book Rental System Menu ---\n";
    cout << "1. Add Person\n";
    cout << "2. Add Book to Person\n";
    cout << "3. Remove Book from Person\n";
    cout << "4. Display All People and Borrowed Books\n";
    cout << "5. Search For Person\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void handleChoice(char  choice, LibrarySystem& library) {
    system("cls");
    switch (choice) {
    case '1': {
 
        std::string name;
        std::string surname;

        cout << "Enter Name: "; cin >> name;
        cout << "Enter Surname: "; cin >> surname; 
        
         
        if (!isValidName(name)|| !isValidName(surname)) {
            std::cout << "Invalid name or surname! Only letters allowed.\n";
        }
        else {
            std::string validatedName = formatName(name);
            std::string validatedSurname = formatName(surname);
        

            Person p;
            p.name = validatedName;
            p.surname = validatedSurname;
            library.addPerson(p);
             

            break;
           
        }
    
 
        break;
    }

    case '2': {

        if (!library.displayAllPeople(false))
        {
            break;
        }
        
        int id;
        Book b;

        cout << "Enter Person ID: "; cin >> id;
        system("cls");

        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter digits only." << endl;
            break;
        }


        if (library.findPersonById(id) == nullptr)
        {
            cout << "No Person with this ID = " <<id<< endl; 
            break;
        } 
        else
        {
           library.findPersonById(id)->displayPersonInfo(false);
        }
       

        string title = "";
        string author = "";
        int validYear = 0;
        int currentYear = getCurrentYear();


        cout << "Enter Book Title: ";
        cin.ignore(); // Clears leftover newline from previous input
        getline(cin, title);

        if (title.empty())
        {
            std::cout << "Title cannot be empty. Please enter a valid title." << std::endl;
            break;
        }


        cout << "Enter Book Author: ";
        getline(cin, author);

        if (!isValidName(author)) {
            std::cout << "Invalid name! Only letters allowed.\n";
            break;
        }
        else {
            std::string validatedName = formatName(author);
        }

        cout << "Enter Year of Publication: " ; cin >> validYear;

        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter digits only." << endl;

            break;
        }

        if (validYear < MIN_PUBLICATION_YEAR || validYear > currentYear)
        {
            cout << "Publication year must be between " << MIN_PUBLICATION_YEAR << " and " << currentYear << "." << endl;
            break;
        }
         

        b.title = title;
        b.author = author;
        b.publicationYear = validYear;

        b.id = rand() % 999 + 1;

        library.addBookToPerson(id, b) ? "" : "Person not found";
 
        break;
    }

    case '3': {

        if (!library.displayAllPeople(false))
        {
            break;
        }

        int personId, bookId;
        cout << "Enter Person ID: "; cin >> personId;


        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter digits only." << endl;
           
            break;
        }

        Person* person = library.findPersonById(personId);


        if (person == nullptr)
        {
            cout << "No Person with this ID" << endl;
            break;
        }
        else
        {
            person->displayPersonInfo();
        }

        if (!person->borrowedBooks.empty())
        {
            cout << "Enter Book ID to remove: "; cin >> bookId;

            if (cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter digits only." << endl;
                break;
            }

            library.removeBookFromPerson(personId, bookId);
        }

        break;
    }

    case '4':
        library.displayAllPeople();
        break;

    case '5': {

        if (!library.displayAllPeople(false))
        {
            break;
        }

        char choice = 1;

        system("cls");

        cout << "1.Search by ID" << endl;
        cout << "2.Search by Name and Surname" << endl;
        cout << "Choice : ";
        cin >> choice;
      
        system("cls");

        if (choice == '1')
        {
            int id = 0;
            cout << "Enter Person ID: "; cin >> id;

            Person* person = library.findPersonById(id);

            if (person == nullptr)
            {
                cout << "Person Not Found" << endl;
                break;
            }
            person->displayPersonInfo();
        }
        else if (choice == '2')
        {
            std::string name;
            std::string surname;

            cout << "Enter Person Name: "; cin >> name;
            cout << "Enter Person Surname: "; cin >> surname;

            if (!isValidName(name) || !isValidName(surname)) {
                std::cout << "Invalid name or surname! Only letters allowed.\n";
                break;
            }

            std::string validatedName = formatName(name);
            std::string validatedSurname = formatName(surname);


            Person* person = library.findPersonByFullname(validatedName, validatedSurname);

            if (person == nullptr)
            {
                cout << "Person Not Found" << endl;
                break;
            }

            person->displayPersonInfo();
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }


        break;
    }

    default:
        cout << "Invalid choice.\n";
    }

    pauseScreen();
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    system("cls"); 
}


// Checks if the input contains only letters and spaces (no digits or symbols)
bool isValidName(const std::string& input) {
    for (char ch : input) {
        if (!std::isalpha(ch) && !std::isspace(ch)) {
            return false;
        }
    }
    return true;
}

// Helper to trim leading and trailing spaces
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(' ');
    if (start == std::string::npos) return "";  // all spaces

    size_t end = s.find_last_not_of(' ');
    return s.substr(start, end - start + 1);
}

// Formats the input string so each word starts uppercase and the rest are lowercase
std::string formatName(const std::string& input) {


    std::string trimmed = trim(input);
    std::istringstream iss(trimmed);
    std::string word;
    std::string result;

    while (iss >> word) {
        // Convert whole word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        // Capitalize first letter
        if (!word.empty()) {
            word[0] = std::toupper(word[0]);
        }
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }
    return result;
}

// Returns the current year (e.g. 2025)
int getCurrentYear() {
    time_t now = time(nullptr);
    tm localTimeStruct;

#if defined(_MSC_VER)  // For Visual Studio / MSVC
    localtime_s(&localTimeStruct, &now);
#else                 // For GCC / Clang / Linux / macOS
    localtime_r(&now, &localTimeStruct);
#endif

    return 1900 + localTimeStruct.tm_year;
}