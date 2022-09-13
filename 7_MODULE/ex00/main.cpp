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
    std::cout << "before min (char) first: " << min(a, b) << std::endl;
    std::cout << "before min (int) first: " << min(c, d) << std::endl;
    std::cout << "before min (float) first: " << min(e, f) << std::endl;
    std::cout << "before min (double) first: " << min(g, h) << std::endl << std::endl;

    std::cout << "=== MAX TEST ===" << std::endl;
    std::cout << "before max (char) first: " << max(a, b) << std::endl;
    std::cout << "before max (int) first: " << max(c, d) << std::endl;
    std::cout << "before max (float) first: " << max(e, f) << std::endl;
    std::cout << "before max (double) first: " << max(g, h) << std::endl << std::endl;

}