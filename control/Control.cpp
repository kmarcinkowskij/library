//
// Created by Konrad Marcinkowski on 01/10/2024.
//

#include "Control.h"

#include <regex>

#include "../Library.h"
#include "../utils/Utilities.h"

void Control::run_lib() {
    Library* lib = new Library;
    lib->init();
    std::string choice;
    int action_choice;
    do {
        std::cout << "choose an action:\n \t\t1: Show all books\n\t\t2: Show all readers\n\t\t3: Show all renters\n\t\t4: Add a new renter\n\t\t5: remove a rented book\n\t\t6: reset all rented books (dangerous)\n";
        std::cin >> action_choice;
        switch(action_choice) {
            case 1: {
                lib->getBooks();
                break;
            }
            case 2: {
                lib->getReaders();
                break;
            }
            case 3: {
                lib->getRented();
                break;
            }
            case 4: {
                std::string ULID;
                int32_t reader_id;
                std::cout << "please input the ULID of the book in question and the ID of the reader in question";
                do {
                    std::cin >> ULID;
                    std::cin >> reader_id;

                    if(std::get<0>(lib->find_book_with_ULID(ULID)) == -1) {
                        std::cerr << "book not found, are you sure it exists?\n";
                    }
                    std::cout << lib->check_book_availibility_ULID(ULID) << "\n";
                    if(lib->check_book_availibility_ULID(ULID) == 0) {
                        std::cerr << "book marked as rented, are you sure it is availible?\n";
                    }
                    if(lib->get_reader_name_with_ID(reader_id) == "404") {
                        std::cerr << "reader not found, are you sure they exist?\n";
                    }
                }while(std::get<0>(lib->find_book_with_ULID(ULID)) == -1 || lib->get_reader_name_with_ID(reader_id) == "404" || lib->check_book_availibility_ULID(ULID) == 0 );
                lib->addRented(ULID, reader_id);
                std::cout << std::get<1>(lib->find_book_with_ULID(ULID)) << " (" << ULID << ") rented by " <<lib->get_reader_name_with_ID(reader_id) << " (" << reader_id  << ")\n";
                break;
            }
            case 5: {
                std::string ULID;
                std::cout << "please input the ULID of the book in question";
                do {
                    std::cin >> ULID;
                    if(lib->find_book_in_rented(ULID) == -1) {
                        std::cerr << "rented book not found, are you sure it exists?\n";
                    }
                }while(lib->find_book_in_rented(ULID) == -1);
                lib->removeRented(ULID);
                break;
            }
            case 6: {
                lib->resetRented();
                break;
            }
            default: {
                std::cerr << "wrong input, or an internal error has happened";
                break;
            }
        }
        std::cout << "continue?\n";
        std::cin >> choice;
        for(char& character: choice) {
            character = tolower(character);
        }
        if(!Utilities::choice_map.contains(choice)) {
            std::cerr << "\nwrong input!\n";
            break;
        }
    }while(Utilities::choice_map.contains(choice) && Utilities::choice_map.at(choice));
}
