#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Book {
private:
    string title;
    string author;
    bool isAvailable;

public:

    Book(string t, string a, bool available = true)
        : title(t), author(a), isAvailable(available) {}


    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }


    void setAvailability(bool available) { isAvailable = available; }


    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};


class Library {
private:
    vector<Book> books;

public:

    void addBook() {
        string title, author;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);

        books.push_back(Book(title, author));
        cout << "Book added successfully!\n";
    }


    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "\n--- Library Books ---\n";
        for (const auto &book : books) {
            book.displayBook();
        }
    }


    void searchBook() {
        string keyword;
        cout << "Enter the title or author to search: ";
        cin.ignore();
        getline(cin, keyword);

        bool found = false;
        for (const auto &book : books) {
            if (book.getTitle().find(keyword) != string::npos ||
                book.getAuthor().find(keyword) != string::npos) {
                book.displayBook();
                found = true;
            }
        }

        if (!found) {
            cout << "No books found matching the search criteria.\n";
        }
    }


    void borrowBook() {
        string title;
        cout << "Enter the title of the book to borrow: ";
        cin.ignore();
        getline(cin, title);

        for (auto &book : books) {
            if (book.getTitle() == title) {
                if (book.getAvailability()) {
                    book.setAvailability(false);
                    cout << "You have successfully borrowed the book: " << title << endl;
                    return;
                } else {
                    cout << "Sorry, this book is currently unavailable.\n";
                    return;
                }
            }
        }
        cout << "Book not found in the library.\n";
    }


    void returnBook() {
        string title;
        cout << "Enter the title of the book to return: ";
        cin.ignore();
        getline(cin, title);

        for (auto &book : books) {
            if (book.getTitle() == title) {
                if (!book.getAvailability()) {
                    book.setAvailability(true);
                    cout << "Thank you for returning the book: " << title << endl;
                    return;
                } else {
                    cout << "This book was not borrowed.\n";
                    return;
                }
            }
        }
        cout << "Book not found in the library.\n";
    }
};


int main() {
    Library library;
    int choice;

    while (true) {

        cout << "\n--- Library Management System ---\n";
        cout << "1. Add a Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Borrow a Book\n";
        cout << "5. Return a Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.borrowBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                cout << "Exiting the program. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

