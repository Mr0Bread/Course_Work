//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#pragma once
#ifndef COURSE_WORK_STORAGEMANAGEMENT_H
#define COURSE_WORK_STORAGEMANAGEMENT_H

#include <vector>
#include <map>
#include "../StorageManager/StorageManager.h"

class StorageManagement {
private:
    StorageManagement() = default;

    static std::map<std::string, StorageManager*> storeManagers;

public:
    static void initManagement();

    static StorageManager* getStoreManagerByModelName(const std::string &modelName);
};

#include "StorageManagement.cpp"

#endif //COURSE_WORK_STORAGEMANAGEMENT_H
