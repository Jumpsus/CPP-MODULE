#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        Bureaucrat(const Bureaucrat &b);
        Bureaucrat &operator=(const Bureaucrat &b);

        void    Increment(int inc = 1);
        void    Decrement(int dec = 1);

        std::string getName() const;
        int         getGrade() const;

        class   GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw(){
                    return "Exception: Grade Too High...";
                }
        };

        class   GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw(){
                    return "Exception: Grade Too Low...";
                }
        };

    private:
        std::string const   name;
        int                 grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &b);

#endif