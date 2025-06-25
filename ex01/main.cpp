#include "RPN.hpp"

void r(const string &msg) {
	cerr << "\033[1;31mERROR: " << msg << "\033[0m" << endl;
}

int main(int ac, char **av) {
	if (ac != 2) {
		r("Error");
		return 1;
	}
	
	try
	{
		RPN rpn;
		int result = rpn.calculate(av[1]);
		cout << result << endl;
	}
	catch (const exception &e) { r(e.what()); return 1; }
	catch (...) { r("an unknown error occurred."); return 1; }

	return 0;
}
