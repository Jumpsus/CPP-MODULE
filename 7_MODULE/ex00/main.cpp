#include "utils.hpp"
#include <iostream>

int main(){

    char    a = 'a';
    char    b = 'b';
    int     c = 0;
    int     d = 1;
    float   e = 0.0f;
    float   f = 0.1f;
    double  g = 0.0;
    double  h = 1.0;
    std::string i = "a";
    std::string j = "b";

    std::cout << "=== SWAP TEST ===" << std::endl;
    std::cout << "before swap (char) first: " << a << " second: " << b << std::endl;
    swap (a, b);
    std::cout << "after swap (char) first: " << a << " second: " << b << std::endl << std::endl;

    std::cout << "before swap (int) first: " << c << " second: " << d << std::endl;
    swap (c, d);
    std::cout << "after swap (int) first: " << c << " second: " << d << std::endl << std::endl;

    std::cout << "before swap (float) first: " << e << " second: " << f << std::endl;
    swap (e, f);
    std::cout << "after swap (float) first: " << e << " second: " << f << std::endl << std::endl;

    std::cout << "before swap (double) first: " << g << " second: " << h << std::endl;
    swap (g, h);
    std::cout << "after swap (double) first: " << g << " second: " << h << std::endl << std::endl;

    std::cout << "before swap (string) first: " << i << " second: " << j << std::endl;
    swap (i, j);
    std::cout << "after swap (string) first: " << i << " second: " << j << std::endl << std::endl;

    std::cout << "=== MIN TEST ===" << std::endl;
    std::cout << "min (char): " << min(a, b) << std::endl;
    std::cout << "min (int): " << min(c, d) << std::endl;
    std::cout << "min (float): " << min(e, f) << std::endl;
    std::cout << "min (double): " << min(g, h) << std::endl << std::endl;

    std::cout << "=== MAX TEST ===" << std::endl;
    std::cout << "max (char): " << max(a, b) << std::endl;
    std::cout << "max (int): " << max(c, d) << std::endl;
    std::cout << "max (float): " << max(e, f) << std::endl;
    std::cout << "max (double): " << max(g, h) << std::endl << std::endl;

}