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
	variables++;
	double inc = *mxGetPr(prhs[1]);

		
	double* x = (double *)mxCalloc(variables, sizeof(double));
	double* y = (double *)mxCalloc(variables, sizeof(double));
	
	for(int i=0;i<variables-1;i++){
		x[i]=mxGetPr(prhs[2])[i];
	}
	x[variables-1]=x[variables-2];
	x[variables-1]+=inc;

	for(int i=0;i<variables-1;i++){
		y[i]=mxGetPr(prhs[3])[i];
	}

	y[variables-1]=y[variables-2];

	
	double len = (x[variables-1]-x[0])/inc +1;
	
	double* xx = (double *)mxCalloc(len, sizeof(double));
	double* yy = (double *)mxCalloc(len, sizeof(double));
	
	double temp=x[0];
	for(int i=0;temp <= x[variables-1]+inc;i++){
		xx[i]=temp;
		temp += inc;
	}
	
	
//Code von Marvin Lehmann start
	unsigned int savepoint = 0;

	// Zwischen jeweils 2 Punkten
	for (unsigned int i = 0; i < variables-1; i++)
	{
		// Für alle Zwischenwerte (xx) y interpolieren (yy)
		for (unsigned int j = savepoint; j < len; j++)
		{
			if (xx[j] >= x[i] && xx[j] <= x[i + 1])
			{
				// Interpolationsformel
				yy[j] = ((y[i + 1] - y[i]) / (x[i + 1] - x[i])) * (xx[j] - x[i]) + y[i];
			}
			else if (xx[j] > x[i + 1])
			{
				savepoint = j;
				break;
			}
		}
	}
//Code von Marvin Lehmann ende

	nlhs = 2;
	
	plhs[0] = mxCreateDoubleMatrix(1, len, mxREAL);
    memcpy(mxGetPr(plhs[0]), xx, len*sizeof(double));	
	
	plhs[1] = mxCreateDoubleMatrix(1, len, mxREAL);
    memcpy(mxGetPr(plhs[1]), yy, len*sizeof(double));


return;
}