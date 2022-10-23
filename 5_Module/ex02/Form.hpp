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
        bool                executable(const Bureaucrat &b) const;
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