#include <iostream>
#include "Models/Book.cpp"
#include "ResourceModels/BookResource.cpp"

#define print std::cout <<
#define nl << std::endl
#define input std::cin >>

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

        auto book = new Book("GoT", "George Martin");
        book->toString();

        switch (answer) {
            case 1:
                print "All books";
                break;
            case 2:
                run = false;
                break;
            default:
                print "Invalid operation";
                break;
        }
    }

    return 0;
}
