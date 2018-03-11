#include <stdio.h>
#include <vector>
#include <string>
int evalRPN(std::vector<std::string> &tokens) {
	std::stack<int> numbers;
	//此处是C++11范围for循环，很好用
	for (auto token : tokens)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			int a, b, res;
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			if (token == "+")
				res = a + b;
			else if (token == "-")
				res = a - b;
			else if (token == "*")
				res = a*b;
			else
				res = a / b;
			numbers.push(res);
		}
		else
		{
			numbers.push(stoi(token));
		}
	}
	return numbers.top();	
}
