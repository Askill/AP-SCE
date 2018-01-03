#include "mex.h" 
#include "matrix.h"


void mexFunction(int nlhs, mxArray *plhs[], 		/* Output variables */
				 int nrhs, const mxArray *prhs[]) 	/* Input variables */
{

if (nrhs != 3 || ! mxIsNumeric (prhs[0]))
    mexErrMsgTxt ("ARG1 must be a 3 dimensional matrix");

if( mxGetNumberOfElements(prhs[0]) != mxGetNumberOfElements(prhs[1]) ||
	mxGetNumberOfElements(prhs[0]) != mxGetNumberOfElements(prhs[2]))
	{
	mexErrMsgTxt ("arrays need to be of same size!");
	}
	
	double *heights, *d, *densities;
	heights =  mxGetPr (prhs[0]);
	d =  mxGetPr (prhs[1]);
	densities =  mxGetPr (prhs[2]);

	double mass = 0;
	for (int i = mxGetNumberOfElements(prhs[0]); i--;)
	{
		mass = mass + ((heights[i] / 10) * (d[i] / 20)*(d[i] / 20) * 3.14159265359 * densities[i]);
	}	
	
//return value
	plhs[0] = mxCreateDoubleScalar(mass);



return;
}