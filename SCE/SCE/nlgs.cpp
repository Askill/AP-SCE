#include "nlgs.h"
#include "math.h"
#include <iostream>
using namespace std;


long double nlgs::function(long double x)
{
	return (pow(x, 4) - x - 10);
}

long double nlgs::round(long double x, int acc) 
{
	x = x * pow(10, acc);
	int temp = x;
	x = temp;
	x = x / pow(10, acc);
	return x;
}

float nlgs::bisektion(long double A, long double B , int limit, int acc)
{
	long double a = A;
	long double b = B;
	long double c;
	for (int i = limit; i--;) 
	{
		c = (a + b) / 2;
		c = round(c, acc);
		if (function(a)*function(c) > 0) { a = c; }
		if (function(c)*function(b) > 0) { b = c; }
	}
}

