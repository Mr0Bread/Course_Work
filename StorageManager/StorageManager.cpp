//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#include "StorageManager.h"
#include "../Helpers/StringBuilder/StringBuilder.h"

StorageManager::StorageManager(const std::string& modelToManage) : modelToManage(modelToManage) {}

void StorageManager::save(AbstractModel* model, const std::string& data) {
    std::ofstream modelResourceFile;
    int id = model->getId();

    std::string stringId = id == -1 ? std::to_string(this->nextId) : std::to_string(id);

    auto stringBuilder = new StringBuilder(data);

    modelResourceFile.open(this->storagePath + this->modelToManage + "/" + stringId + ".txt");

    if (modelResourceFile.is_open()) {
        stringBuilder->addLineToStart("ID: " + stringId);
        modelResourceFile << stringBuilder->getString() << "\n\n";
    }

    modelResourceFile.close();
}

void StorageManager::updateModelFile() {

}

void StorageManager::updateStorage() {

}
