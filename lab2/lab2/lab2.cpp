#include <iostream>
#include <math.h>

constexpr double lambda = 0.335;

struct vector
{
    double x1, x2;
};

struct revG
{
    const double detG = 4;
    double x0 = 2;
    double x1 = 2;
    double x2 = 2;
    double x3 = 4;
};

double fx(vector v)
{
    return pow((v.x2 - v.x1), 2) + pow((1 - v.x1), 2);
}

vector gradient(vector v)
{
    vector grad;

    grad.x1 = 4 * v.x1 - 2 * v.x2 - 2;
    grad.x2 = -2 * v.x1 + 2 * v.x2;

    return grad;
}

vector calcForKoshi(vector x, vector gradient, double lambda)
{
    vector buffer;

    buffer.x1 = x.x1 - lambda * gradient.x1;
    buffer.x2 = x.x2 - lambda * gradient.x2;

    return buffer;
}

vector calcForNewton(vector x, revG g, vector grad)
{
    revG gAfterMult;

    gAfterMult.x0 = g.x0 * (1 / g.detG);
    gAfterMult.x1 = g.x1 * (1 / g.detG);
    gAfterMult.x2 = g.x2 * (1 / g.detG);
    gAfterMult.x3 = g.x3 * (1 / g.detG);

    vector rRes;
    rRes.x1 = gAfterMult.x0 * grad.x1 + gAfterMult.x1 * grad.x2;
    rRes.x2 = gAfterMult.x2 * grad.x1 + gAfterMult.x3 * grad.x2;

    vector lRes;
    lRes.x1 = x.x1 - rRes.x1;
    lRes.x2 = x.x2 - rRes.x2;

    return lRes;
}

vector newton(vector v, double eps)
{
    const revG g;
    vector current = v;
    vector last;

    int iter = 0;
    while (sqrt(pow(gradient(current).x1, 2) + pow(gradient(current).x2, 2)) > eps)
    {
        last = current;
        current = calcForNewton(current, g, gradient(v));
        std::cout << iter << ") " << " x1 = " << current.x1 << " x2 = " << current.x2 << std::endl;
        iter++;
    }

    return current;
}

vector koshi(vector x, double eps, double lambda) 
{
    vector current = x;
    vector last;

    int iter = 0;
    do
    {
        last = current; 
        vector grad = gradient(current); 
        current = calcForKoshi(current, grad, lambda); 
        std::cout  << iter << ") " << " x1 = " << current.x1 << " x2 = " << current.x2 << std::endl;
        iter++;
    } while (std::fabs(current.x1 - last.x1) > eps || std::fabs(current.x2 - last.x2) > eps);

    return current;
}

int main()
{
    vector v{ 0, 0 };
    double eps;

    std::cout << "f(x) = (x2 - x1)^2 + (1 - x1)^2" << std::endl;

    std::cout << "Input x1 = ";
    std::cin >> v.x1;
    std::cout << "Input x2 = ";
    std::cin >> v.x2;
    std::cout << "Input eps = ";
    std::cin >> eps;

    std::cout << std::endl;

    std::cout << "Newton" << std::endl;
    vector res = newton(v, eps);
    std::cout << "Newton: x1 = " << res.x1 << " x2 = " << res.x2 << std::endl;

    std::cout << std::endl;

    std::cout << "Koshi" << std::endl;
    res = koshi(v, eps, lambda);
    std::cout << "Koshi: x1 = " << res.x1 << " x2 = " << res.x2 << std::endl;
}

