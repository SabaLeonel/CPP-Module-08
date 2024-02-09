#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <climits>

class Span
{
    private:
        unsigned int _n;
        unsigned int _size;
        std::vector<int> _v;
    public:
        Span(void);
        Span(unsigned int n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span(void);
        void addNumber(int n);
        int shortestSpan(void);
        int longestSpan(void);
        void fillVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void fill_random(unsigned int n);
};



#endif