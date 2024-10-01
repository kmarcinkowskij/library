//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#include "Audiobook.h"

int32_t Audiobook::getLength() {
    return this->length;
}

std::string Audiobook::getNarrator() {
    return this->narrator;
}

void Audiobook::showInfo() {
    std::cout <<"ULID: "<<getULID()<<"\tTitle: "<<getTitle()<<"\tAuthor: "<<getAuthor()<<"\treleased in: "<<getDate()<<"\tlength: "<<getLength()<<"\tnarrator: "<<getNarrator()<<"\tavailible: ";
    if(this->getAvailability() == true) {
        std::cout << "\x1B[32myes\n\x1B[0m";
        return;
    }
    std::cout << "\x1B[31mno\n\x1B[0m";
}
