#include "MateriaSource.hpp"

bool MateriaSource::_verbose = false;

MateriaSource::MateriaSource() : _learned(0){
    if (MateriaSource::_verbose)
        std::cout << "Construct MateriaSource" << std::endl;
    for (int i = 0; i < MateriaSource::_maxSource; i++){
        this->_source[i] = NULL;
    }
}

MateriaSource::~MateriaSource(){
    if (MateriaSource::_verbose)
        std::cout << "Destruct MateriaSource" << std::endl;
    for (int i = 0; i < this->_learned; i++){
        delete this->_source[i];
        this->_source[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &ms){
    if (MateriaSource::_verbose)
        std::cout << "Copy Constructor MateriaSource" << std::endl;
    (*this) = ms;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms){
    if (MateriaSource::_verbose)
        std::cout << "Copy Assignment MateriaSource" << std::endl;
    for (int i = 0; i < MateriaSource::_maxSource; i++){
        if (this->_source[i])
            delete this->_source[i];
        if (ms._source[i])
            this->_source[i] = ms._source[i]->clone();
        else
            this->_source[i] = NULL;
    }
    this->_learned = ms._learned;
    return (*this);
}

void MateriaSource::learnMateria(AMateria *a){
    if (this->_learned >= MateriaSource::_maxSource){
        std::cout << "MateriaSource is already at learn limit" << std::endl;
        return ;
    }
    this->_source[this->_learned] = a;
    std::cout << "MateriaSource learned " << a->getType() << std::endl;
    this->_learned++;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < this->_learned; i++){
        if (this->_source[i]->getType() == type){
            return (this->_source[i]->clone());
        }
    }
    return (0);
}