//
// Created by zimni on 7/25/2020.
//

#include "BookResource.h"
#include <fstream>
#include <cstring>

// Saves data about object in Storage/.txt
void BookResource::save(Book *book) {
    std::ofstream bookFile;
    const std::string &title = book->getTitle();
    bookFile.open("../Storage/" + title + ".txt");
    bookFile << "Title: " << title << std::endl
             << "Author: " << book->getAuthor() << std::endl
             << "Quantity: " << book->getQuantity();
    bookFile.close();

    std::ifstream readBookStorage("../Storage/bookStorage.txt");

    if (readBookStorage.is_open()) {
        std::string line;
        bool appendTitle = true;
        bool firstLine = true;

        do {
            if (line.empty() and firstLine) {
                appendTitle = true;
                firstLine = false;
            } else if (line == title){
                appendTitle = false;
                break;
            }
        } while (getline(readBookStorage, line));

        readBookStorage.close();

        if (appendTitle) {
            std::ofstream writeBookStorage;
            writeBookStorage.open("../Storage/bookStorage.txt", std::ios_base::app);
            writeBookStorage << title << std::endl;
            writeBookStorage.close();
        }
    }
}

// Creates object by loading .txt file from Storage folder by passed title
Book *BookResource::load(const std::string &title) {
    std::ifstream bookFile("../Storage/" + title + ".txt");
    std::string line;
    auto book = create();

    if (bookFile.is_open()) {
        int i = 0;
        while (getline(bookFile, line)) {
            if (i == 0) {
                book->setTitle(getValueFromLine(line));
            } else if (i == 1) {
                book->setAuthor(getValueFromLine(line));
            } else {
                book->setQuantity(std::stoi(getValueFromLine(line)));
            }
            i++;
        }
        bookFile.close();
    }
    return book;
}

std::string BookResource::getValueFromLine(const std::string &line) {
    std::string value = line.substr(line.find(':') + 2);
    return value;
}

// Creates new Book object and returns pointer to it
Book *BookResource::create(const std::string &title, const std::string &author, int quantity) {
    return new Book(title, author, quantity);
}

// Deletes relative .txt file from Storage and refreshes bookStorage.txt
void BookResource::remove(const std::string &title) {
    std::string stringPath = "../Storage/" + title + ".txt";
    char path[stringPath.length() + 1];
    strcpy(path, stringPath.c_str());

    std::remove(path);

    deleteFromBookStorage(title);
}

void BookResource::deleteFromBookStorage(const std::string &title) {
    std::ifstream readBookStorage("../Storage/bookStorage.txt");
    std::ofstream writeTempBookStorage;
    writeTempBookStorage.open("../Storage/tempBookStorage.txt", std::ios_base::app);

    std::string line;
    while (getline(readBookStorage, line)) {
        if (line != title) {
            writeTempBookStorage << line << std::endl;
        }
    }
    writeTempBookStorage.close();
    readBookStorage.close();

    refreshBookStorage();
}

void BookResource::refreshBookStorage() {
    std::remove("../Storage/bookStorage.txt");
    std::rename("../Storage/tempBookStorage.txt", "../Storage/bookStorage.txt");
}
