//
// Created by Vladislavs Zimnikovs on 06/10/2020.
//

#include <string>
#include "AbstractResourceModel.h"

AbstractResourceModel::AbstractResourceModel(const std::string& identifierField) : identifierField(identifierField) {}

const std::string& AbstractResourceModel::getIdentifierField() const {
    return identifierField;
}
