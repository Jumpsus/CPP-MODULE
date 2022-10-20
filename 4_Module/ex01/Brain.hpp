#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain{
    private:
        static int const    _maxIdea = 100;
    public:
        Brain();
        Brain(Brain const &brain);
        ~Brain();
        Brain &operator=(Brain const &brain);

        std::string idea[_maxIdea];
};
#endif