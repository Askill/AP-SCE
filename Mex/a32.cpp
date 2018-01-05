#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	char *func_Name;
	func_Name = mxArrayToString(prhs[0]);
	
	double a = *mxGetPr(prhs[1]);
	double b = *mxGetPr(prhs[2]);
	int    limit= *mxGetPr(prhs[3]);
	
	double c;
		
//allocate memory
	mxArray *func_Input[1];
	mxArray *func_Outputs[1];
	
	func_Input[0] = mxCreateDoubleScalar(a); 		

//bisection
	for (int i = limit; i--;) 
	{
		double tempA, tempB, tempC;
		
		c = (a + b) / 2;
		
		func_Input[0] = mxCreateDoubleScalar(a);
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name);
		tempA = *mxGetPr(func_Outputs[0]);
		
		func_Input[0] = mxCreateDoubleScalar(b);
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name);
		tempB = *mxGetPr(func_Outputs[0]);
		
		func_Input[0] = mxCreateDoubleScalar(c);
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name);
		tempC = *mxGetPr(func_Outputs[0]);
		
		if(tempA*tempC > 0){ a = c; }
		if(tempC*tempB > 0){ b = c; }
	}

// Output
	plhs[0] = mxCreateDoubleScalar(c);
	
//free allocated memory
	mxDestroyArray(func_Input[0]);
	mxDestroyArray(func_Outputs[0]);
		 
 return;
}