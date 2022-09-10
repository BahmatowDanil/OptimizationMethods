#include "algorithms.h"
#include <math.h>

Algorithms::Algorithms()
{
}

Algorithms::~Algorithms()
{
}

double Algorithms::swann(double& h, double& x1, double& x2)
{
    x2 = x1 + h;
    if (myFunc(x2) > myFunc(x1))
    {
        h = -h;
        x2 = x1 + h;
    }
    while (myFunc(x2) < myFunc(x1))
    {
        x1 = x2;
        x2 = x1 + h;
        h = h * 2;
    }
    return (x2);
}

double Algorithms::myFunc(double x)
{
	return -4 * x + exp(fabs(x - 0.2) * x);
}

double Algorithms::firstDerivative(double x)
{
	return (2 * x - 0.2) * exp((x - 0.2) * x) - 4;
}

double Algorithms::secondDerivative(double x)
{
	return 4 * pow(x - 0.1, 2) * exp(x * (x - 0.2)) + 2 * exp(x * (x - 0.2));
}
