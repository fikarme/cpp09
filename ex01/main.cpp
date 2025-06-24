#include "RPN.hpp"

int main(int ac, char **av) {
	try
	{
		RPN rpn;
		int result = rpn.calculate("8 9 * 9 - 9 - 9 - 4 - 1 +");
		cout << result << endl;
		result = rpn.calculate("7 7 * 7 -");
		cout << result << endl;
		result = rpn.calculate("1 2 * 2 / 2 * 2 4 - +");
		cout << result << endl;
		result = rpn.calculate("(1 + 1)");
		cout << result << endl; // This should throw an error
		result = rpn.calculate("1 2 + 3 *");
		cout << result << endl; // This should also throw an error
		result = rpn.calculate("1 2 + 3 * 4");
		cout << result << endl; // This should also throw an error
		result = rpn.calculate("1 2 + 3 * 4 -");
		cout << result << endl; // This should also throw an error
	}
	catch (const exception &e) { r(e.what()); return 1; }
	catch (...) { r("an unknown error occurred."); return 1; }
	
	(void)ac; // To avoid unused parameter warning
	(void)av; // To avoid unused parameter warning
	// if (ac != 2) {
	// 	r("Error");
	// 	return 1;
	// }
	
	// try
	// {
	// 	RPN rpn;
	// 	int result = rpn.calculate(av[1]);
	// 	cout << result << endl;
	// }
	// catch (const exception &e) { r(e.what()); return 1; }
	// catch (...) { r("an unknown error occurred."); return 1; }

	return 0;
}
