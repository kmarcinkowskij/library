//
// Created by Konrad Marcinkowski on 01/10/2024.
//

#include "Reader.h"

int32_t Reader::getReaderID() const {
    return this->number_id;
}

std::string Reader::getReaderName() const {
    return this->name;
}

void Reader::showInfo() const {
    std::cout << "reader id: " << getReaderID() << ", reader name: " << getReaderName() << "\n";
}