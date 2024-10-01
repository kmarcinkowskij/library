//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"



class Audiobook : public Book {
protected:
    int32_t length;
    std::string narrator;
public:
    Audiobook(const std::string &v_ULID, const std::string &_title, const std::string &_author,const int32_t &_release_date, const int32_t &_length, const std::string &_narrator, bool _availible): Book(v_ULID, _title,_author,_release_date, _availible), length(_length), narrator(_narrator){};
    int32_t getLength();
    std::string getNarrator();
    void showInfo() override;
};



#endif //AUDIOBOOK_H
