#pragma once
class nlgs
{
private:
	long double function(long double);
	long double round(long double, int);
public:
	float bisektion(long double, long double, int, int );		//a, b, number of iterations, accuracy
	float fixedpoint();
	float newton();
	float secant();
	nlgs(){};
	~nlgs(){};
};

