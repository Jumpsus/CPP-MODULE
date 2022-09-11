#ifndef UTILS_HPP
# define UTILS_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <stdlib.h>
# include <time.h>

Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif