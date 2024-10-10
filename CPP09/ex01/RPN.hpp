#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<float> _stack;
	public:
		RPN();
		RPN(const RPN& rhs);
		~RPN();
		RPN& operator=(const RPN& rhs);

		void calculate(const std::string& str);
		bool check(const std::string& str);
		
};

#endif