# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "utils.hpp"

int main(){
    Base *base = generate();

    identify(base);
    identify(*base);
}