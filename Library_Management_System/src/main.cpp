#include "../include/Library.h"
#include <iostream>
using namespace std;
void printMenu()
{
    cout << "\n========= LIBRARY MANAGEMENT SYSTEM =========\n";
    cout << "1. Add Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Issue Book\n";
    cout << "4. Return Book\n";
    cout << "5. Search Book\n";
    cout << "0. Exit\n";
    cout << "================================================\n";
    cout << "Enter choice: ";
}

int main()
{
    Library library;

    library.AddBook(1, "The C++ Programing Language", "Bjarne Stroustrup");
    library.AddBook(2, "Introduction to Algorithms", "Coremen");

    int choice;

    do
    {
        printMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int id;
            string title, author;
            cout << "Book ID: ";
            cin >> id;
            cout << "Title: ";
            cin.ignore();
            getline(cin, author);
            cout << "Author: ";
            getline(cin, author);
            library.AddBook(id, title, author);
            cout << "Book Added successfully!\n";
            break;
        }
        case 2:
        library.displayAllBooks();
        break;

        case 3: {
            int id;
            cout<<"Enter Book ID to  issue: ";
            cin>>id;
            if(library.issueBook(id)) cout<<"Book issued successfully\n";
            break;
        }

        case 4: {
            int id;
            cout <<"Enter Book ID to return: ";
            cin >>id;
            if(library.returnBook(id)) cout <<"Book returned successfully!\n";
            break;
        }
        case 5: {
            int id;
            cout<<"Enter Book ID to Search: ";
            cin>>id;
            Book* b = library.searchBook(id);
            if(b) b->display();
            else cout<<"Book not found.\n";
            break;
        }
        case 0:
                cout<<"Exiting..... Goodbye!\n";
                break;
                default:
                cout<<"Invalid choice! Try again.\n";
    }
}while(choice != 0);
return 0;
}