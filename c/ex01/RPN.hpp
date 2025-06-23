#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN {
private:
    std::stack<int> _numbers;

public:
    RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);
    ~RPN();

    int calculate(const std::string &expression);

private:
    bool isOperator(char c) const;
    void performOperation(char op);
};

#endif