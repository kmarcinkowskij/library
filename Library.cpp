//
// Created by Konrad Marcinkowski on 30/09/2024.
//

#include "Library.h"
#include <fstream>

#include "book/Audiobook.h"
#include "book/Ebook.h"
#include "book/Paperback.h"
#include "utils/Utilities.h"

void Library::getBooks() const{
    for(const std::unique_ptr<Book> &book: this->books) {
        book->showInfo();
    }
}

void Library::getReaders() const {
    for (const Reader &reader: this->readers) {
        reader.showInfo();
    }
}

void Library::getRented() {
    for(auto i: rented_books) {
        std::cout <<this->get_reader_name_with_ID(std::get<1>(i)) << " (" << std::get<1>(i) << ")" << " rented " << std::get<1>(this->find_book_with_ULID(std::get<0>(i))) << " (" << std::get<0>(i) << ")\n";
    }
}
void Library::printToRented(const std::string &v_ULID, const char &_current_state) {
    const int32_t line_number = std::get<0>(this->find_book_with_ULID(v_ULID));
    int32_t counter = 0;
    std::ifstream input("books.csv");
    std::string line;
    while(std::getline(input, line)) {
        // std::cout << "book number: " << line_number << ", current number: " << counter <<  ", line: "<< line<<"\n";
        if(counter == line_number && line[static_cast<int32_t>(line.size())-2] != _current_state) {
            // std::cout << "found the correct book: " << line<<"\n";
            std::string new_line = line;
            new_line[static_cast<int32_t>(line.size())-2] = _current_state;
            Utilities::change_line_in_file(counter, "books.csv", new_line);
        }
        counter++;
    }
    input.close();
}
void Library::addRented(const std::string &v_ULID, const int32_t &_reader_id) {
    for(auto i: this->rented_books) {
        if(std::get<0>(i) == v_ULID) {
            return;
        }
    }
    std::ofstream rented("rented_books.csv", std::ios_base::app);
    printToRented(v_ULID, '0');
    rented << v_ULID + ',' + std::to_string(_reader_id) + '\n';
    rented.close();

    for(std::tuple<std::string, int32_t> &rented_book: this->rented_books) {
        if(std::get<0>(rented_book) == v_ULID) {
            std::get<1>(rented_book) = _reader_id;
            return;
        }
    }

    for(const std::unique_ptr<Book> &book: this->books) {
        if(book->getULID() == v_ULID) {
            book->setAvailability(true);
        }
    }
    rented.close();
    rented_books.emplace_back(v_ULID, _reader_id);
}

void Library::init() {
    this->readBooks();
    this->readReaders();
    this->readRented();
}

void Library::readRented() {
    std::ifstream input_file("rented_books.csv");
    std::string line;
    int16_t counter = 0;
    std::array<std::string, 2> rented_data;
    if(!input_file.is_open()) {
        std::cerr << "\ncould not opend input file!\n";
    }

    while(std::getline(input_file, line)) {
        for(int i = 0; i < 2; i++) {
            std::tuple<std::string, int16_t> data = Utilities::get_string_from_index_until_delimiter(line, counter, ',');
            rented_data[i] = std::get<0>(data);
            counter = std::get<1>(data)+(int16_t)1;
        }
        this->rented_books.emplace_back(rented_data[0], stoi(rented_data[1]));
        counter = 0;
        printToRented(rented_data[0], '0');
    }

    input_file.close();


}

void Library::changeRented(const std::string &v_ULID, const int32_t &_reader_id) {
    int counter = 0;
    for(auto i: this->rented_books) {
        if(std::get<0>(i) == v_ULID) {
            std::get<1>(i) = _reader_id;
            Utilities::change_line_in_file(counter, "rented_books.csv", v_ULID + ',' + std::to_string(_reader_id));
        }
        counter++;
    }

}

void Library::removeRented(const std::string &v_ULID) {
    int32_t counter = 0;
    for(auto i: this->rented_books) {
        if(std::get<0>(i) == v_ULID) {
            this->rented_books.erase(rented_books.begin() + counter);\
            Utilities::remove_line_in_file(counter, "rented_books.csv");
            printToRented(v_ULID, '1');
        }
        counter++;
    }
}

