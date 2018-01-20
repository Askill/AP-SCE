#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"
#include "math.h"
double g_von_theta(long double x, long double y, char * func_Name)
{
																		//-(x*x + y*y);
	mxArray *func_Inputs[2];
	mxArray *func_Outputs[1];
	func_Inputs[0] = mxCreateDoubleScalar(x); 			
	func_Inputs[1] = mxCreateDoubleScalar(y);
	mexCallMATLAB(1, func_Outputs , 2 , func_Inputs , func_Name);		  
	return *mxGetPr(func_Outputs[0]);

}

void mexFunction(int nlhs, mxArray *plhs[], 			// Output variables 
				 int nrhs, const mxArray *prhs[]) 		// Input variables 
{

	if (nrhs != 4)
    mexErrMsgTxt ("Check your input parameters");
	
	char *func_Name;
	func_Name = mxArrayToString(prhs[0]);
														//x = -2, y = -2
	double x = *mxGetPr(prhs[1]);
	double y = *mxGetPr(prhs[2]);
	double increments = *mxGetPr(prhs[3]);

	double	xnew, ynew,
	z = g_von_theta(x, y, func_Name),
	znew = 0, zold = 1,
	zinitial = z;
	int xTOy = 1, iAThalf = 1000; 				//iAThalf: max iterations/2

	for(int i = 0 ; i <= 2 * iAThalf + 1; ++i) 	// add. exit crit. needed
	{
		if (xTOy == 1)
		{
			xnew = x;
			ynew = y;
			if (zinitial / 2 == z)				
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

		znew = g_von_theta(xnew, ynew, func_Name);
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

return;
}