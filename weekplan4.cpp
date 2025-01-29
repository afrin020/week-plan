
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
using namespace std;

// 📌
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
};


int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add a Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Exit\n";
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
                cout << "Exiting program. Thank you!\n";
                system("pause");
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
