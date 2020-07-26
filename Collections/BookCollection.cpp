//
// Created by zimni on 7/25/2020.
//

#include "BookCollection.h"
#include <fstream>

Book *BookCollection::load() {
    std::ifstream readBookStorage("../Storage/bookStorage.txt");

    if (readBookStorage.is_open()) {
        std::string line;
        std::string titles;
        int arraySize = 0;
        while (getline(readBookStorage, line)) {
            titles.append(line + ",");
            arraySize++;
        }
        std::cout << titles;
    }
}
