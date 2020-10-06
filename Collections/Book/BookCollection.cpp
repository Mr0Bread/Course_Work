//
// Created by zimni on 7/25/2020.
//

#include "BookCollection.h"
#include <fstream>
#include <vector>

std::vector<Book*> BookCollection::load() {
    std::ifstream readBookStorage("../Storage/bookStorage.txt");

    std::vector<Book*> books;

    if (readBookStorage.is_open()) {
        std::string title;
        while (getline(readBookStorage, title)) {
            books.push_back(BookResource::load(title));
        }
        readBookStorage.close();
    }

    return books;
}
