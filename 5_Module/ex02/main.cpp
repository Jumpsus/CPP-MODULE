#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
    Bureaucrat *b1 = new Bureaucrat("bureacrat_1", 1);
    Bureaucrat *b3 = new Bureaucrat("bureacrat_1", 150);

    std::cout << "===== Shruberry Try (expect no err)  =====" << std::endl;
    try {
         Form *sc = new ShruberryCreationForm("tree");

         std::cout << "***** Bureaucrat Try to sign form  *****" << std::endl;
         b1->signForm(*sc);
         sc->beSigned(*b1);
         std::cout << "sign status of " << sc->getName() << " : " << sc->getSignStatus() << std::endl;
         b1->executeForm(*sc);
         sc->execute(*b1);
         delete sc;
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "===== Robotomy Try (expect no err)  =====" << std::endl;
    try {
         Form *rb = new RobotomyRequestForm("robo");

         std::cout << "***** Bureaucrat Try to sign form  *****" << std::endl;
         b1->signForm(*rb);
         rb->beSigned(*b1);
         std::cout << "sign status of " << rb->getName() << " : " << rb->getSignStatus() << std::endl;
         b1->executeForm(*rb);
         rb->execute(*b1);
         rb->execute(*b1);
         rb->execute(*b1);
         delete rb;
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "===== Presidential Try (expect no err)  =====" << std::endl;
    try {
         Form *pp = new PresidentialPardonForm("pred");

         std::cout << "***** Bureaucrat Try to sign form  *****" << std::endl;
         b1->signForm(*pp);
         pp->beSigned(*b1);
         std::cout << "sign status of " << pp->getName() << " : " << pp->getSignStatus() << std::endl;
         b1->executeForm(*pp);
         pp->execute(*b1);
         delete pp;
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "===== Not Signed Try (expect not sign exception)  =====" << std::endl;
    try {
         Form *pp = new PresidentialPardonForm("pred");

         std::cout << "sign status of " << pp->getName() << " : " << pp->getSignStatus() << std::endl;
         b1->executeForm(*pp);
         pp->execute(*b1);
         delete pp;
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "===== Too low try (expect too low exception)  =====" << std::endl;
    try {
         Form *pp = new PresidentialPardonForm("pred");

         std::cout << "***** Bureaucrat Try to sign form  *****" << std::endl;
         b3->signForm(*pp);
         pp->beSigned(*b3);
         std::cout << "sign status of " << pp->getName() << " : " << pp->getSignStatus() << std::endl;
         b3->executeForm(*pp);
         pp->execute(*b3);
         delete pp;
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
    std::cout << std::endl;

    delete b1;
    delete b3;
}