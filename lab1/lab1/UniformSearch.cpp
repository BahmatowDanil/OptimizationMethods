#include "UniformSearch.h"

void UniformSearch::calc(double a, double b, double eps, int N)
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

void UniformSearch::printName()
{
    std::cout << "Using method: Uniform Search" << std::endl;
}


