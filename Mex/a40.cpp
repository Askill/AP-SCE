#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"

void mexFunction(int nlhs, mxArray *plhs[], 			// Output variables 
				 int nrhs, const mxArray *prhs[]) 		// Input variables 
{
	int variables = *mxGetPr(prhs[0]);
	
	double* x = (double *)mxCalloc(variables+1, sizeof(double));					//create solution array
	
	double** GA = (double **)mxCalloc(variables+1, sizeof(double*));				//create Gauss Array (GA)
	for (int i = 0; i <= variables+1; i++){
		GA[i] = (double *)mxCalloc(variables+1, sizeof(double));
	}
	
	for(int i = 0; i < variables*(variables+1); i++){							//copy input array into GA								
		GA[i%variables][i/variables] = mxGetPr(prhs[1])[i];	
	}
	
	
	int i, j, k;
	for (i = 0; i<variables; i++)						//Pivotisation
		for (k = i + 1; k<variables; k++)
			if (abs(GA[i][i])<abs(GA[k][i]))
				for (j = 0; j <= variables; j++)
				{
					long double temp = GA[i][j];
					GA[i][j] = GA[k][j];
					GA[k][j] = temp;
				}

	for (i = 0; i<variables - 1; i++)					//gauss elimination
		for (k = i + 1; k<variables; k++)
		{
			long double t = GA[k][i] / GA[i][i];
			for (j = 0; j <= variables; j++)
				GA[k][j] = GA[k][j] - t*GA[i][j];		//make the elements below the pivot elements equal to zero or elimnate the variables
		}

	for (i = variables - 1; i >= 0; i--)                //back-substitution
	{													//x is an array whose values correspond to the values of x,y,z..
		x[i] = GA[i][variables];						//make the variable to be calculated equal to the rhs of the last equation
		for (j = i + 1; j<variables; j++)
			if (j != i)									//then subtract all the lhs values except the coefficient of the variable whose value is being calculated
				x[i] = x[i] - GA[i][j] * x[j];
		x[i] = x[i] / GA[i][i];							//now finally divide the rhs by the coefficient of the variable to be calculated
	}
	
	nlhs = variables;
	for(int l=0;l<variables;l++){
		char temp;
		
		if(x[variables-1-l] != 0)
		{
			if(l!=0){
			mexPrintf("+");
			}
			if(x[variables-1-l] < 0 ){
				mexPrintf("-");
				x[variables-l] *= -1;
			}
			temp=(char)(48+x[variables-1-l]);
			mexPrintf("%c",temp);
			
			if(variables-1-l != 0){
				mexPrintf("*");
				mexPrintf("x");
				mexPrintf("^");
				temp=(char)(48+variables-1-l);
				mexPrintf("%c",temp);
			}
			
		}
		
	}
	mexPrintf("\n");
	for(int j=0; j < variables; j++){
		plhs[j]=mxCreateDoubleScalar(x[j]);
		
	}
	
	for (int i = 0; i <= variables; i++ ){
		free(GA[i]);
	}
	
	free(GA);
	free(x);
  
return;
}