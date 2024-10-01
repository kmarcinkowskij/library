
#include <chrono>
#include "control/Control.h"

int main() {
    // std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::high_resolution_clock::now();
    Control::run_lib();
    // std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::high_resolution_clock::now();
    //
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //
    // std::cout << duration.count() << "\n";
    return 0;
}
