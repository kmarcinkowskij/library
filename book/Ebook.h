//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#ifndef EBOOK_H
#define EBOOK_H
#include "Book.h"

class Ebook final : public Book {
protected:
    int32_t filesize;
    std::string filetype;
public:
    Ebook(const std::string &v_ULID,const std::string &_title, const std::string &_author, const int32_t &_release_date, const int32_t &_filesize, const std::string &_filetype, const bool &_availible): Book(v_ULID,_title,_author,_release_date, _availible), filesize(_filesize), filetype(_filetype){};
    [[nodiscard]] int32_t getFilesize() const;
    [[nodiscard]] std::string getFiletype() const;
    void showInfo() override;
};



#endif //EBOOK_H
