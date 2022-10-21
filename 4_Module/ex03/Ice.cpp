#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
    if (AMateria::_verbose)
        std::cout << "Create Default Constructor Ice !" << std::endl;
}

Ice::Ice(Ice const &a): AMateria(a.getType()){
    if (AMateria::_verbose)
        std::cout << "Copy Constructor Ice type: " << this->_type << std::endl;
}

Ice    &Ice::operator=(Ice const &a){
    if (AMateria::_verbose)
        std::cout << "Assign Copy operator Ice (Do nothing)" << std::endl;
    if (this->_type != a.getType())
        std::cout << "(Doesn't Make Sense) Assign Copy operator Ice" << std::endl;
    return (*this);
}

Ice::~Ice(){
    if (AMateria::_verbose)
        std::cout << "Destructor Ice !" << std::endl;
}

AMateria* Ice::clone() const{
    AMateria *clone = new Ice();
    return (clone);
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}