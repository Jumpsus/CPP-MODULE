#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource{
    private:
        static  int const   _maxSource = 4;

        AMateria    *_source[_maxSource];
        int         _learned;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &ms);
        MateriaSource &operator=(const MateriaSource &ms);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);

        static bool     _verbose;
};

#endif