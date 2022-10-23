#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){
    Bureaucrat *b1 = new Bureaucrat("bureacrat_1", 1);
    Bureaucrat *b3 = new Bureaucrat("bureacrat_3", 150);

    Form *a;
    Form *b;
    Form *c;
    Form *d;

    std::cout << "===== Intern Create Form =====" << std::endl;
    {
        Intern someRandomIntern;

        a =someRandomIntern.makeForm("presidential pardon", "target");
        b =someRandomIntern.makeForm("robotomy request", "target");
        c =someRandomIntern.makeForm("shrubbery creation", "target");
        d =someRandomIntern.makeForm("unknown form", "target");
    }
	
    std::cotu << endl;
    std::cout << "===== Worst Bureaucrat Try to sign and execute every form  =====" << std::endl;
    try {
         std::cout << "***** Bureaucrat Try to sign form  *****" << std::endl;
         b3->signForm(*a);
         b3->executeForm(*a);
         b3->signForm(*b);
         b3->executeForm(*b);
         b3->signForm(*c);
         b3->executeForm(*c);
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "===== Best Bureaucrat Try to sign and execute every form  =====" << std::endl;
    try {
         std::cout << "***** Bureaucrat Try to sign form  *****" << std::endl;
         b1->signForm(*a);
         b1->executeForm(*a);
         b1->signForm(*b);
         b1->executeForm(*b);
         b1->signForm(*c);
         b1->executeForm(*c);
    }
    catch (std::exception &exception){
        std::cout << exception.what() <<std::endl;
    }
    std::cout << std::endl;

    delete a;
    delete b;
    delete c;
    
    if (d){
        delete d;
    }

    delete b1;
    delete b3;
}
