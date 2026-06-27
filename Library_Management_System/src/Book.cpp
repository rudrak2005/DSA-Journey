#include "../include/Book.h"
#include <iostream>
#include <iomanip>
using namespace std;

Book::Book() : bookId(0), title(""),author(""), isIssued(false){}
 Book::Book(int bookId, const string& title, const string& author): bookId(bookId), title(title),
 author(author), isIssued(false) {}

 int Book::getBookId() const {return bookId;}
 string Book::getTitle() const { return title;}
 string Book::getAuthor() const{return author   ;}
 bool Book::getIsIssued() const {return isIssued;}

 void Book::issueBook(){isIssued = true;}
 void Book::returnBook(){isIssued= false;}

 void Book::display() const {
    cout<<left
    <<setw(6)<<bookId
    <<setw<<(32)<<title
    <<setw(20)<<author
    <<(isIssued ? "Issued ": "Avaiable")<<"\n";
 }
