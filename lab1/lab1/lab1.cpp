#include <iostream>
#include <math.h>
#include <list>
#include <iomanip>
#include <string>
#include <string.h>

#define STEP 0.1
#define INTERVALS 10

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


struct Interval
{
    Interval(double __a, double __b)
    {
        a = __a;
        b = __b;
    }
    double a;
    double b;
};

Interval swann(double x1, double x2, double h)
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
    std::cout << "a = " << x1 << " b = " << x2 << std::endl;
    return (Interval(x1, x2));
}


void uniSearch(double a, double b, double eps, int N)
{
    double yMin = f(a);
    double xMin = a;
    int i = 0;
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
        std::cout << i << ") x = " << xMin << " f = " << yMin << std::endl;
        i++;
    }
}

void newton(double x, double eps)
{
    double x1;
    int i = 0;
    do
    {
        x1 = x - df(x) / ddf(x);
        x = x1;
        std::cout << i << ") x = " << x1 << " f = " << f(x1) << std::endl;
        i++;
    } while (df(x1) > eps);

}

void goldenRatio(double a, double b, double eps)
{
    double x1, x2;
    int i = 0;
    do
    {
        x1 = b - (b - a) / fi;
        x2 = a + (b - a) / fi;
        f(x1) > f(x2) ? a = x1 : b = x2;
        std::cout << i << ") x = " << (a + b) / 2 << " f = " << f((a + b) / 2) << std::endl;
        i++;
    } while (fabs(a - b) > eps);
}

int main(int argc, char** argv)
{
    if (argc != 5)
    {
        std::cerr << "Using: " << argv[0] << " <left bound> <right bound> <x0> <epsilon>" << std::endl;
        return 0;
    }
    auto a = std::stod(argv[1]);
    auto b = std::stod(argv[2]);
    auto x0 = std::stod(argv[3]);
    auto eps = std::stod(argv[4]);

    std::cout << "f(x) = -4 * x + exp(fabs(x - 0.2) * x)" << std::endl;
    std::cout << "f'(x) = (2 * x - 0.2) * exp((x - 0.2) * x) - 4" << std::endl;
    std::cout << "f''(x) = 4 * pow(x - 0.1, 2) * exp(x * (x - 0.2)) + 2 * exp(x * (x - 0.2))" << std::endl;

    std::cout << std::endl << "Swann" << std::endl;
    auto interval = swann(a, b, STEP);
    std::cout << std::endl << "Uni" << std::endl;
    uniSearch(interval.a, interval.b, eps, INTERVALS);
    std::cout << std::endl << "Newton" << std::endl;
    newton(x0, eps);
    std::cout << std::endl << "Golden Ratio" << std::endl;
    goldenRatio(interval.a, interval.b, eps);
    std::cout << std::endl << "Done!" << std::endl;
}
