#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

class Bureaucrat;

class PresidentialPardonForm : public Form{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);

        PresidentialPardonForm(const PresidentialPardonForm &form);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

        ~PresidentialPardonForm();

        void    execute(Bureaucrat const &executor) const;
    private:
        std::string const target;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &form);

#endif