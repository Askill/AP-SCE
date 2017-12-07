#pragma once
class NLGS
{
private:
	long double function(long double);
	long double function_fixedpoint(long double );
	long double function_derived(long double);

public:
	long double bisektion(long double, long double, int);		//a, b, number of iterations
	long double fixedpoint(long double, int);					//start, number of iterations
	long double newton(long double, int);						//start, number of iterations
	long double secant(long double, long double, int);			//a, b, number of iterations
	NLGS(){};
	~NLGS(){};
};

