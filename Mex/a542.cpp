#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"
#include "math.h"
double g_von_theta(long double x, long double y)
{
	return -(x*x + y*y);
}

void mexFunction(int nlhs, mxArray *plhs[], 			// Output variables 
				 int nrhs, const mxArray *prhs[]) 		// Input variables 
{
	double x = -2, y = -2, 
	xnew, ynew,
	increments = 0.1,
	z = g_von_theta(x, y),
	znew = 0, zold = 1,
	zinitial = z;
	int xTOy = 1, iAThalf = 1000; 				//iAThalf: max iterations/2
int i;
	for( i = 0 ; i <= 2 * iAThalf + 1; ++i) // add. exit crit. needed
	{
		if (xTOy == 1)
		{
			xnew = x;
			ynew = y;
			if (zinitial / 2 == z)				//appropriate criteria?
			{
				iAThalf = i;
				ynew = y + increments;
			}
			else
				xnew = x + increments;
		}
		else
		{
			xnew = x;
			ynew = y + increments;
		}

		znew = g_von_theta(xnew, ynew);
		zold = z;
		if(znew > z)
		{
			z = znew;
			x = xnew;
			y = ynew;
		}
		else
			if (xTOy == 1)
				xTOy = 2;		
	}
	
	// Output
	plhs[0] = mxCreateDoubleScalar(x);
	plhs[1] = mxCreateDoubleScalar(y);
	plhs[2] = mxCreateDoubleScalar(z);
	plhs[3] = mxCreateDoubleScalar(i);
return;
}