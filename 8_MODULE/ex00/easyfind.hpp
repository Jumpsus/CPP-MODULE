#include <algorithm>
#include <exception>

class exceptionNotFound : public std::exception{
    public:
        virtual char const *what() const throw(){
            return ("Find Nothing");
        }
};

template <typename T>
typename T::iterator     easyfind(T &container, int target){
    typename T::iterator     index;
    index = std::find(container.begin(), container.end(), target);

    if (index == container.end()){
        throw(exceptionNotFound());
    }
    
    return index;
}
