#include "utils.hpp"

Base    *generate(void){
    Base    *base;

    std::cout << "Generate ";
    srand(time(0));
    switch (rand() % 3)
    {
    case (1):
        std::cout << "A" << std::endl;
        base = new A();
        break;

    case (2):
        std::cout << "B" << std::endl;
        base = new B();
        break;

    default: //case 0
        std::cout << "C" << std::endl;
        base = new C();
        break;
    }
    return (base);
}

void    identify(Base *p){

    // TYPE* dynamic_cast<TYPE*> (object); It will return "NULL" if input isn't actual type...
    if (dynamic_cast<A*>(p)){
        std::cout << "This pointer is definitely A !!" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p)){
        std::cout << "This pointer is definitely B !!" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p)){
        std::cout << "This pointer is definitely C !!" << std::endl;
        return;
    }
}

void    identify(Base &p){

    // TYPE& dynamic_cast<TYPE&> (object); It will throw " bad_cast " if input isn't actual type
    try{
        dynamic_cast<A&>(p);
        std::cout << "This reference is definitely A !!" << std::endl;
    }
    catch(...){
        try{
            dynamic_cast<B&>(p);
            std::cout << "This reference is definitely B !!" << std::endl;
        }
        catch(...){
            try{
                dynamic_cast<C&>(p);
                std::cout << "This reference is definitely C !!" << std::endl;
            }
            catch(...){
                std::cout << "What you give me Dude !!!" << std::endl;
            }
        }
    }
}

