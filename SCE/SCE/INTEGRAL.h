#pragma once
class INTEGRAL
{
public:
	INTEGRAL();
	~INTEGRAL();
	long double funkt(long double);
	long double trapz(long double, long double, long double);
	long double quad(/*long double (*funk)(long double), */long double, long double, long double);
};

