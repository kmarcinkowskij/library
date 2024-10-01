//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#include "Utilities.h"




Utilities::book_types Utilities::convert_string_to_book_types(const std::string &_string) {
    return {types_map.contains(_string) ? types_map.at(_string) : UNKNOWN_BOOK_TYPE};
}

Utilities::paperback_cover_type Utilities::convert_int_to_cover_types(const int &_int) {
    return {cover_map.contains(_int) ? cover_map.at(_int) : UNKNOWN_COVER};
}

void Utilities::change_line_in_file(const int32_t &_line_number, const std::string &_file_dir, const std::string &_new_line) {
    std::ifstream input_file(_file_dir);
    std::ofstream target_file("temp.csv");
    int32_t counter = 0;
    std::string line;
    while(std::getline(input_file, line)) {
        if(counter == _line_number) {
            target_file << _new_line << "\n";
            counter++;
        } else {
            target_file << line << "\n";
            counter++;
        }
    }

    std::remove(_file_dir.c_str());
    std::rename("temp.csv", _file_dir.c_str());
}

void Utilities::remove_line_in_file(const int &_line_number, const std::string &_file_dir) {
    std::ifstream input_file(_file_dir);
    std::ofstream target_file("temp.csv");
    int32_t counter = 0;
    std::string line;
    while(std::getline(input_file, line)) {
        if(counter == _line_number) {
            counter++;
        } else {
            target_file << line << "\n";
            counter++;
        }
    }

    std::remove(_file_dir.c_str());
    std::rename("temp.csv", _file_dir.c_str());
}

int32_t Utilities::find_book_with_ULID(const std::string &v_ulid) {
    std::ifstream input("books.csv");
    std::string line;
    std::array<std::string, 8>book_data;
    std::tuple<std::string, int16_t>data;
    int16_t line_iter = 0;
    int32_t line_counter = 0;
    int32_t counter = 0;
    while(std::getline(input, line)) {
        for(int i = 0; i < 8; i++) {
            std::tuple<std::string, int16_t> data = Utilities::get_string_from_index_until_delimiter(line, counter, ',');
            book_data[i] = std::get<0>(data);
            counter = std::get<1>(data)+(int16_t)1;

        }
        if(book_data[1] == v_ulid) {
            return line_counter;
        }

        line_counter++;
        counter = 0;
    }
    return -1;
}


std::tuple<std::string, int16_t> Utilities::
get_string_from_index_until_delimiter(const std::string &_string, const int16_t &index, const char &_delimiter) {
    std::string final;
    int16_t counter = index;
    while(_string[counter] != _delimiter && _string[counter] != '\n') {
        final += _string[counter];
        counter++;
    }
    return {std::tuple(final, counter)};
}
