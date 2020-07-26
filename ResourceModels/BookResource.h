//
// Created by zimni on 7/25/2020.
//

#pragma once
#ifndef COURSE_WORK_BOOKRESOURCE_H
#define COURSE_WORK_BOOKRESOURCE_H

class BookResource {
public:
    static void save(Book *book);

    static Book* load(const std::string &title);

    static Book* create(const std::string &title = "Na", const std::string &author = "Na", int quantity = 0);

    static void remove(const std::string &title);

private:
    static std::string getValueFromLine(const std::string &line);
    static void deleteFromBookStorage(const std::string &title);
    static void refreshBookStorage();
};

#include "BookResource.cpp"

#endif //COURSE_WORK_BOOKRESOURCE_H
