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

void Algorithms::uniformSearch(double a, double b, double eps, int N)
{
    double yMin = myFunc(a);
    double xMin = a;
    while (fabs(b - a) > eps)
    {
        for (double x = a + ((b - a) / N); x <= b; x += (b - a) / N)
        {
            double y = myFunc(x);
            if (y < yMin)
            {
                xMin = x;
                yMin = y;
            }
        }
        a = xMin - (b - a) / N;
        b = xMin + (b - a) / N;
    }
    std::cout << "Min = " << xMin << std::endl;
    std::cout << " Значение функции: " << yMin << std::endl;
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
