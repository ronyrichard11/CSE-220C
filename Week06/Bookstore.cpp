#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string genre;
    double price;
    int quantity;
};

struct BookInfo {
    string title;
    string author;
    string genre;
    double price;
};

vector<Book> database;
double balance = 0;

void addBook() {
    Book book;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter author: ";
    getline(cin, book.author);
    cout << "Enter genre: ";
    getline(cin, book.genre);
    cout << "Enter price: $";
    cin >> book.price;
    cout << "Enter quantity: ";
    cin >> book.quantity;

    srand(time(0));
    book.id = rand() % 1000 + 1;

    database.push_back(book);
    cout << "Book added successfully with ID: " << book.id << endl;
}

void sellBook() {
    int id, quantity;
    cout << "Enter book ID: ";
    cin >> id;
    cout << "Enter quantity to sell: ";
    cin >> quantity;

    for (Book& book : database) {
        if (book.id == id) {
            if (book.quantity >= quantity) {
                double total = book.price * quantity;
                book.quantity -= quantity;
                balance += total;
                cout << "Sold " << quantity << " book(s). Balance updated: $" << balance << endl;
            } else {
                cout << "Insufficient quantity of books!" << endl;
            }
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void searchBook() {
    string keyword;
    cout << "Enter book title, author, or ID number: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (const Book& book : database) {
        if (book.title == keyword || book.author == keyword || to_string(book.id) == keyword) {
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Genre: " << book.genre << endl;
            cout << "Price: $" << book.price << endl;
            cout << "Quantity: " << book.quantity << endl << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Book not found!" << endl;
    }
}

void displayAllBooks() {
    for (const Book& book : database) {
        cout << "ID: " << book.id << endl;
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Genre: " << book.genre << endl;
        cout << "Price: $" << book.price << endl;
        cout << "Quantity: " << book.quantity << endl << endl;
    }
}

void checkBalance() {
    cout << "Current balance: $" << balance << endl;
}

void buyBook() {
    vector<BookInfo> booksToBuy = {
        {"The Hunger Games", "Suzanne Collins", "Science Fiction", 14.99},
        {"Fahrenheit 451", "Ray Bradbury", "Dystopian Fiction", 12.99},
        {"Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy", 19.99}
    };

    cout << "Available books to buy:\n";

    int option = 1;
    for (const auto& book : booksToBuy) {
        cout << option << ". Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << ", Price: $" << book.price << "\n";
        option++;
    }

    cout << "Enter option: ";
    cin >> option;

    if (option < 1 || option > booksToBuy.size()) {
        cout << "Invalid option!\n";
        return;
    }

    const BookInfo& selectedBook = booksToBuy[option - 1];

    cout << "Book information:\n";
    cout << "Title: " << selectedBook.title << "\n";
    cout << "Author: " << selectedBook.author << "\n";
    cout << "Genre: " << selectedBook.genre << "\n";
    cout << "Price: $" << selectedBook.price << "\n";

    int quantity;
    cout << "Enter quantity to buy: ";
    cin >> quantity;

    // Assign a unique ID to the purchased book
    int maxId = 0;
    for (const Book& book : database) {
        if (book.id > maxId) {
            maxId = book.id;
        }
    }
    int purchasedBookId = maxId + 1;

    // Create a new book object for the purchased book
    Book purchasedBook;
    purchasedBook.id = purchasedBookId;
    purchasedBook.title = selectedBook.title;
    purchasedBook.author = selectedBook.author;
    purchasedBook.genre = selectedBook.genre;
    purchasedBook.price = selectedBook.price;
    purchasedBook.quantity = quantity;

    // Add the purchased book to the database
    database.push_back(purchasedBook);
    cout << "Purchased " << quantity << " book(s) with ID: " << purchasedBookId << "\n";

    // Deduct the total purchase cost from the balance
    double totalCost = selectedBook.price * quantity;
    balance -= totalCost;
}

int main() {
    int choice;

    while (true) {
        cout << "Bookstore Program Menu:\n";
        cout << "1. Add a book to the database\n";
        cout << "2. Sell a book\n";
        cout << "3. Search for a book\n";
        cout << "4. Display all books\n";
        cout << "5. Check balance\n";
        cout << "6. Buy a book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                sellBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                displayAllBooks();
                break;
            case 5:
                checkBalance();
                break;
            case 6:
                buyBook();
                break;
            case 7:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }

        cout << endl;
    }

    return 0;
}
