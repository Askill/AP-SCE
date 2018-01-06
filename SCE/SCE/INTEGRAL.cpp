#include "INTEGRAL.h"
#include <cmath>
using namespace std;

INTEGRAL::INTEGRAL()
{
}
INTEGRAL::~INTEGRAL()
{
}

long double INTEGRAL::funkt(long double x)
{
	return sin(x);
}

long double INTEGRAL::trapz(long double x0, long double x1, long double precision)
{
	long double A = 0, a = x0, b = a + precision;
	
	for(; a < x1; a += precision, b += precision)
	{
		A += (b - a)*((funkt(b) + funkt(a))/2);
		
	}

	return A;
}

long double INTEGRAL::quad(/*long double (* funk)(long double), */long double x0, long double x1, long double precision)
{
	long double A = 0, a = x0;
	int fak = 1;

	for (int i = 0; a < x1; a += precision, i++)
	{
		A += fak*funkt(a);
		i % 2 ? fak = 2 : fak = 4;
	}
	A += funkt(a);
	return A*precision/3;
}


