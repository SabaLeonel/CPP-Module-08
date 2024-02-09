#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int _number;
    public:
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array		&operator= (const Array &other);
		T			&operator[](unsigned int i);
		const T		&operator[](unsigned int i) const;
		~Array(void);
        
    void printArray(void);
    void setArray(T customfill);
    unsigned int size(void);
  
};

#include "Array.tpp"

#endif
