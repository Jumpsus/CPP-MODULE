#include "AMateria.hpp"

bool AMateria::_verbose = false;

AMateria::AMateria(){
    if (AMateria::_verbose)
        std::cout << "Create Default Constructor AMateria !" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type){
    if (AMateria::_verbose)
        std::cout << "Create Constructor AMateria type: " << this->_type << std::endl;
}

AMateria::AMateria(AMateria const &a): _type(a.getType()){
    if (AMateria::_verbose)
        std::cout << "Copy Constructor AMateria type: " << this->_type << std::endl;
}

AMateria    &AMateria::operator=(AMateria const &a){
    if (AMateria::_verbose)
        std::cout << "Assign Copy operator AMateria (Do nothing)" << std::endl;
    if (this->getType() != a.getType()){
        std::cout << "Cannot Assigned new type (Different type)" << std::endl;
    }
    return (*this);
}

AMateria::~AMateria(){
    if (AMateria::_verbose)
        std::cout << "Default Destructor AMateria !" << std::endl;
}

std::string const & AMateria::getType() const{
    return (this->_type);
}

void    AMateria::use(ICharacter& target){
    std::cout << "* User doesn't know how to use this to " << target.getName() << " *" << std::endl;
}