void Library::resetRented() {
    for(const std::unique_ptr<Book> &book: this->books) {
        printToRented(book->getULID(), '1');
        book->setAvailability(true);
    }
    this->rented_books.clear();
    Utilities::clear_file("rented_books.csv");

}

std::string Library::get_reader_name_with_ID(const int32_t &v_id) const {
        for(const Reader& reader: this->readers) {
            if(reader.getReaderID() == v_id) {
                return reader.getReaderName();
            }
        }
        return "404";
}

std::tuple<int32_t, std::string> Library::find_book_with_ULID(const std::string &v_ulid) const {
    int32_t counter = 0;
    try {
        for(const std::unique_ptr<Book> &book: this->books) {
            if(book->getULID() == v_ulid) {
                return {counter, book->getTitle()};
            }
            counter++;
        }
    }catch(int err_code) {
        return {err_code, std::to_string(err_code)};
    }
    return {-1, "null"};
}

std::int32_t Library::find_book_in_rented(const std::string &v_ulid) const {
    int32_t counter = 0;
    for(const std::tuple<std::string, int32_t> &rented: this->rented_books) {
        if(std::get<0>(rented) == v_ulid) {
            return counter;
        }
        counter++;
    }
    return -1;
}

std::int32_t Library::check_book_availibility_ULID(const std::string &v_ulid) const {
    for(const std::unique_ptr<Book> &book: this->books) {
        if(book->getULID() == v_ulid) {
            return book->getAvailability();
        }
    }
    return 404;
}


void Library::readReaders() {
    std::ifstream input_file("readers.csv");
    std::string line;
    int16_t counter = 0;
    std::array<std::string, 2> reader_data;
    if(!input_file.is_open()) {
        std::cerr << "\ncould not opend input file!\n";
    }

    while(std::getline(input_file, line)) {
        for(int i = 0; i < 2; i++) {
            std::tuple<std::string, int16_t> data = Utilities::get_string_from_index_until_delimiter(line, counter, ',');
            reader_data[i] = std::get<0>(data);
            counter = std::get<1>(data)+(int16_t)1;
        }
        this->addReader(stoi(reader_data[0]), reader_data[1]);
        counter = 0;
    }
    input_file.close();
}

void Library::addBook(std::unique_ptr<Book> _book) {
    this->books.push_back(std::move(_book));
}

void Library::addReader(const int32_t &_id, const std::string &_name) {
    this->readers.emplace_back(_id, _name);
}

void Library::readBooks() {
    std::ifstream input_file("books.csv");
    std::string line;
    int16_t counter = 0;
    std::array<std::string, 8> book_data;
    if(!input_file.is_open()) {
        std::cerr << "\ncould not opend input file!\n";
    }

    while(std::getline(input_file, line)) {
        for(int i = 0; i < 8; i++) {
            std::tuple<std::string, int16_t> data = Utilities::get_string_from_index_until_delimiter(line, counter, ',');
            book_data[i] = std::get<0>(data);
            counter = std::get<1>(data)+(int16_t)1;

        }
        switch(Utilities::convert_string_to_book_types(book_data[0])) {
            case Utilities::book_types::PAPERBACK: {
                this->addBook(std::make_unique<Paperback>(*new Paperback(book_data[1], book_data[2], book_data[3],stoi(book_data[4]), stoi(book_data[5]), Utilities::convert_int_to_cover_types(stoi(book_data[6])), stoi(book_data[7]))));
                break;
            }
            case Utilities::book_types::EBOOK: {
                this->addBook(std::make_unique<Ebook>(*new Ebook(book_data[1], book_data[2], book_data[3], stoi(book_data[4]), stoi(book_data[5]), book_data[6], stoi(book_data[7]))));
                break;
            }
            case Utilities::book_types::AUDIOBOOK: {
                this->addBook(std::make_unique<Audiobook>(*new Audiobook(book_data[1], book_data[2], book_data[3], stoi(book_data[4]), stoi(book_data[5]), book_data[6], stoi(book_data[7]))));
                break;
            }
            default: {
                std::cout << "unhandled exception";
                break;
            }
        }
        counter = 0;
    }
    input_file.close();
}
