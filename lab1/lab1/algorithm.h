#pragma once

#include <iostream>

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	virtual void calc(double a, double b, double eps, int N) = 0;
	virtual void printName() = 0;

	double swann(double& h, double& x1, double& x2);

protected:
	double myFunc(double x);
	double firstDerivative(double x);
	double secondDerivative(double x);

};

