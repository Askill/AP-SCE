#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	char *func_Name;
	func_Name = mxArrayToString(prhs[0]);
	
	double a = *mxGetPr(prhs[1]);
	double x1= *mxGetPr(prhs[2]);
	double precision = *mxGetPr(prhs[3]);
	double A=0;
	
	int fak = 1;
	
	double ya = 0;
	
	
//quad
	mxArray *func_Input[1];
	mxArray *func_Outputs[1]; 

	for(int i = 0; a < x1; a += precision,i++)
	{
		func_Input[0] = mxCreateDoubleScalar(a);
		mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name);
		ya = *mxGetPr(func_Outputs[0]);
		A += fak*ya;
		
		
		if(i%2)			
			fak=2;
		else
			fak=4;
	}
	
	func_Input[0] = mxCreateDoubleScalar(a);
	mexCallMATLAB(1, func_Outputs , 1 , func_Input , func_Name);
	ya = *mxGetPr(func_Outputs[0]);
		
	A += ya;
	A = A*precision/3;

// Output
	plhs[0] = mxCreateDoubleScalar(A);
	
//free allocated memory
	mxDestroyArray(func_Input[0]);
	mxDestroyArray(func_Outputs[0]);
		 
 return;
}