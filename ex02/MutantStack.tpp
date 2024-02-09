#include "Mutant.hpp"

template <class T>
Array<T>::Array() : arr(nullptr), _number(0) 
{
    std::cout << "Default constructor Array created with 0" << std::endl;
}

template <class T>
Array<T>::Array(unsigned int n) : arr(new T[n]), _number(n)
{
    std::cout << "Array created with " << n << std::endl;
}


template <class T>
Array<T>::Array(const Array &other) : arr(new T[other._number]), _number(other._number) 
{
    for (unsigned int i = 0; i < this->_number; i++) 
        this->arr[i] = other.arr[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array &rhs) 
{
    if (this != &rhs) 
    {
        if (this->arr)
            delete[] this->arr;
        this->_number = rhs._number;
        this->arr = new T[rhs._number];
        for (unsigned int i = 0; i < this->_number; i++) 
            this->arr[i] = rhs.arr[i];
    }
    return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int i) 
{
    if (i >= this->_number || i < 0)
        throw std::out_of_range("Index out of range");
    return arr[i];
}


template <class T>
const T &Array<T>::operator[](unsigned int i) const 
{
    if (i >= this->_number || i < 0)
        throw std::out_of_range("Index out of range");
    return arr[i];
}

template <class T>
Array<T>::~Array(void) 
{
    std::cout << "Array destroyed" << std::endl;
    delete[] this->arr;
}

template <class T>
void Array<T>::printArray(void) 
{
    for (unsigned int i = 0; i < this->_number; i++) 
        std::cout << this->arr[i] << std::endl;
}

template <class T>
void Array<T>::setArray(T customfill) 
{
    for (unsigned int i = 0; i < this->_number; i++)
        this->arr[i] = customfill;
}

template <class T>
unsigned int Array<T>::size(void) {
    return this->_number;
}
