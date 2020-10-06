//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#include "StorageManagement.h"
#include <filesystem>

void StorageManagement::initManagement() {
    std::string path = "../Models";

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string filePath = entry.path();
        auto modelName = filePath.substr(10);

        auto storageManager = new StorageManager(modelName);
        StorageManagement::storeManagers.push_back(storageManager);
    }
}
