#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		r("Error: An inverted Polish mathematical expression as an argument required.");
		return 1;
	}
	
	try
	{
		RPN rpn;
		int result = rpn.calculate(av[1]);
		cout << result << endl;
	}
	catch (const exception &e) { r(e.what()); return 1; }

	return 0;
}
#include <iostream>
