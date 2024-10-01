//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#ifndef PAPERBACK_H
#define PAPERBACK_H
#include "Book.h"
#include "../utils/Utilities.h"


class Paperback final: public Book {
protected:
    int32_t pages;
    Utilities::paperback_cover_type cover;
public:
    Paperback(const std::string &v_ULID,const std::string &_title, const std::string &_author, const int32_t &_release_date, const int32_t &_pages, const Utilities::paperback_cover_type &_cover_type, const bool &_availible): Book(v_ULID, _title,_author,_release_date, _availible), pages(_pages), cover(_cover_type){};
    [[nodiscard]] int32_t getPages() const;
    [[nodiscard]] Utilities::paperback_cover_type getCover() const;
    void showInfo() override;
};



#endif //PAPERBACK_H
