#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include<string>

class Library {
    private:
    std::vector<Book> books;

    public:
            void AddBook(int bookId, const std::string & title, const std::string& author);
            void displayAllBooks()const;
            bool issueBook (int bookId);
            bool returnBook(int bookId);
            Book* searchBook(int bookId);
};
#endif