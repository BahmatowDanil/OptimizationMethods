#include <iostream>
#include "algorithm.h"
#include "UniformSearch.h"
#include <math.h>
#include <list>


int main()
{
    auto methods = std::list<Algorithm*>();
    methods.push_back(new UniformSearch);

    for (auto method : methods)
    {
        method->printName();
        //method->calc(0, 10, 0.01, 2); //dont work
    }
}
