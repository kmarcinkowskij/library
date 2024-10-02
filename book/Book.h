//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <utility>

class Book {
protected:
    std::string ULID;
    std::string title;
    std::string author;
    int32_t release_date;
    bool availible;
public:

    Book(const std::string &v_ULID, const std::string &_title, const std::string &_author, const int32_t _release_date, bool const _availible):title(_title), author(_author), release_date(_release_date), availible(_availible), ULID(v_ULID){};
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getULID() const;
    [[nodiscard]] bool getAvailability() const;
    void setAvailability(const bool &_new);
    [[nodiscard]] int32_t getDate() const;
    virtual void showInfo();
    virtual ~Book()= default;
};



#endif //BOOK_H
