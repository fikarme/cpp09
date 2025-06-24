#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <stack>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;
using std::exception;
using std::runtime_error;
using std::stack;

void r(const string &msg);

class RPN {
public:
	~RPN();
	RPN();
	RPN(const RPN &cpy);
	RPN &operator=(const RPN &rhs);
	int calculate(const string &expr);

private:
	void performOperation(char op);

	stack<int> _nbrs;

	};

#endif
