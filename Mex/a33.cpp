#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	if (nrhs != 4)
    mexErrMsgTxt ("Check your input parameters");

	char *func_Name_1;
	func_Name_1 = mxArrayToString(prhs[0]);
	char *func_Name_2;
	func_Name_2 = mxArrayToString(prhs[1]);
	
	double x = *mxGetPr(prhs[2]);
	
	int    limit= *mxGetPr(prhs[3]);
	
//allocate memory
	mxArray *func_Input[1];
	mxArray *func_Outputs[1];
	
			

//bisection
	for (limit; limit--;)
	{
		double temp_func_1, temp_func_2;
		
		func_Input[0] = mxCreateDoubleScalar(x); 
		
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name_1);	//f(x)
		temp_func_1 = *mxGetPr(func_Outputs[0]);
		
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name_2);	//f'(x)
		temp_func_2 = *mxGetPr(func_Outputs[0]);
		
		x = x - temp_func_1/temp_func_2;
	}

// Output
	plhs[0] = mxCreateDoubleScalar(x);
	
//free allocated memory
	mxDestroyArray(func_Input[0]);
	mxDestroyArray(func_Outputs[0]);
		 
 return;
}