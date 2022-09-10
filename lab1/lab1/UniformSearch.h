#pragma once
#include "algorithm.h"
class UniformSearch : public Algorithm
{
	virtual void calc(double a, double b, double eps, int N) override;
	virtual void printName() override;
};

