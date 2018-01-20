#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	if (nrhs != 3 || ! mxIsNumeric (prhs[0]))
    mexErrMsgTxt ("Check your input parameters");

	char *func_Name;
	func_Name = mxArrayToString(prhs[0]);
	
	double start = *mxGetPr(prhs[1]);
	int    limit= *mxGetPr(prhs[2]);
	
//allocate memory
	mxArray *func_Inputs[1];
	mxArray *func_Outputs[1];
	func_Inputs[0] = mxCreateDoubleScalar(start); 			
	
	for(int i = limit ; i-- ;)
	{
		func_Inputs[0] = mxCreateDoubleScalar(start);
		mexCallMATLAB(1, func_Outputs , 1 , func_Inputs , func_Name);		  
		start = *mxGetPr(func_Outputs[0]);
	}

// Output
	plhs[0] = mxCreateDoubleScalar(start);
	
//free allocated memory
	mxDestroyArray(func_Inputs[0]);
	mxDestroyArray(func_Outputs[0]);
		 
 return;
}