#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <stdexcept>

class Span{
    public:
        Span();
        Span(unsigned int   size);
        Span(const Span &s);
        Span &operator=(const Span &s);
        ~Span();

        void    addNumber(int value);

        unsigned    int     shortestSpan();
        unsigned    int     longestSpan();
        unsigned    int     size() const;
        unsigned    int     maxSize() const;
        class   exceedMaximumLimit : std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("size is beyond maximum limit");
                }
        };

        class   tooLittleValue : public std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("too little argument");
                }
        };

    private:
        unsigned    int     _maxsize;
        unsigned    int     _currentsize;
        std::vector<int>    _value;
};

// std::ostream    &operator<<(std::ostream &out, Span &s);

#endif