#include "book.h"

Book::Book(std::string title, std::string author, int year, int id)
    : title(std::move(title)), author(std::move(author)), year(year), id(id), available(true) {}

const std::string& Book::getTitle() const { 
    return title; 
    }

const std::string& Book::getAuthor() const { 
    return author; 
    }

int Book::getYear() const { 
    return year; 
    }

int Book::getID() const { 
    return id; 
    }

bool Book::isAvailable() const { 
    return available; 
    }

void Book::borrow() { 
    available = false; 
    }
    
void Book::returnBook() { 
    available = true; 
    }

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "ID: " << book.id << ", Title: " << book.title
       << ", Author: " << book.author << ", Year: " << book.year
       << ", Available: " << (book.available ? "Yes" : "No");
    return os;
}