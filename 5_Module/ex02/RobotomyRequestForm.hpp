#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public Form{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const target);

        RobotomyRequestForm(const RobotomyRequestForm &form);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &form);

        ~RobotomyRequestForm();

        void  execute(Bureaucrat const &executor) const;
    private:
        std::string const   target;
};

std::ostream &operator<<(std::ostream &out,  RobotomyRequestForm &form);

#endif