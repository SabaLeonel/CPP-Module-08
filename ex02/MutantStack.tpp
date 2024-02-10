#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other)
	{
	    std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}
    
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::iterator iterator;
	
    iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
	iterator begin() const { return std::stack<T>::c.begin(); }
	iterator end() const { return std::stack<T>::c.end(); }
	reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
	reverse_iterator rend() { return std::stack<T>::c.rend(); }
	reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
	reverse_iterator rend() const { return std::stack<T>::c.rend(); }

};

#endif