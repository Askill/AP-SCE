#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	if (nrhs != 4)
    mexErrMsgTxt ("Check your input parameters");
	

	char *func_Name;
	func_Name = mxArrayToString(prhs[0]);
	
	double a = *mxGetPr(prhs[1]);
	double x1= *mxGetPr(prhs[2]);
	double precision = *mxGetPr(prhs[3]);
	double b = a + precision;
	double A=0;
	
	
//trapz
	mxArray *func_Input[1];
	mxArray *func_Outputs[1]; 

	for(; a < x1; a += precision, b += precision)
	{
		double yb,ya;
		
		func_Input[0] = mxCreateDoubleScalar(a);
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name);
		ya = *mxGetPr(func_Outputs[0]);
		
		func_Input[0] = mxCreateDoubleScalar(b);
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name);
		yb = *mxGetPr(func_Outputs[0]);
		
		A += (b - a)*((yb + ya)/2);
		
	}

// Output
	plhs[0] = mxCreateDoubleScalar(A);
	
//free allocated memory
	mxDestroyArray(func_Input[0]);
	mxDestroyArray(func_Outputs[0]);
	
	

		 
 return;
}