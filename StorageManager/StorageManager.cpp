//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#include "StorageManager.h"

StorageManager::StorageManager(const std::string &modelToManage) : modelToManage(modelToManage) {}

void StorageManager::save(AbstractModel* model) {
    std::ofstream modelResourceFile;

    modelResourceFile.open(this->storagePath + this->modelToManage + "/" + ".txt");

    modelResourceFile.close();
}
