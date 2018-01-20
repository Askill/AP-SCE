#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"

void mexFunction(int nlhs, mxArray *plhs[], 			// Output variables 
				 int nrhs, const mxArray *prhs[]) 		// Input variables 
{
	if (nrhs != 2 || ! mxIsNumeric (prhs[0]))
    mexErrMsgTxt ("Check your input parameters");

	int variables = *mxGetPr(prhs[0]);
	
	double* x = (double *)mxCalloc(variables+1, sizeof(double));					//create solution array
	
	double** GA = (double **)mxCalloc(variables+1, sizeof(double*));			//create Gauss Array (GA)
	for (int i = 0; i <= variables; i++){
		GA[i] = (double *)mxCalloc(variables+1, sizeof(double));
	}
	
	for(int i = 0; i < variables*(variables+1); i++){							//copy input array into GA								
		GA[i%variables][i/variables] = mxGetPr(prhs[1])[i];	
	}
	
// Gauß
	for (int i = 0; i<variables; i++)					//Pivotisation
		for (int k = i + 1; k<variables; k++)
			if (abs(GA[i][i])<abs(GA[k][i]))
				for (int j = 0; j <= variables; j++)
				{
					long double temp = GA[i][j];
					GA[i][j] = GA[k][j];
					GA[k][j] = temp;
				}

	for (int i = 0; i<variables - 1; i++)				//gauss elimination
		for (int k = i + 1; k<variables; k++)
		{
			long double t = GA[k][i] / GA[i][i];
			for (int j = 0; j <= variables; j++)
				GA[k][j] = GA[k][j] - t*GA[i][j];		//make the elements below the pivot elements equal to zero or elimnate the variables
		}

	for (int i = variables - 1; i >= 0; i--)            //back-substitution
	{													//x is an array whose values correspond to the values of x,y,z..
		x[i] = GA[i][variables];						//make the variable to be calculated equal to the rhs of the last equation
		for (int j = i + 1; j<variables; j++)
			if (j != i)									//then subtract all the lhs values except the coefficient of the variable whose value is being calculated
				x[i] = x[i] - GA[i][j] * x[j];
		x[i] = x[i] / GA[i][i];							//now finally divide the rhs by the coefficient of the variable to be calculated
	}

//Output
	nlhs = 1;
	plhs[0] = mxCreateDoubleMatrix(1, variables, mxREAL);
    memcpy(mxGetPr(plhs[0]), x, variables*sizeof(double));

return;
}