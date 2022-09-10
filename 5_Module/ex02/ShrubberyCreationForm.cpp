#include "ShrubberyCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(const std::string &target)
    :Form("shruberry", 137, 145), target(target){
    std::cout << "Constructed shruberry form" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm()
    : Form("shruberry", 137, 145), target(""){
     std::cout << "Default Constructed shruberry form" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &form)
    :Form(form.getName(), form.getRequiredExecGrade(), form.getRequiredSignGrade()), target(form.target){
    std::cout << "Constructed copy constructor shruberry form" << std::endl;
}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm &form){
    std::cout << "Assigned copy constructor shruberry form (Do nothing)" << std::endl;
    if (this == &form){
        return (*this);
    }
    return (*this);
}

ShruberryCreationForm::~ShruberryCreationForm(){
    std::cout << "Destructed shruberry form" << std::endl;
}

void    ShruberryCreationForm::execute(Bureaucrat const &executor) const{

    if (executor.getGrade() > this->getRequiredExecGrade()){
        throw(Form::GradeTooLowException());
    }
    if (!this->getSignStatus()){
        throw(Form::FormHasNotSignedYet());
    }
    
    std::string name = this->target + "_shruberry";
    char *name_char = &name[0];
    std::ofstream File(name_char);

    File << "                                                             ." << std::endl;
    File << "                                              .         ;  " << std::endl;
    File << "                 .              .              ;%     ;;   " << std::endl;
    File << "                   ,           ,                :;%  %;   " << std::endl;
    File << "                    :         ;                   :;%;'     .," << std::endl;   
    File << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    File << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    File << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    File << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    File << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    File << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    File << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    File << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
    File << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
    File << "                          `@%%. `@%%    ;@@%;        " << std::endl;
    File << "                            ;@%. :@%%  %@@%;       " << std::endl;
    File << "                              %@bd%%%bd%%:;     " << std::endl;
    File << "                                #@%%%%%:;;" << std::endl;
    File << "                                %@@%%%::;" << std::endl;
    File << "                                %@@@%(o);  . '         " << std::endl;
    File << "                                %@@@o%;:(.,'         " << std::endl;
    File << "                            `.. %@@@o%::;         " << std::endl;
    File << "                               `)@@@o%::;         " << std::endl;
    File << "                                %@@(o)::;        " << std::endl;
    File << "                               .%@@@@%::;         " << std::endl;
    File << "                               ;%@@@@%::;.          " << std::endl;
    File << "                              ;%@@@@%%:;;;. " << std::endl;
    File << "                          ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;

    File.close();
}

std::ostream &operator<<(std::ostream &out, ShruberryCreationForm &f){
    out << f.getName() << ", form required signed grade: " << f.getRequiredSignGrade() \
    << " form required exec grade: " << f.getRequiredExecGrade() << " sign status: "  \
    << f.getSignStatus() << std::endl;

    return (out);
}