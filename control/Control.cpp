//
// Created by Konrad Marcinkowski on 01/10/2024.
//

#include "Control.h"
#include "../Library.h"
#include "../utils/Utilities.h"

void Control::run_lib() {
    Library* lib = new Library;
    lib->readBooks();
    lib->getBooks();
    lib->readReaders();
    lib->getReaders();
    lib->readRented();
    lib->getRented();
    lib->addRented("01J93NWKHY4KYEA4ZFFPY59HKS", 10);
    lib->removeRented("01J93NWKHXYQ7X63CHV3GQTK3M");
    // lib->resetRented();
    // lib->changeRented("01J93NWKHX2QQ8C4SZ3JZBXVGD", 323);
    // std::cerr << Utilities::find_book_with_ULID("01J93NWKHXYQ7X63CHV3GQTK3M");
}
