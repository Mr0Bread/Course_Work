//
// Created by zimni on 7/25/2020.
//

#ifndef COURSE_WORK_BOOKRESOURCE_H
#define COURSE_WORK_BOOKRESOURCE_H

class BookResource {
public:
    void save(Book *book);

    Book *load(const std::string &title);

private:
    static std::string getValueFromLine(const std::string &line);
};

#include "BookResource.cpp"

#endif //COURSE_WORK_BOOKRESOURCE_H
