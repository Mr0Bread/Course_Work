//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#include "StorageManagement.h"
#include <filesystem>

void StorageManagement::initManagement() {
    std::string path = "../Models";

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string filePath = entry.path();
        auto modelName = filePath.substr(filePath.rfind('/'));

        auto storageManager = new StorageManager(modelName);
        StorageManagement::storeManagers.insert(std::pair<std::string, StorageManager*>(modelName, storageManager));
    }
}

StorageManager* StorageManagement::getStoreManagerByModelName(const std::string& modelName) {
    return StorageManagement::storeManagers.at(modelName);
}
