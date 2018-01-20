#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"



void mexFunction(int nlhs, mxArray *plhs[], 			// Output  
				 int nrhs, const mxArray *prhs[]) 		// Input  
{
	if (nrhs != 3)
    mexErrMsgTxt ("Check your input parameters");
	if( mxGetNumberOfElements(prhs[1]) != mxGetNumberOfElements(prhs[2]))
	{
	mexErrMsgTxt ("arrays need to be of same size!");
	}

	int num_data_points = *mxGetPr(prhs[0]);
	
	double* x = (double *)mxCalloc(num_data_points, sizeof(double));
	double* y = (double *)mxCalloc(num_data_points, sizeof(double));
	double* temp = (double *)mxCalloc(num_data_points, sizeof(double));
	
	for(int j=0; j < num_data_points; j++)
	{
		x[j] = mxGetPr(prhs[1])[j];
		y[j] = mxGetPr(prhs[2])[j];
	}
	
//Mid-diff
	int i = 0;

	temp[i] = (y[i+1] - y[i]) / (x[i+1] - x[i]);
	i++;
	temp[i] = (y[i+1] - y[i]) / (x[i+1] - x[i]);
	temp[i]  += (y[i+1] - y[i-1]) / (x[i+1] - x[i-1]);
	temp[i]  /= 2;

	for (; i < num_data_points - 2; ++i)
	{
		temp[i] = (y[i+1] - y[i-1] ) / (x[i+1] - x[i-1]);
	}

	temp[i] += (y[i] - y[i-1]) / (x[i] - x[i-1]);
	temp[i] /= 2;
	i++;
	temp[i] = (y[i] - y[i-1]) / (x[i] - x[i-1]);

// Output
	nlhs = 1;
	plhs[0] = mxCreateDoubleMatrix(1, num_data_points, mxREAL);
    memcpy(mxGetPr(plhs[0]), temp, num_data_points*sizeof(double));	

		 
 return;
}