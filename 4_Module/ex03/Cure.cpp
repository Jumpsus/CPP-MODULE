#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    if (AMateria::_verbose)
        std::cout << "Create Default Constructor Cure !" << std::endl;
}

Cure::~Cure(){
    if (AMateria::_verbose)
        std::cout << "Destructor Cure !" << std::endl;
}

Cure::Cure(const Cure &p) : AMateria(p.getType()){
    if (AMateria::_verbose)
        std::cout << "Copy Constructor Cure type: " << this->_type << std::endl;
}

Cure &Cure::operator=(const Cure &p){
    if (AMateria::_verbose)
        std::cout << "Assign Copy operator Cure (Do nothing)" << std::endl;
    if (this->_type != p.getType())
        std::cout << "(Doesn't Make Sense) Assign Copy operator Ice" << std::endl;
    return (*this);
}

AMateria *Cure::clone() const{
    AMateria *clone = new Cure();
    return (clone);
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}