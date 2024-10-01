//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#include "Paperback.h"

int32_t Paperback::getPages() const {
    return this->pages;
}

Utilities::paperback_cover_type Paperback::getCover() const {
    return this->cover;
}

void Paperback::showInfo() {
    std::cout <<"ULID: "<<getULID()<<"\tTitle: "<<getTitle()<<"\tAuthor: "<<getAuthor()<<"\treleased in: "<<getDate()<<"\tpages: "<<getPages()<<"\tcoverType: "<<getCover()<<"\tavailible: ";
    if(this->getAvailability() == true) {
        std::cout << "\x1B[32myes\n\x1B[0m";
        return;
    }
    std::cout << "\x1B[31mno\n\x1B[0m";
}
