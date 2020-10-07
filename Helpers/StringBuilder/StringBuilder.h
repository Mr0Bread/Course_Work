//
// Created by Vladislavs Zimnikovs on 07/10/2020.
//

#pragma once
#ifndef COURSE_WORK_STRINGBUILDER_H
#define COURSE_WORK_STRINGBUILDER_H

class StringBuilder {
public:
    void addLine(const std::string& line);

    void addText(const std::string& text);

    void addLineToStart(const std::string& text);

    const std::string& getString() const;

    StringBuilder(const std::string& data = "");

private:
    std::string data;
};

#include "StringBuilder.cpp"

#endif //COURSE_WORK_STRINGBUILDER_H
