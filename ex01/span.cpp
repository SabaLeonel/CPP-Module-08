#include "Span.hpp"

Span::Span(void) : _n(0), _size(0) {
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(0), _size(n) {
    std::cout << "Parametric constructor called" << std::endl;
}

Span::Span(Span const &other) : _n(other._n), _size(other._size), _v(other._v) {
    std::cout << "Copy constructor called" << std::endl;
}




Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _n = other._n;
        _size = other._size;
        _v = other._v;
    }
    return *this;
}


Span::~Span(void) {}

void Span::addNumber(int n)
{
    if (this->_n < this->_size)
    {
        this->_v.push_back(n);
        this->_n++;
    }
    else
        throw std::out_of_range("Span is full");
}

int Span::shortestSpan(void)
{
    int ret;
    std::vector <int>::iterator custom_iterator;
    std::vector <int> bigtemp;

    if (this->_v.size () <= 1)
        throw std::out_of_range("Not enough elements for a span");
    bigtemp = this->_v;
    std::sort(bigtemp.begin(), bigtemp.end());
    custom_iterator = bigtemp.begin();
    ret = *(custom_iterator + 1) - *custom_iterator;
    for (custom_iterator = bigtemp.begin(); custom_iterator != bigtemp.end(); custom_iterator++)
    {
        if (ret > *(custom_iterator + 1) - *custom_iterator)
            ret = *(custom_iterator + 1) - *custom_iterator;
    }
    return ret;
}

void Span::fill_random(unsigned int n)
{
    std::srand(std::time(0));
    for (unsigned int i = 0; i < n; i++)
        this->_v.push_back(std::rand () % n + 1);
}

void Span::fillVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) > this->_size - this->_n)
        throw std::out_of_range("Not enough space in the span");
    this->_v.insert(this->_v.end(), begin, end);
    this->_n += std::distance(begin, end);
}

int Span::longestSpan(void)
{
    std::vector<int> bigtemp;


    if (this->_v.size() <= 1)
        throw std::out_of_range("Not enough elements for a span");
    bigtemp = this->_v;
    std::sort(bigtemp.begin(), bigtemp.end());
    return *std::max_element(this->_v.begin(), this->_v.end()) - *std::min_element(this->_v.begin(), this->_v.end());
}