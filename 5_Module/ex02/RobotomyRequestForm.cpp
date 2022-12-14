#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    :Form("robotomy", 45, 72), target(target){
    std::cout << "Constructed robotomy form" <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm()
    :Form("robotomy", 45, 72), target(""){
    std::cout << "Default Constructed robotomy form" <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    :Form(form.getName(), form.getRequiredExecGrade(), form.getRequiredSignGrade()), target(form.target){
    std::cout << "Constructed copy constructor robotomy form" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form){
    std::cout << "Assigned copy constructor robotomy form (Do nothing)" << std::endl;
    if (this == &form){
        return (*this);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Destructed  robotomy form" <<std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const{

    if (this->executable(executor)){
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
        std::cout << "Drill Drill Dr..... *Drilling Noise" << std::endl;
    
        srand(time(0));
        if (rand() %2 == 0){
            std::cout << this->target << " has been robotomized..." <<std::endl;
        } else {
            std::cout << "robotomy failed..." << std::endl;
        }
    }
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &f){
    out << f.getName() << ", form required signed grade: " << f.getRequiredSignGrade() \
    << " form required exec grade: " << f.getRequiredExecGrade() << " sign status: "  \
    << std::boolalpha << f.getSignStatus() << std::endl;

    return (out);
}