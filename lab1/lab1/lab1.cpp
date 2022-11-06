#include <iostream>
#include "algorithm.h"
#include "UniformSearch.h"
#include <math.h>
#include <list>
#include <iomanip>

const double fi = (1 + sqrt(5)) / 2; // "Золотое" число

double f(double x)
{
    return -4 * x + exp(fabs(x - 0.2) * x);
}

double df(double x)
{
    return (2 * x - 0.2) * exp((x - 0.2) * x) - 4;
}

double ddf(double x)
{
    return 4 * pow(x - 0.1, 2) * exp(x * (x - 0.2)) + 2 * exp(x * (x - 0.2));
}

double g(double x)
{
    return x - f(x) / df(x);
}

double swann(double x1, double x2, double h)
{
    x2 = x1 + h;
    if (f(x2) > f(x1))
    {
        h = -h;
        x2 = x1 + h;
    }
    while (f(x2) < f(x1))
    {
        x1 = x2;
        x2 = x1 + h;
        h = h * 2;
    }
    std::cout << "x1 = " << x1 << " x2 = " << x2 << std::endl;
    return (x2);
}


void uniSearch(double a, double b, double eps, int N)
{
    double yMin = f(a);
    double xMin = a;
    while (fabs(b - a) > eps)
    {
        for (double x = a + ((b - a) / N); x <= b; x += (b - a) / N)
        {
            double y = f(x);
            if (y < yMin)
            {
                xMin = x;
                yMin = y;
            }
        }
        a = xMin - (b - a) / N;
        b = xMin + (b - a) / N;
        std::cout << "Min = " << xMin << std::endl;
        std::cout << " Значение функции: " << yMin << std::endl;
    }
    std::cout << "Min = " << xMin << std::endl;
    std::cout << " Значение функции: " << yMin << std::endl;
}

void newton(double x, double eps)
{
    double f0 = f(x);
    double x1 = x;
    while (fabs(f(x1)) > eps)
    {
        x -= f0 / df(x1);
        f0 = f(x1);
        std::cout << "x = " << x << " f = " << f(x) << std::endl;
    }

}

void goldenRatio(double a, double b, double eps)
{
    double x1, x2;
    while (fabs(b - a) > eps) {
        x1 = b - (b - a) / fi;
        x2 = a + (b - a) / fi;
        f(x1) > f(x2) ? a = x1 : b = x2;
        std::cout << "x = " << (a + b) / 2 << " f = " << f((a + b) / 2) << std::endl;
    }   
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    swann(0, 3, 0.1);
    uniSearch(0.8, 1.6, 0.00001, 10);
    //newton(0.5, 0.001);
    goldenRatio(0.8, 1.6, 0.00001);
    std::cin.get();
}
