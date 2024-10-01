//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#include "Ebook.h"

int32_t Ebook::getFilesize() const{
    return this->filesize;
}

std::string Ebook::getFiletype() const{
    return this->filetype;
}

void Ebook::showInfo() {
    std::cout <<"ULID: "<<getULID()<<"\tTitle: "<<getTitle()<<"\tAuthor: "<<getAuthor()<<"\treleased in: "<<getDate()<<"\tfilesize: "<<getFilesize()<<"\tfiletype: "<<getFiletype()<<"\tavailible: ";
    if(this->getAvailability() == true) {
        std::cout << "\x1B[32myes\n\x1B[0m";
        return;
    }
    std::cout << "\x1B[31mno\n\x1B[0m";
}
