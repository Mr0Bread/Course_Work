//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#include "StorageManager.h"

StorageManager::StorageManager(const std::string& modelToManage) : modelToManage(modelToManage) {}

void StorageManager::save(AbstractModel* model, const std::vector<std::string>& fields, const std::string& data) {
    std::ofstream modelResourceFile;
    int id = model->getId();

    if (id == -1) {
        modelResourceFile.open(this->storagePath + this->modelToManage + "/" + std::to_string(this->nextId) + ".txt");

        modelResourceFile.close();
        return;
    }

    modelResourceFile.open(this->storagePath + this->modelToManage + "/" + std::to_string(id) + ".txt");

    modelResourceFile.close();
}

void StorageManager::updateModelFile() {

}

void StorageManager::updateStorage() {

}
