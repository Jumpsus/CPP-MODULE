#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
    std::cout << "===== First Try (expect can sign: 1 can't sign: 1)  =====" << std::endl;
    try {
         Bureaucrat b1("bureacrat_1", 100);
         Form fp("Form_Premium", 1, 1);
         Form fl("Form_LowLevel", 150, 150);
         std::cout << b1 << std::endl << std::endl;
         std::cout << fp << std::endl;
         std::cout << fl << std::endl;

         std::cout << "***** Bureaucrat Try to sign form  *****" << std::endl;
         b1.signForm(fl);
         std::cout << "sign status of " << fl.getName() << " : " << std::boolalpha << fl.getSignStatus() << std::endl;
         std::cout << fl << std::endl;
         b1.signForm(fp);
         std::cout << "sign status of " << fp.getName() << " : " << std::boolalpha << fp.getSignStatus() << std::endl;
         std::cout << fp << std::endl;
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }

    std::cout << std::endl << "===== Second Try (Create Too high Form expect exception too high) =====" << std::endl;
    try {
         Form fp("Form_Too_Premium", 0, 0);
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
}