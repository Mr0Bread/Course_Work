//
// Created by zimni on 7/25/2020.
//

#pragma once
#ifndef COURSE_WORK_BOOKRESOURCE_H
#define COURSE_WORK_BOOKRESOURCE_H

#include <vector>
#include "../../Interfaces/ResourceModel/AbstractResourceModel.h"

class BookResource : public AbstractResourceModel {
public:
    std::string modelName;

    std::vector<std::string> fields;

    void save(AbstractModel *model) override;

    Book *load(const std::string &identifier) override;

    Book *create() override;

    void remove(const std::string &identifier) override;

public:

    explicit BookResource(const std::vector<std::string>& fields, const std::string &modelName = "Book");

private:
    std::string getValueFromLine(const std::string &line) override;

    void deleteFromBookStorage(const std::string &title) override;

    void replaceOldBookStorageWithNewOne() override;
};

#include "BookResource.cpp"

#endif //COURSE_WORK_BOOKRESOURCE_H
