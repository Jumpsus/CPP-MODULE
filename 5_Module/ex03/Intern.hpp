#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Form;

class Intern{
    public:
        Intern();
        Intern(const Intern &i);
        Intern & operator=(const Intern &i);
        ~Intern();

        Form *makeForm(std::string form, std::string target);
};


#endif