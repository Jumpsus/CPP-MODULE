#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    public:
        Form();
        Form(const std::string name, const int requiredExecGrade, const int requiredSignGrade);
        Form(const Form &f);
        
        Form &operator=(const Form &f);
        virtual ~Form();

        std::string getName() const;
        int         getRequiredSignGrade() const;
        int         getRequiredExecGrade() const;
        bool        getSignStatus() const;
        void        beSigned(Bureaucrat &b);

        // newly added
        virtual void        execute(Bureaucrat const &b) const = 0;
        class GradeTooLowException: public std::exception{
            virtual const char *what() const throw(){
                return "Form Exception: Grade Too Low";
            }
        };

        class GradeTooHighException: public std::exception{
            virtual const char *what() const throw(){
                return "Form Exception: Grade Too High";
            }
        };

        class FormHasNotSignedYet: public std::exception{
            virtual const char *what() const throw(){
                return "Form Exception: Cannot Execute Form because Form hasn't been signed";
            }
        };

    private:
        const std::string   name;
        const int           requiredExecGrade;
        const int           requiredSignGrade;
        bool                sign;
};

std::ostream &operator<<(std::ostream &out, Form &f);

#endif