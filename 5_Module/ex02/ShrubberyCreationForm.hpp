#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <stdexcept>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"


class Bureaucrat;

class Form;

class ShruberryCreationForm: public Form{
    public:
        ShruberryCreationForm(const std::string &target);
        ShruberryCreationForm();
        ShruberryCreationForm(const ShruberryCreationForm &form);

        ShruberryCreationForm &operator=(const ShruberryCreationForm &form);
        ~ShruberryCreationForm();

        void execute(Bureaucrat const &executor) const;
    private:
        const std::string target;
};

std::ostream &operator<<(std::ostream &out, ShruberryCreationForm &f);

#endif