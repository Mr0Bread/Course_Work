//
// Created by Mr0Bread on 7/26/2020.
//

#ifndef COURSE_WORK_ASKER_H
#define COURSE_WORK_ASKER_H

namespace Asker {
    void clearInputBuffer() {
        std::cin.clear();
        while(std::cin.get() != '\n');
    }

    std::string askString(const std::string &message) {
        std::cout << message << "\n> ";
        std::string input;

        while (!getline(std::cin, input)) {
            clearInputBuffer();
            std::cout << "Invalid input; please re-enter.\n";
        }

        return input;
    }

    int askInt(const std::string &message) {
        std::cout << message << "\n> ";
        int input;

        while (!(std::cin >> input)) {
            clearInputBuffer();
            std::cout << "Invalid input; please re-enter.\n";
        }

        return input;
    }

}

#endif //COURSE_WORK_ASKER_H
