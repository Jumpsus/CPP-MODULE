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
        ~Form();

        std::string getName() const;
        int         getRequiredSignGrade() const;
        int         getRequiredExecGrade() const;
        bool        getSignStatus() const;
        void        beSigned(Bureaucrat &b);

        class GradeTooLowException: public std::exception{
            virtual const char *what() const throw(){
                return "Form Exception: Cannot creat form Grade Too Low";
            }
        };

        class GradeTooHighException: public std::exception{
            virtual const char *what() const throw(){
                return "Form Exception: Cannot creat form Grade Too High";
            }
        };

        class BureauceatTooLowException: public std::exception{
            virtual const char *what() const throw(){
                return "bureaucrat grade too low.";
            }
        };

        class FormHasBeenSigned: public std::exception{
            virtual const char *what() const throw(){
                return "form has been signed.";
            }
        };

        class FormIsNotSigned : public std::exception{
            virtual const char *what() const throw(){
                return "form isn't signed.";
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