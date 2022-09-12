# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "utils.hpp"

int main(){
    Base *base = generate();

    std::cout << std::endl << "=== Identify from Pointer ===" << std::endl ;
    identify(base);
    std::cout << std::endl << "=== Identify from Reference ===" << std::endl;
    identify(*base);

    std::cout << std::endl;
    delete base;
}
