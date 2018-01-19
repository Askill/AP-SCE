#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	/*
	char *func_Name;
	func_Name = mxArrayToString(prhs[0]);
	double* tout = mxGetPr(prhs[4]);
	double* xout = mxGetPr(prhs[5]);*/

	double t0 = *mxGetPr(prhs[0]);
	double tfinal= *mxGetPr(prhs[1]);
	double x0 = *mxGetPr(prhs[2]);

	double 	theta_umg = 20,								//temp of room
			theta = x0,									//start temp
			h = 1,										//incremtens size
			t_start = t0, 								//start time
			t_end = tfinal, 							//end time
			t=t_start,									
			theta_dot = 0;

	int len = (t_end-t_start)/h+1;
	double* t_out = (double *)mxCalloc(len, sizeof(double));			//array cont. time stamps
	double* theta_out = (double *)mxCalloc(len, sizeof(double));		//array cont. temp


	t_out[0]=t_start;
	theta_out[0]=theta;
	
	for(int i = 1; t<t_end; i++)
	{
		theta_dot = -1*(theta-theta_umg)/2; //<- totally different from (-1/2)*(theta-theta_umg), because that doesn't work!
		theta += theta_dot*h;
		//debug output mexPrintf("%f \t %f \t %f \t %f\n",theta_dot, theta, theta_umg,h);
		t += h;
		t_out[i] = t;
		theta_out[i]= theta;
	}
	

// Output
	nlhs = 2;
	
	plhs[0] = mxCreateDoubleMatrix(1, len, mxREAL);
    memcpy(mxGetPr(plhs[0]), t_out, len*sizeof(double));	
	
	plhs[1] = mxCreateDoubleMatrix(1, len, mxREAL);
    memcpy(mxGetPr(plhs[1]), theta_out, len*sizeof(double));

		 
 return;
}

