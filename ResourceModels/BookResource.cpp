//
// Created by zimni on 7/25/2020.
//

#include "BookResource.h"
#include <fstream>
#include <map>

void BookResource::save(Book *book) {
    std::ofstream bookFile;
    const std::string &title = book->getTitle();
    bookFile.open("../Storage/" + title + ".txt");
    bookFile << "Title: " << title << std::endl
             << "Author: " << book->getAuthor() << std::endl
             << "Quantity: " << book->getQuantity();
    bookFile.close();
}

Book *BookResource::load(const std::string &title) {
    std::ifstream bookFile("../Storage/" + title + ".txt");
    std::string line;
    auto book = new Book();

    if (bookFile.is_open()) {
        for (int i = 0; getline(bookFile, line); i++) {
            if (i == 0) {
                book->setTitle(getValueFromLine(line));
            } else if (i == 1) {
                book->setAuthor(getValueFromLine(line));
            } else {
                book->setQuantity(std::stoi(getValueFromLine(line)));
            }
        }
        bookFile.close();
    }

    return book;
}

std::string BookResource::getValueFromLine(const std::string &line) {
    std::string value = line.substr(line.find(':'));
    return value;
}
