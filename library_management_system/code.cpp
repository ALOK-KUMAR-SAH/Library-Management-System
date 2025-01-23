#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // for formatting output
using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor, bool issued = false) 
        : id(bookId), title(bookTitle), author(bookAuthor), isIssued(issued) {}
};

// Library class
class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, const string& title, const string& author) {
        books.emplace_back(id, title, author);
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        cout << left << setw(10) << "ID" << setw(30) << "Title" 
             << setw(30) << "Author" << "Status\n";
        for (const auto& book : books) {
            cout << left << setw(10) << book.id 
                 << setw(30) << book.title 
                 << setw(30) << book.author 
                 << (book.isIssued ? "Issued" : "Available") << endl;
        }
    }

    void issueBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "Book is already issued.\n";
                } else {
                    book.isIssued = true;
                    cout << "Book issued successfully!\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book is not issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

// Main Function
int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(); // Clear input buffer
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;

        case 2:
            library.displayBooks();
            break;

        case 3:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            library.issueBook(id);
            break;

        case 4:
            cout << "Enter Book ID to return: ";
            cin >> id;
            library.returnBook(id);
            break;

        case 5:
            cout << "Exiting the system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
