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
    void getRented();

    void addBook(std::unique_ptr<Book> _book);
    void addReader(const int32_t &_id, const std::string &_name);
    void addRented(const std::string &v_ULID, const int32_t &_reader_id);

    void init();

    void readBooks();
    void readReaders();
    void readRented();

    void changeRented(const std::string &v_ULID, const int32_t &_reader_id);
    void removeRented(const std::string &v_ULID);
    void resetRented();
    void printToRented(const std::string &v_ULID, const char &_current_state);

    [[nodiscard]] std::string get_reader_name_with_ID(const int32_t &v_id) const;
    [[nodiscard]] std::tuple<int32_t, std::string> find_book_with_ULID(const std::string &v_ulid) const;
    [[nodiscard]] std::int32_t find_book_in_rented(const std::string &v_ulid) const;
    std::int32_t check_book_availibility_ULID(const std::string &v_ulid) const;

};



#endif //LIBRARY_H
