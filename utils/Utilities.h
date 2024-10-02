//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#ifndef UTILITIES_H
#define UTILITIES_H
#include <map>
#include <string>
#include <iostream>
#include <fstream>


class Utilities {
public:
    enum paperback_cover_type { HARD, SOFT, UNKNOWN_COVER };
    enum book_types { AUDIOBOOK, EBOOK, PAPERBACK, UNKNOWN_BOOK_TYPE};
    inline static const std::map<std::string,book_types> types_map{{"audiobook",AUDIOBOOK}, {"ebook",EBOOK}, {"paperback",PAPERBACK}};
    inline static const std::map<int,paperback_cover_type> cover_map{{0,HARD}, {1,SOFT}};
    inline static const std::map<std::string,bool> choice_map{{"y",true}, {"yes",true}, {"t", true}, {"tak", true}, {"1", true}, {"n", false}, {"no", false}, {"nie", false}, {"0", false}};
    Utilities()= default;

    static book_types convert_string_to_book_types(const std::string &_string);
    static paperback_cover_type convert_int_to_cover_types(const int &_int);

    static void change_line_in_file(const int &_line_number, const std::string &_file_dir, const std::string &_new_line);
    static void remove_line_in_file(const int &_line_number, const std::string &_file_dir);

    static int32_t find_book_with_ULID(const std::string &v_ulid);

    static std::tuple<std::string, int16_t> get_string_from_index_until_delimiter(const std::string &_string, const int16_t &index, const char &_delimiter);
};



#endif //UTILITIES_H
