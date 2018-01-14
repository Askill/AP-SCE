#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	char *func_Name;
	func_Name = mxArrayToString(prhs[0]);
	double t0 = *mxGetPr(prhs[1]);
	double tfinal= *mxGetPr(prhs[2]);
	double x0 = *mxGetPr(prhs[3]);
	double* tout = mxGetPr(prhs[4]);
	double* xout = mxGetPr(prhs[5]);
	
	double 	theta_umg = 20,								//temp of room
			theta = x0,									//start temp
			h = 1,										//incremtens size
			t_start = t0, 								//start time
			t_end = tfinal, 							//end time
			t=t_start,									
			theta_dot;
	double* t_out = (double *)mxCalloc((t_end-t_start)/h, sizeof(double));			//array cont. time stamps
	double* theta_out = (double *)mxCalloc((t_end-t_start)/h, sizeof(double));		//array cont. temp

	t_out[0]=t_start;
	theta_out[0]=theta;
	
	for(int i = 1; t<t_end; i++)
	{
		theta_dot = -1/2*(theta-theta_umg);
		theta += theta_dot*h;
		t += h;
		t_out[i] = t;
		theta_out = [i]= theta;
	}
	

	mxArray *func_Input[2];
	mxArray *func_Outputs[1]; 

	func_Input[0] = ;
	func_Input[1] = ;
	mexCallMATLAB(1, func_Outputs , 1 , func_Input , "plot");

// Output


		 
 return;
}