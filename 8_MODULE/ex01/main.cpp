#include "Span.hpp"

int main(){
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