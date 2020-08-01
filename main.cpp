#include <iostream>
#include "Models/Book.h"
#include "ResourceModels/BookResource.h"
#include "Collections/BookCollection.h"
#include "Asker.h"

#define print std::cout <<
#define nl << std::endl
#define input std::cin >>

void printAllBooks();

void addNewBook();

void removeBook();

int main() {
    bool run = true;

    print "Welcome to library inventory system of company \"ABC\"" nl nl;

    while (run) {
        print "Choose operation: " nl nl;

        print "1. List all books" nl;
        print "2. Add book(s)" nl;
        print "3. Remove book(s)" nl;
        print "4. Edit book(s)" nl;
        print "5. Exit" nl;

        print "> ";
        int answer;
        input answer;

        switch (answer) {
            case 1:
                print "All books: \n\n";
                printAllBooks();
                break;
            case 2:
                print "Add book(s)\n\n";
                addNewBook();
                break;
            case 3:
                print "Remove book(s)\n\n";
                removeBook();
                break;
            case 4:
                print "Edit book(s)";
                break;
            case 5:
                print "Exiting";
                run = false;
                break;
            default:
                print "Invalid operation";
                break;
        }
    }

    return 0;
}

void removeBook() {
    Asker::clearInputBuffer();
    std::string title = Asker::askString("Enter title of book you want to delete");
    BookResource::remove(title);
}

void addNewBook() {
    Asker::clearInputBuffer();
    std::string title = Asker::askString("Enter book's title");
    std::string author = Asker::askString("Enter book's author");
    int quantity = Asker::askInt("Enter quantity");

    BookResource::save(BookResource::create(title, author, quantity));
}

void printAllBooks() {
    auto books = BookCollection::load();

    for (auto & book : books) {
        book->toString();
        print "\n";
    }
}
