#include "mex.h" 
#include "matrix.h"

void mexFunction(int nlhs, mxArray *plhs[], 		/* Output variables */
				 int nrhs, const mxArray *prhs[]) 	/* Input variables */
{

if (nrhs != 4 || ! mxIsNumeric (prhs[0]))
    mexErrMsgTxt ("ARG1 must be a 4 dimensional matrix");

if( mxGetNumberOfElements(prhs[0]) != mxGetNumberOfElements(prhs[1]) ||
	mxGetNumberOfElements(prhs[0]) != mxGetNumberOfElements(prhs[2]) ||
	mxGetNumberOfElements(prhs[0]) != mxGetNumberOfElements(prhs[3]))
	{
	mexErrMsgTxt ("arrays need to be of same size!");
	}
	
	double *heights, *d, *densities, *resistances;
	heights =  mxGetPr (prhs[0]);
	d =  mxGetPr (prhs[1]);
	densities =  mxGetPr (prhs[2]);
	resistances = mxGetPr(prhs[3]);

	double resistance = 0;
	for (int i = mxGetNumberOfElements(prhs[0]); i--;)
	{
		resistance = resistance + ((heights[i] / 1000) * resistances[i]) / ((d[i] / 20)*(d[i] / 20) * 3.14159265359);
	}

//return value
	plhs[0] = mxCreateDoubleScalar(resistance);

return;
}