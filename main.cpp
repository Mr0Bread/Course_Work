#include <iostream>
#include "Model/Book/Book.cpp"
#include "Model/Author/Author.cpp"
#include "Application.cpp"
#include "fstream"

#define print std::cout <<
#define nl << std::endl
#define input std::cin >>

void add();
void remove();

void addBook();

void addAuthor();

void removeBook();

void removeAuthor();

void showOne();

void showBook();

void showAuthor();

void showAll();

void showAllBooks();

void showAllAuthors();

int main() {
    Application::init();
    print "Welcome to \"ABC\" Library inventory system";
    Application::run();
    return 0;
    auto run = true;

    while (run) {
        print "Enter command to execute:\n";
        print "1. Add\n2. Delete\n3. Exit";

        int answer;
        input answer;

        switch (answer) {
            case 1:
                add();

                break;
            case 2:
                remove();

                break;
            case 4:
                showOne();

                break;
            case 5:
                showAll();

                break;
            case 3:
                run = false;

                break;
            default:
                print "Invalid input";

                break;
        }
    }

    return 0;
}

void showAll() {
    print "Choose what records you want to show:\n\n1. Books\n 2. Authors\n 3. Return\n\n";

    int answer;
    if (!(input answer)) {
        print "Invalid input";
        return;
    }

    switch (answer) {
        case 1:
            showAllBooks();

            break;
        case 2:
            showAllAuthors();

            break;
        case 3:
            return;
        default:
            print "Invalid command\n";
            return;
    }
}

void showAllAuthors() {

}

void showAllBooks() {

}

void showOne() {
    print "Choose what you want to show:\n\n1. Book\n 2. Author\n 3. Return\n\n";

    int answer;
    if (!(input answer)) {
        print "Invalid input\n";
        return;
    }

    switch (answer) {
        case 1:
            showBook();

            break;
        case 2:
            showAuthor();

            break;
        case 3:
            return;
        default:
            print "Invalid command";
            return;
    }
}

void showAuthor() {

}

void showBook() {

}

void add() {
    print "Choose what you want to add:\n\n1. Book\n2. Author\n3. Return\n\n";

    int answer;
    input answer;

    switch (answer) {
        case 1:
            addBook();

            break;
        case 2:
            addAuthor();

            break;
        case 3:
            return;
        default:
            print "Invalid input";
            break;
    }
}

void addAuthor() {

}

void addBook() {
    Book book{};

    print "Enter title of book(should be no more than 100 symbols)\n";
    std::string title;
    input title;

    if (title.length() > 100) {
        print "Length of title is too large, terminating\n";
        return;
    }

    print "Enter language of book(should be no more than 20 symbols)\n";
    std::string language;
    input language;

    if (title.length() > 20) {
        print "Length of language is too large, terminating\n";
        return;
    }

    print "Enter publish year(should be only integers)\n";
    int publishYear;

    if (!(input publishYear)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        print "Invalid input, terminating\n";
        return;
    }

    print "Enter ID of author of this book\n";
    int authorID;

    if (!(input authorID)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        print "Invalid input, terminating\n";
        return;
    }

    book.setTitle(title);
    book.setLanguage(language);
    book.setAuthorId(authorID);
    book.setPublishYear(publishYear);

    std::ofstream booksStorage("./Storage/books.dat", std::ios::out | std::ios::binary);

    booksStorage.write((char *) &book, sizeof(book));

    if (!(booksStorage.good())) {
        print "Error occurred while writing to binary file!\n";
        return;
    }
}

void remove() {
    print "Choose what you want to remove:\n\n1. Book\n2. Author\n3. Return\n\n";

    int answer;
    input answer;

    switch (answer) {
        case 1:
            removeBook();

            break;
        case 2:
            removeAuthor();

            break;
        case 3:
            return;
        default:
            print "Invalid input";
            break;
    }
}

void removeAuthor() {

}

void removeBook() {

}
