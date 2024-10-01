//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "book/Book.h"
#include "reader/Reader.h"


class Library {
protected:
    std::vector<std::unique_ptr<Book>> books;
    std::vector<Reader> readers;
    std::vector<std::tuple<std::string, int32_t>> rented_books;
public:
    void getBooks() const;
    void getReaders() const;
    void getRented() const;

    void addBook(std::unique_ptr<Book> _book);
    void addReader(const int32_t &_id, const std::string &_name);
    void addRented(const std::string &v_ULID, const int32_t &_reader_id);

    void readBooks();
    void readReaders();
    void readRented();

    void changeRented(const std::string &v_ULID, const int32_t &_reader_id);
    void removeRented(const std::string &v_ULID);
    void resetRented();

};



#endif //LIBRARY_H
