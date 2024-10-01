//
// Created by Konrad Marcinkowski on 01/10/2024.
//

#ifndef READER_H
#define READER_H

#include <iostream>
#include <string>


class Reader {
protected:
    int32_t number_id;
    std::string name;
public:
    Reader(const int32_t &_number_id, const std::string &_name):number_id(_number_id),name(_name){};
    [[nodiscard]] int32_t getReaderID() const;
    [[nodiscard]] std::string getReaderName() const;
    void showInfo() const;
};

#endif //READER_H
