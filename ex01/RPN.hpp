#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::runtime_error;
using std::stack;

class RPN {
public:
	~RPN();
	RPN();
	RPN(const RPN &cpy);
	RPN &operator=(const RPN &rhs);
	int calculate(const string &expr);

private:
	void applyOp(char op);
	stack<int> _nbrs;

};

#endif
