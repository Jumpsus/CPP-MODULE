#include "Span.hpp"

int main(){
    try{
        std::cout << "== Mandatory Case ==" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (...){
        std::cerr << "Unknown error appear" << std::endl;
    }
    try{
        std::cout << "== Normal Case ==" << std::endl;
        Span    s(10);

        for (int i = 0; i < 10; i++){
            s.addNumber(i * i);
        }
        std::cout << "Longest Span " << s.longestSpan() << std::endl;
        std::cout << "Shortest Span " << s.shortestSpan() << std::endl;
    }
    catch (std::exception &ex){
        std::cout << ex.what() << std::endl;
    }
    catch (...){
        std::cout << "Caught unknown exception" << std::endl;
    }

    try {
        std::cout << std::endl << "== Exceed Limit Case ==" << std::endl;
        Span    s(10);

        for (int i = 0; i < 11; i++){
            s.addNumber(i * i);
        }
        std::cout << "Longest Span " << s.longestSpan() << std::endl;
        std::cout << "Shortest Span " << s.shortestSpan() << std::endl;
    }
    catch (std::exception &ex){
        std::cout << ex.what() << std::endl;
    }
    catch (...){
        std::cout << "Caught unknown exception" << std::endl;
    }

    try{
        std::cout << std::endl << "== Too Little argument Case ==" << std::endl;
        Span    s(10);

        for (int i = 0; i < 1; i++){
            s.addNumber(i * i);
        }
        std::cout << "Longest Span " << s.longestSpan() << std::endl;
        std::cout << "Shortest Span " << s.shortestSpan() << std::endl;
    }
    catch (std::exception &ex){
        std::cout << ex.what() << std::endl;
    }
    catch (...){
        std::cout << "Caught unknown exception" << std::endl;
    }

}