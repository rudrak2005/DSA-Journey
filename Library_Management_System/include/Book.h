#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
    private:
            int bookId;
            std::string title;
            std::string author;
            bool isIssued;
    
    public:
            Book();
            Book(int bookId, const std::string& title, const std::string& author);

            int getBookId() const;
            std::string getTitle() const;
            std::string getAuthor()  const;
            bool getIsIssued() const;

            void issueBook();
            void returnBook();
            void display() const;
};

#endif