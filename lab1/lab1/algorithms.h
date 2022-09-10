#pragma once

#include <iostream>

class Algorithms
{
public:
	Algorithms();
	~Algorithms();

	double swann(double& h, double& x1, double& x2);
	void uniformSearch(double a, double b, double eps, int N);

private:
	double myFunc(double x);
	double firstDerivative(double x);
	double secondDerivative(double x);

};

