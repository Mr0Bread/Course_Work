//
// Created by zimni on 7/25/2020.
//

#pragma once
#ifndef COURSE_WORK_BOOK_H
#define COURSE_WORK_BOOK_H


class Book {
    std::string title;
    std::string author;
    int quantity = 0;

public:
    Book(const std::string &title, const std::string &author, int quantity);
    Book(const std::string &title, const std::string &author);

    void toString();
};

#endif //COURSE_WORK_BOOK_H
