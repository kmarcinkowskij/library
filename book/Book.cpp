//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#include "Book.h"

std::string Book::getTitle() const {
    return this->title;
}

std::string Book::getAuthor() const {
    return this->author;
}

std::string Book::getULID() const {
    return this->ULID;
}

bool Book::getAvailability() const{
    return this->availible;
}

void Book::setAvailability(const bool &_new) {
    this->availible = _new;
}

int32_t Book::getDate() const {
    return this->release_date;
}

void Book::showInfo() {
    std::cout <<"Title: "<<getTitle()<<"\tAuthor: "<<getAuthor()<<"\treleased in: "<<getDate()<<"\tavailible: ";
    if(this->availible) {
        std::cout << "\x1B[32myes\n\x1B[0m";
        return;
    }
    std::cout << "\x1B[31mno\n\x1B[0m";
}
