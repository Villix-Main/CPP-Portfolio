#include <iostream>


class DoSomething
{
private:
	int a;

public:
	DoSomething(int a) 
		: a {a} { }

	int operator() (int b) const
	{
		return a * b;
	}
};


void RunLambdaExpressionsFile()
{
	DoSomething something(3);
	std::cout << something(43);
}