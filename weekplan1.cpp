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

    void addBookPlaceholder() {
        cout << "Add book functionality will be implemented in Week 2.\n";
    }


    void displayBooksPlaceholder() {
        cout << "Display books functionality will be implemented in Week 2.\n";
    }

    void searchBookPlaceholder() {
        cout << "Search book functionality will be implemented in Week 2.\n";
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\n--- Library Management System (Week 1) ---\n";
        cout << "1. Add a Book (Coming Soon)\n";
        cout << "2. Display All Books (Coming Soon)\n";
        cout << "3. Search for a Book (Coming Soon)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBookPlaceholder();
                break;
            case 2:
                library.displayBooksPlaceholder();
                break;
            case 3:
                library.searchBookPlaceholder();
                break;
            case 4:
                cout << "Exiting the program. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

