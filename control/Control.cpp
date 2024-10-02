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
        std::cout << "choose an action:\n \t\t1: Show all books\n\t\t2: Show all readers";
        std::cin >> action_choice;
        switch(action_choice) {
            case 1: {
                lib->getBooks();
                break;
            }
            default: {
                std::cerr << "wrong input, or an internal error has happened";
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
    // lib->readBooks();
    // lib->getBooks();
    // lib->readReaders();
    // lib->getReaders();
    // lib->readRented();
    // lib->getRented();
    // lib->addRented("01J93NWKHY4KYEA4ZFFPY59HKS", 10);
    // lib->removeRented("01J93NWKHXYQ7X63CHV3GQTK3M");
    // lib->resetRented();
    // lib->changeRented("01J93NWKHX2QQ8C4SZ3JZBXVGD", 323);
    // std::cerr << Utilities::find_book_with_ULID("01J93NWKHXYQ7X63CHV3GQTK3M");
}
