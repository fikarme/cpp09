#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) {
	*this = copy;
	}

RPN &RPN::operator=(const RPN &copy) {
	if (this != &copy)
		this->_numbers = copy._numbers;
	return *this;
	}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
	}

void RPN::performOperation(char op) {
	if (_numbers.size() < 2)
		throw std::runtime_error("Error: Not enough operands");

	int b = _numbers.top();
	_numbers.pop();
	int a = _numbers.top();
	_numbers.pop();

	switch (op) {
		case '+':
			_numbers.push(a + b);
			break;
		case '-':
			_numbers.push(a - b);
			break;
		case '*':
			_numbers.push(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			_numbers.push(a / b);
			break;
		}
	}

int RPN::calculate(const std::string &expression) {
	for (size_t i = 0; i < expression.length(); i++) {
		char c = expression[i];

		if (std::isspace(c))
			continue;

		if (std::isdigit(c)) {
			_numbers.push(c - '0');
			}
		else if (isOperator(c)) {
			performOperation(c);
			}
		else {
			throw std::runtime_error("Error: Invalid character");
			}
		}

	if (_numbers.size() != 1)
		throw std::runtime_error("Error: Invalid expression");

	return _numbers.top();
	}
