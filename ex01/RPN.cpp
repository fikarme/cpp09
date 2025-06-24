#include "RPN.hpp"

void r(const string &msg) {
	cerr << "\033[1;31mERROR: " << msg << "\033[0m" << endl;
}

RPN::~RPN() {}

RPN::RPN() {}

RPN::RPN(const RPN &cpy) {
	*this = cpy;
}

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs)
		_nbrs = rhs._nbrs;
	return *this;
}

int RPN::calculate(const string &expr) {
	for (size_t i = 0; i < expr.length(); i++) {
		char c = expr[i];

		if (isspace(c))
			continue;

		if (isdigit(c))
			_nbrs.push(c - '0');

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			performOperation(c);
		}
		else {
			r("Invalid character in expression");
			throw runtime_error("Invalid character in expression");
		}
	}

	if (_nbrs.size() != 1) {
		r("The expression is not valid");
		throw runtime_error("The expression is not valid");
	}

	return _nbrs.top();
}

void RPN::performOperation(char op) {
	if (_nbrs.size() < 2) {
		r("Not enough operands for operation");
		throw runtime_error("Not enough operands for operation");
	}
	
	int b = _nbrs.top();
	_nbrs.pop();
	int a = _nbrs.top();
	_nbrs.pop();
	switch (op) {
	case '+':
		_nbrs.push(a + b);
		break;
	case '-':
		_nbrs.push(a - b);
		break;
	case '*':
		_nbrs.push(a * b);
		break;
	case '/':
		if (b == 0) {
			r("Division by zero");
			throw runtime_error("Division by zero");
		}
		_nbrs.push(a / b);
		break;
	default:
		r("Unknown operator");
		throw runtime_error("Unknown operator");
	}
	
}
