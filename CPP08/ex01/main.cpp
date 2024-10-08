#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;

        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        try
        {
            sp.addNumber(12);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        std::vector<int> extraNumbers(10000);
        std::srand(time(NULL));
        std::generate(extraNumbers.begin(), extraNumbers.end(), std::rand);

        Span span(extraNumbers.size());
        Span sp2(7);
        sp2.addNumber(1);
        sp2.addLots(extraNumbers.begin(), extraNumbers.end());
        std::cout << "sp2 Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "sp2 Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}