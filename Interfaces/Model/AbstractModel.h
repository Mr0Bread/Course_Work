//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#pragma once
#ifndef COURSE_WORK_ABSTRACTMODEL_H
#define COURSE_WORK_ABSTRACTMODEL_H

class AbstractModel {
protected:
    int id;

    int getId();

    void setId(int id);
};

#include "AbstractModel.cpp"

#endif //COURSE_WORK_ABSTRACTMODEL_H
