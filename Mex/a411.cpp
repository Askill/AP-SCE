#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"
#include "math.h"

void mexFunction(int nlhs, mxArray *plhs[], 			// Output variables 
				 int nrhs, const mxArray *prhs[]) 		// Input variables 
{
	if (nrhs != 4)
    mexErrMsgTxt ("Check your input parameters");
	if( mxGetNumberOfElements(prhs[2]) != mxGetNumberOfElements(prhs[3]))
	{
	mexErrMsgTxt ("arrays need to be of same size!");
	}

	int variables = *mxGetPr(prhs[0]);
	double inc = *mxGetPr(prhs[1]);
	
	double* x = (double *)mxCalloc(variables, sizeof(double));					//create solution array
	
	double* x_in = (double *)mxCalloc(variables, sizeof(double));				//input x
	double* y = (double *)mxCalloc(variables, sizeof(double));					//input y
	
	double** GA = (double **)mxCalloc(variables+1, sizeof(double*));			//create Gauss Array (GA)
	for (int i = 0; i <= variables; i++){
		GA[i] = (double *)mxCalloc(variables+1, sizeof(double));
	}
	
	for(int i=0;i<variables;i++){
		x_in[i]=mxGetPr(prhs[2])[i];
	}
	for(int i=0;i<variables;i++){
		y[i]=mxGetPr(prhs[3])[i];
	}
	
	for(int i=0;i<variables;i++){											//fill GA with the polynoms
		for(int j=0; j<variables;j++){
			GA[i][j] = pow(x_in[i],j);
		}
	}
	for(int i=0;i<variables;i++){											
		GA[i][variables] = y[i];
	}

	double len = (x_in[variables-1]-x_in[0])/inc +1;
	
	double* xx = (double *)mxCalloc(len, sizeof(double));					//return array with x values
	double* yy = (double *)mxCalloc(len, sizeof(double));					//return array with interpolated y values
	
	double temp=x_in[0];
	for(int i=0;temp <= x_in[variables-1]+inc;i++){							//generate return array with x values
		xx[i]=temp;
		temp += inc;
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

//polyval: filling yy with the interpolated values

	for (int i = 0; i < len; i++){
		double tmp = 0;
		for (int j = 0; j < variables; j++){
			tmp += pow(xx[i], j) * x[j];
		}
		yy[i]=tmp;
	}

//return values
	nlhs = 2;
	
	plhs[0] = mxCreateDoubleMatrix(1, len, mxREAL);
    memcpy(mxGetPr(plhs[0]), xx, len*sizeof(double));	
	
	plhs[1] = mxCreateDoubleMatrix(1, len, mxREAL);
    memcpy(mxGetPr(plhs[1]), yy, len*sizeof(double));

//free memory 

// causes errors
return;
}