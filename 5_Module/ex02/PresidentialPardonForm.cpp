#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    :Form("presidential", 5, 25), target(target){
    std::cout << "Constructed presidential form" <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
    :Form("presidential", 5, 25), target(""){
    std::cout << "Default Constructed presidential form" <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
    :Form(form.getName(), form.getRequiredExecGrade(), form.getRequiredSignGrade()), target(form.target){
    std::cout << "Constructed copy constructor presidential form" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form){
    std::cout << "Assigned copy constructor presidential form (Do nothing)" << std::endl;
    if (this == &form){
        return (*this);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Destructed  presidential form" <<std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > this->getRequiredExecGrade()){
        throw (Form::BureauceatTooLowException());
    }
    if (!this->getSignStatus()){
        throw (Form::FormIsNotSigned());
    }
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    std::cout << "[INFORM] " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &f){
    out << f.getName() << ", form required signed grade: " << f.getRequiredSignGrade() \
    << " form required exec grade: " << f.getRequiredExecGrade() << " sign status: "  \
    << std::boolalpha << f.getSignStatus() << std::endl;

    return (out);
}