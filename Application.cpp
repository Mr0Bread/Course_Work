//
// Created by Vladislavs Zimnikovs on 01/11/2020.
//

#include "Application.h"

void Application::run() {
    Application::isRunning = true;

    while (Application::isRunning) {
        std::cout << "Enter command to proceed\n";
        std::string command;
        std::cin >> command;

        Application::isRunning = false;
    }
}

void Application::init() {
    Application::isRunning = false;
}