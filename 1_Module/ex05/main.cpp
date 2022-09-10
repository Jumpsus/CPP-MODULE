#include "Harl.hpp"

int main(){
    Harl    harl;
    std::cout << "=== DUBUG CASE ===" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "=== INFO CASE ===" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "=== WARNING CASE ===" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "=== ERROR CASE ===" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
}