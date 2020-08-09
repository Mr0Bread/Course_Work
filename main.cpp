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

void editBook();

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
                print "Add book\n\n";
                addNewBook();
                break;
            case 3:
                print "Remove book\n\n";
                removeBook();
                break;
            case 4:
                print "Edit book";
                editBook();
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

void editBook() {
    Asker::clearInputBuffer();
    std::string title = Asker::askString("Enter title of book which information you want to edit");
    auto bookToEdit = BookResource::load(title);
    auto oldTitle = bookToEdit->getTitle();
    char options[2]{'y', 'n'};

    if (Asker::askChar("Do you want to change title? y/n", options) == 'y') {
        std::string newTitle = Asker::askString("Enter new title");
        while (BookResource::setNewTitle(title, bookToEdit) == 0) {
            if (Asker::askChar("Do you want to try another title? y/n", options) == 'n') {
                break;
            }
        }
    }

    if (Asker::askChar("Do you want to change author? y/n", options) == 'y') {
        std::string newAuthor = Asker::askString("Enter new author");
        bookToEdit->setAuthor(newAuthor);
    }

    if (Asker::askChar("Do you want to change quantity? y/n", options) == 'y') {
        int newQuantity = Asker::askInt("Enter new quantity");
        bookToEdit->setQuantity(newQuantity);
    }

/* <---------------- TODO --------------------------------> */
    BookResource::save(bookToEdit);

    if (bookToEdit->getTitle() != oldTitle) {
        BookResource::replaceOldBookFileWithNewOne(bookToEdit->getTitle());
    }
/* <------------------------------------------------------> */

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

    for (auto &book : books) {
        book->toString();
        print "\n";
    }
}
