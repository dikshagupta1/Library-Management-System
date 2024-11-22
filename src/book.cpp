#include "Book.h"
#include <iostream>
#include <iomanip>

void Book::inputDetails() {
    std::cout << "Enter Book ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter Year: ";
    std::cin >> year;
    available = true;
}

void Book::display() const {
    std::cout << std::left << std::setw(10) << id << std::setw(30) << title
              << std::setw(20) << author << std::setw(10) << year
              << std::setw(15) << (available ? "Yes" : "No") << "\n";
}

void Book::borrow() {
    available = false;
}

void Book::returnBook() {
    available = true;
}
