//
// Created by zimni on 7/25/2020.
//

#include "Book.h"

Book::Book(const std::basic_string<char> &title,
           const std::basic_string<char> &author,
           int quantity) : title(title),
                           author(author),
                           quantity(quantity) {}

void Book::toString() {
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Quantity: " << this->quantity << std::endl;
}

Book::Book(const std::string &title,
           const std::string &author) : author(author),
                                        title(title) {}
