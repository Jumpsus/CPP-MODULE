#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int     main()
{
    {
        std::cout << "=== Mandatory Test ===" << std::endl;

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
        std::cout << std::endl;
    }
    {
        std::cout << "=== My Test ===" << std::endl;

        // MateriaSource::_verbose = true;
        // Character::_verbose = true;
        // AMateria::_verbose = true;

        std::cout << "--- Create MateriaSource ---" << std::endl;
        IMateriaSource* src = new MateriaSource();
        std::cout << std::endl;

        std::cout << "--- Test create unlearned material ---" << std::endl;
        src->learnMateria(new Ice());
        AMateria *materiaPtr;

        materiaPtr = src->createMateria("ice");
        std::cout << "[Expect Can Created] Materia source create ice :" << materiaPtr << std::endl;
        delete materiaPtr;
        materiaPtr = src->createMateria("pure");
        std::cout << "[Expect Cannot Created] Materia source create pure :" << materiaPtr << std::endl;
        
        std::cout << std::endl;

        std::cout << "--- Test Learn more than limit (maximum 4) ---" << std::endl;

        AMateria *model;
        for (int i = 1; i <= 4; i++){
            if (i % 2 == 1){
                model = new Ice();
                src->learnMateria(model);
            } else {
                model = new Cure();
                src->learnMateria(model);
            }
        }
        delete model;
        std::cout << std::endl;

        std::cout << "--- Create 2 Character ---" << std::endl;
        ICharacter* me = new Character("me"); // active
        ICharacter* bob = new Character("bob"); // victim
        std::cout << std::endl;

        std::cout << "--- Equip and Unequipped Item for Character me ---" << std::endl;

        std::cout << "* equip part *" << std::endl;
        AMateria* tmp;

        for (int i = 1; i <= 5 ; i++){
            std::cout << i << " Try" << std::endl;
            tmp = src->createMateria("ice");
            me->equip(tmp);
        }
        delete tmp;
        std::cout << std::endl;

        std::cout << "* unequip part *" << std::endl;
        me->unequip(1);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        std::cout << std::endl;

        std::cout << "--- Use Item Part ---" << std::endl;        
        me->use(0, *bob);
        me->use(1, *bob);

        std::cout << std::endl;

        std::cout << "--- Delete Part ---" << std::endl;  
        delete bob;
        delete me;
        delete src;
        std::cout << std::endl;
    }
    return (0);
}