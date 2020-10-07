//
// Created by Vladislavs Zimnikovs on 07/10/2020.
//

#include "StringBuilder.h"

void StringBuilder::addLine(const std::string& line) {
    this->data += line + "\n";
}

void StringBuilder::addText(const std::string& text) {
    this->data += text;
}

const std::string& StringBuilder::getString() const {
    return data;
}

StringBuilder::StringBuilder(const std::string& data) {
    this->data = data;
}

void StringBuilder::addLineToStart(const std::string& text) {
    this->data = text + "\n" + this->data;
}
