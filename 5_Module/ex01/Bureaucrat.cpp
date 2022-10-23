#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){
    if (grade > 150){
        throw (Bureaucrat::GradeTooLowException());
    }
    if (grade < 1){
        throw (Bureaucrat::GradeTooHighException());
    }
    std::cout << "Implement Constructor Bureaucrat name: " << name << " grade: " << grade << std::endl;
}


Bureaucrat::Bureaucrat(): name("Default Bureaucrat"), grade(150){
    std::cout << "Implement Default Constructor Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Implement Default Destructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b): name(b.name), grade(b.grade){
    std::cout << "Implement Copy Constructor Bureaucrat" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b){
    if (this == &b){
        return (*this);
    }
    this->grade = b.grade;
    std::cout << "Implement operator= from " << b.name << " to " << this->name << std::endl;
    return (*this);
}

void        Bureaucrat::Decrement(int dec){
    if ((this->grade + dec) > 150){
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << "Implement decrement " << dec << " to " << this->name << std::endl;
    this->grade = this->grade + dec;
}

void        Bureaucrat::Increment(int inc){
    if ((this->grade - inc) < 1){
        throw Bureaucrat::GradeTooHighException();
    }
    std::cout << "Implement increment " << inc << " to " << this->name << std::endl;
    this->grade = this->grade - inc;
}

std::string Bureaucrat::getName() const{
    return (this->name);
}

int         Bureaucrat::getGrade() const{
    return (this->grade);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b){
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (out);
}

void        Bureaucrat::signForm(Form &f){
    try {
        f.beSigned((*this)); // Do auto sign...
        std::cout << this->name << " signed " << f.getName() << std::endl;
    }

    catch(std::exception &e){
        std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}