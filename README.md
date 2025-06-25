# 📚 Book Rental System

This is a simple C++ console application that simulates a book rental system for a library. Users can add people, assign books to them, and manage their borrowed books.

## 🛠️ Features

- Add a new person to the system
- Add a book to a person
- Remove a book from a person
- Display all people and their borrowed books
- Search for a person by ID
- Input validation (names, book data, etc.)

## 🗂️ Project Structure

📁 ProjectRoot/
├── 📁 Header Files/ # Contains .h files (Book.h, Person.h, LibrarySystem.h)
├── 📁 Source Files/ # Contains .cpp files (Book.cpp, Person.cpp, LibrarySystem.cpp, main.cpp)
├── 📄 README.md # This file

## 🧑‍💻 Technologies Used

- C++
- Standard Template Library (STL): `vector`, `string`
- Object-Oriented Programming (OOP)

## ✅ How to Use

1. Clone or download the project.
2. Open it in Visual Studio.
3. Build and run the project.
4. Follow the on-screen menu to interact with the system.

## 🔎 Example Menu

--- Book Rental System Menu ---

1.Add Person

2.Add Book to Person

3.Remove Book from Person

4.Display All People and Borrowed Books

5.Search For Person

6.Exit

## 📅 Minimum Publication Year

- Books can only be added if their publication year is between **1450** and the **current year**.
  - ✅ `1450` is defined as a constant in the code: `const int MIN_PUBLICATION_YEAR = 1450;`
  - ✅ The current year is determined **dynamically** at runtime using system time functions (`<ctime>`).


## 📖 Validation Rules

- Names and surnames:
- Must not include numbers or special characters.
- Are automatically formatted (e.g., "mARy" → "Mary").
- Book titles must not be empty.
- User input is validated to ensure correct data types (e.g., IDs must be numeric).
- Each person is automatically assigned a unique ID.

## 📝 Notes

Feel free to update or expand this file based on your preferences or future features!