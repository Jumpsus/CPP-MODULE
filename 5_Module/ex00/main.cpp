#include "Bureaucrat.hpp"

int main(void){
    std::cout << "===== First Try (expect exception too high)  =====" << std::endl;
    try {
         Bureaucrat b1("bureacrat_1", 100);
         Bureaucrat b2(b1);
         b2.Increment(10);
         std::cout << b2 << std::endl;
         b2.Increment(1000);
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }

    std::cout << std::endl << "===== Second Try (expect exception too low) =====" << std::endl;
    try {
         Bureaucrat b1("bureacrat_1", 1);
         Bureaucrat b2("bureacrat_2", 2);
         b2 = b1;
         std::cout << b2 << std::endl;
         b2.Decrement(1000);
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
}