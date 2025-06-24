#include "RPN.hpp"

int main(int ac, char **av) {
	try
	{
		RPN rpn;
		int result = rpn.calculate("8 9 * 9 - 9 - 9 - 4 - 1 +");
		cout << result << endl;
		
		RPN rpn2;
		result = rpn2.calculate("7 7 * 7 -");
		cout << result << endl;
		
		RPN rpn3;
		result = rpn3.calculate("1 2 * 2 / 2 * 2 4 - +");
		cout << result << endl;
		
		RPN rpn4;
		result = rpn4.calculate("(1 + 1)");
		cout << result << endl; // This should throw an error
		
		RPN rpn5;
		result = rpn5.calculate("1 2 + 3 *");
		cout << result << endl; // This should also throw an error
		
		RPN rpn6;
		result = rpn6.calculate("1 2 + 3 * 4");
		cout << result << endl; // This should also throw an error
		
		RPN rpn7;
		result = rpn7.calculate("1 2 + 3 * 4 -");
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
