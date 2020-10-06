//
// Created by zimni on 7/25/2020.
//

#include "Book.h"

Book::Book(
        const std::basic_string<char> &title,
        const std::basic_string<char> &author,
        int quantity
) : title(title),
    author(author),
    quantity(quantity) {}

void Book::toString() {
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Quantity: " << this->quantity << std::endl;
}

Book::Book() = default;

Book::Book(
        const std::string &title,
        const std::string &author
) : author(author),
    title(title) {}

const std::string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string &title) {
    Book::title = title;
}

const std::string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const std::string &author) {
    Book::author = author;
}

int Book::getQuantity() const {
    return quantity;
}

void Book::setQuantity(int quantity) {
    Book::quantity = quantity;
}
