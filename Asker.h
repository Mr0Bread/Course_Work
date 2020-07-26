//
// Created by Mr0Bread on 7/26/2020.
//

#ifndef COURSE_WORK_ASKER_H
#define COURSE_WORK_ASKER_H

namespace Asker {
    std::string askString(const std::string &message) {
        std::cout << message << "\n> ";
        std::string input;

        while (!getline(std::cin, input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input; please re-enter.\n";
        }

        return input;
    }

    int askInt(const std::string &message) {
        std::cout << message << "\n> ";
        int input;

        while (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input; please re-enter.\n";
        }

        return input;
    }
}

#endif //COURSE_WORK_ASKER_H
