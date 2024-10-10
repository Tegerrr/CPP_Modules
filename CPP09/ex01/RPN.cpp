#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& rhs) {
	*this = rhs;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& rhs) {
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

bool RPN::check(const std::string& str) {
	for (std::string::size_type i = 0; i < str.length(); ++i) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			return true;
	}
	return false;
}

void RPN::calculate(const std::string& str) {
	if (!check(str)) {
		std::cout << "Error: Invalid expression" << std::endl;
		return;
	}
	std::string::size_type i = 0;
	while (i < str.length()) {
		if (str[i] == ' ')
			++i;
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (this->_stack.size() < 2) {
				std::cout << "Error: Invalid expression" << std::endl;
				return;
			}
			float a = this->_stack.top();
			this->_stack.pop();
			float b = this->_stack.top();
			this->_stack.pop();
			if (str[i] == '+')
				this->_stack.push(b + a);
			else if (str[i] == '-')
				this->_stack.push(b - a);
			else if (str[i] == '*')
				this->_stack.push(b * a);
			else if (str[i] == '/')
			{
				if (a == 0) {
					std::cout << "Error: Division by zero" << std::endl;
					return;
				}
				this->_stack.push(b / a);
			}
			++i;
		} else {
			int num = 0;
			while (i < str.length() && str[i] != ' ') {
				if (str[i] < '0' || str[i] > '9') {
					std::cout << "Error: Invalid expression" << std::endl;
					return;
				}
				num = num * 10 + str[i] - '0';
				++i;
			}
			this->_stack.push(num);
		}
	}
	if (this->_stack.size() != 1) {
		std::cout << "Error: Invalid expression" << std::endl;
		return;
	}
	std::cout << this->_stack.top() << std::endl;
}
