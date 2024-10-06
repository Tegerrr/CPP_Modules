#ifndef easyfind_hpp
#define easyfind_hpp

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
int easyFind(const T& container, int n)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::out_of_range("Element not found in the container");
    return *it;
}

#endif 
