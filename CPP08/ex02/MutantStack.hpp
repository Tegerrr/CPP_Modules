#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    ~MutantStack() {}
    MutantStack &operator=(const MutantStack &other)
    {
        if (this == &other)
            return *this;
        std::stack<T>::operator=(other);
    }
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() 
    { 
        return std::stack<T>::c.begin(); 
    }

    iterator end() 
    { 
        return std::stack<T>::c.end(); 
    }
};

#endif