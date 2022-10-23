#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Default Constructor Intern" << std::endl;
}

Intern::Intern(const Intern &i){
    std::cout << "Copy Constructor Intern" << std::endl;
    (void) i;
}

Intern & Intern::operator=(const Intern &i){
    std::cout << "Assign Copy Operator Intern" << std::endl;
    if (this == &i)
        return (*this);
    return (*this);
}

Intern::~Intern(){
    std::cout << "Destructor Intern" << std::endl;
}

Form *Intern::makeForm(std::string form, std::string target){
    int index = (form == "presidential pardon") ? 0 : \
                (form == "robotomy request") ? 1 : \
                (form == "shrubbery creation") ? 2 : 3;

    switch(index){
        case 0:
            std::cout << "Intern creates presidential pardon form" << std::endl; 
            return (new PresidentialPardonForm(target));
            break;
        case 1:
            std::cout << "Intern creates robotomy request form" << std::endl;
            return (new RobotomyRequestForm(target));
            break;
        case 2:
            std::cout << "Intern creates shrubbery creation form" << std::endl;
            return (new ShruberryCreationForm(target));
            break;
        default:
            std::cerr << "Intern cannot create form : unknown name" << std::endl;
    }
    return (NULL);
}