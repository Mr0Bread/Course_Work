//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#pragma once
#ifndef COURSE_WORK_ABSTRACTRESOURCEMODEL_H
#define COURSE_WORK_ABSTRACTRESOURCEMODEL_H

class AbstractResourceModel {
protected:
    std::string identifierField;

    AbstractResourceModel(const std::string &identifierField);

    virtual void save(AbstractModel *model) = 0;

    virtual AbstractModel *load(const std::string &identifier) = 0;

    virtual AbstractModel *create() = 0;

    virtual void remove(const std::string &identifier) = 0;

    std::string modelName;

private:
    virtual std::string getValueFromLine(const std::string &line) = 0;

    virtual void deleteFromBookStorage(const std::string &title) = 0;

    virtual void replaceOldBookStorageWithNewOne() = 0;
};

#include "AbstractResourceModel.cpp"

#endif //COURSE_WORK_ABSTRACTRESOURCEMODEL_H
