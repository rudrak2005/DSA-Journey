#include "../include/Library.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Library::AddBook(int bookId, const string& title, const string& author){
    books.push_back(Book(bookId, title, author));
} 

void Library::displayAllBooks() const {
    if(books.empty()){
        cout<<"No books in the library .\n";
        return;
    }
    cout<<left
    <<setw(6)<<"ID"
    <<setw(32)<<"Title"
    <<setw (20)<<"Author";
    cout<<string(64, '-')<<"\n";

    for(const auto& b: books) b.display();

}

Book* Library::searchBook(int bookId){
    for(auto& b: books){
        if(b.getBookId()==bookId)return &b;
    }
    return nullptr;
}

bool Library::issueBook(int bookId){
    Book*b= searchBook(bookId);
    if(!b){
        cout<<"Book not found. \n";
        return false;

    }
    if(b->getIsIssued()){
        cout<<"Sorry, this book is already issued.\n";
        return false;
    }
    b->issueBook();
    return true;
}

bool Library::returnBook(int bookId){
    Book* b= searchBook(bookId);
    if(!b){
        cout<<"Book not found.\n";
        return false;
    }
    if(!b->getIsIssued()){
        cout<<"This book was not issued.\n";
        return false;
    }
    b->returnBook();
    return true;
}