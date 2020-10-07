//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#pragma once
#ifndef COURSE_WORK_STORAGEMANAGER_H
#define COURSE_WORK_STORAGEMANAGER_H

class StorageManager {
public:
    StorageManager(const std::string &modelToManage);

    void save(AbstractModel* model, const std::string& data);

    void updateModelFile();

    void updateStorage();

private:
    std::string modelToManage;
    std::string storagePath = "../Storage/";
    int nextId = 0;
};

#include "StorageManager.cpp"

#endif //COURSE_WORK_STORAGEMANAGER_H
