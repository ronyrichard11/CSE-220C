#ifndef BOOKSTORE_HPP
#define BOOKSTORE_HPP

#include <string>
#include <vector>
#include <list>

struct Book {
    int id;
    std::string title;
    std::string author;
    std::string genre;
    double price;
    int quantity;
};

struct BookInfo {
    std::string title;
    std::string author;
    std::string genre;
    double price;
};

extern std::vector<Book> database;
extern double balance;

void addBook();
void sellBook();
void searchBook();
void displayAllBooks();
void checkBalance();
void buyBook();

#endif  // BOOKSTORE_HPP
