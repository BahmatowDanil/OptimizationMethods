#pragma once

class Algorithms
{
public:
	Algorithms();
	~Algorithms();

	double swann(double& h, double& x1, double& x2);

private:
	double myFunc(double x);
	double firstDerivative(double x);
	double secondDerivative(double x);

};

