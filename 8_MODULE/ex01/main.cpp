#include "Span.hpp"

int main(){
    Span    s(10);

    for (int i = 0; i < 10; i++){
        s.addNumber(i * i);
    }
    std::cout << "Longest Span " << s.longestSpan() << std::endl;
    std::cout << "Shortest Span " << s.shortestSpan() << std::endl;

}