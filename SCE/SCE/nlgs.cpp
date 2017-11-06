#include "nlgs.h"
#include "math.h"
#include <iostream>
using namespace std;


long double nlgs::function(long double x)
{
	return (pow(x, 4) - x - 10);
}

long double nlgs::function_fixedpoint(long double x)
{
	return pow(x+10, 1/4);
}

long double nlgs::function_derived(long double x)
{
	return 4 * pow(x, 3) - 1;
}



long double  nlgs::bisektion(long double A, long double B , int limit)
{
	long double a = A, b = B, c;
	for (int i = limit; i--;) 
	{
		c = (a + b) / 2;
		if (function(a)*function(c) > 0) { a = c; }
		if (function(c)*function(b) > 0) { b = c; }
	}
	return c;
}

long double  nlgs::fixedpoint(long double start, int limit)
{
	long double x = start;
	for(int i = limit ; i-- ;)
	{
		x = function_fixedpoint(x);
	}
	return x;
}

long double  nlgs::newton(long double start, int limit)
{
	long double x = start;
	for (int i = limit; i--;)
	{
		x = x - function(x)/function_derived(x);
	}
	return x;
}




