//
// Created by zimni on 7/25/2020.
//

#pragma once
#ifndef COURSE_WORK_BOOKCOLLECTION_H
#define COURSE_WORK_BOOKCOLLECTION_H
#include <vector>

class BookCollection {
public:
    static std::vector<Book*> load();
};

#include "BookCollection.cpp"
#endif //COURSE_WORK_BOOKCOLLECTION_H
