#include "RPN.hpp"

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

		if (c == ' ')
			continue;
		if (expr[i+1])
			if (expr[i+1] != ' ')
				throw runtime_error("must be a space after ops");
		if (c >= '0' && c <= '9')
			_nbrs.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (i < 4)
				throw runtime_error("not enough operands for operation");
			if (c == '/' && _nbrs.top() == 0)
				throw runtime_error("unidentified (division by zero)");
			applyOp(c);
		}
	}

	return _nbrs.top();
}

void RPN::applyOp(char op) {
	int b = _nbrs.top();
	_nbrs.pop();
	int a = _nbrs.top();
	_nbrs.pop();

	switch (op)
	{
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
		_nbrs.push(a / b);
		break;
	}
}
