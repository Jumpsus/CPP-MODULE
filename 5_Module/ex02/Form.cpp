#include "Form.hpp"

Form::Form(const std::string name, const int requiredExecGrade, const int requiredSignGrade)
    : name(name), requiredExecGrade(requiredExecGrade), requiredSignGrade(requiredSignGrade), sign(false){

    if (requiredExecGrade > 150 || requiredSignGrade > 150){
        throw (Form::GradeTooLowException());
    } else if (requiredExecGrade < 1 || requiredSignGrade < 1) {
        throw (Form::GradeTooHighException());
    }

    std::cout << "Implement Constructor Form name: " << name << " required signed grade:  " << requiredSignGrade \
    << " require execute grade: " << requiredExecGrade << std::endl;
}

Form::Form()
    :name("Default Form"), requiredExecGrade(150), requiredSignGrade(150), sign(false){
    std::cout << "Implement Default Constructor Form" << std::endl;
}

Form::Form(const Form &f)
    :name(f.name), requiredExecGrade(f.requiredExecGrade), requiredSignGrade(f.requiredSignGrade), sign(f.sign){
    std::cout << "Implement Copy Constructor Form from " << f.name << std::endl;
}

Form   &Form::operator=(const Form &f){
    std::cout << "Implement Assign Copy Form (which do nothing... \
    [almost all member is const and it's not make sense to copy sign status])" << std::endl;
    if (this == &f){
        return (*this);
    }
    return (*this);
}

Form::~Form(){
    std::cout << "Implement Default Destructor Form" << std::endl;
}

std::string Form::getName() const{
    return(this->name);
}

int         Form::getRequiredSignGrade() const{
    return(this->requiredSignGrade);
}

int         Form::getRequiredExecGrade() const{
    return(this->requiredExecGrade);
}

bool        Form::getSignStatus() const{
    return(this->sign);
}

void        Form::beSigned(Bureaucrat &b){
    if (b.getGrade() > this->getRequiredSignGrade()){
        throw(Form::GradeTooLowException());
    }
    this->sign = true;
}

std::ostream &operator<<(std::ostream &out, Form &f){
    out << f.getName() << ", form required signed grade: " << f.getRequiredSignGrade() \
    << " form required exec grade: " << f.getRequiredExecGrade() << " sign status: "  \
    << f.getSignStatus() << std::endl;

    return (out);
}