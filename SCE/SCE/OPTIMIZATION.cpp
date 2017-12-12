#include "OPTIMIZATION.h"

OPTIMIZATION::OPTIMIZATION()
{
}
OPTIMIZATION::~OPTIMIZATION()
{
}

long double OPTIMIZATION::g_von_theta(long double x, long double y)
{
	return -(2*x + y*y);
}

