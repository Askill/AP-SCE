#include "mex.h" 
#include "matrix.h"
#include "stdlib.h"


double** CA;
double** CA2;
double* x;
int variables;
	
	
void copy_array()
{
	for (int i = 0; i < variables; ++i)
		for (int n = 0; n < variables + 1; ++n)
			CA2[i][n] = CA[i][n];
}

void swap_column(double** ca2, int col)
{
	double* temp = (double *)mxCalloc(variables, sizeof(double));
	copy_array();
	for(int i=0; i < variables ;i++)
	{
		temp[i] = CA[i][variables];
	}
	for(int i=0; i < variables ;i++)
	{
		CA2[i][col] = temp[i];
	}
	free(temp);
}

double determinant(double** ga, int m)   
{

	double sum = 0;
	double** t = (double **)mxCalloc(variables, sizeof(double*));		
	for (int i = 0; i < variables; ++i)
		t[i] = (double *)mxCalloc(variables, sizeof(double));
	

	if (m == 2)
	{												
		sum = ga[0][0] * ga[1][1] - ga[0][1] * ga[1][0];
		return sum;
	}
	for (int p = 0; p<m; p++)
	{
		int h = 0, k = 0;
		for (int i = 1; i<m; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (j == p)
					continue;
				t[h][k] = ga[i][j];
				k++;
				if (k == m - 1)
				{
					h++;
					k = 0;
				}

			}
		}

		sum = sum + ga[0][p] * pow(-1, p)*determinant(t, m - 1);
	}
	return sum;
}

void mexFunction(int nlhs, mxArray *plhs[], 			// Output variables 
				 int nrhs, const mxArray *prhs[]) 		// Input variables 
{
	variables = *mxGetPr(prhs[0]);
	
	double* x = (double *)mxCalloc(variables, sizeof(double));

	CA = (double **)mxCalloc(variables, sizeof(double*));			//create original array
	CA2 = (double **)mxCalloc(variables, sizeof(double*));			//create working array
	
	for (int i = 0; i <= variables; i++){
		CA[i] = (double *)mxCalloc(variables, sizeof(double));
	}					
	for (int i = 0; i <= variables; i++){									
		CA2[i] = (double *)mxCalloc(variables, sizeof(double));
	}
	
	for(int i = 0; i < variables*(variables+1); i++){				//copy input array into ca and ca2							
		CA[i%variables][i/variables] = mxGetPr(prhs[1])[i];	
		CA2[i%variables][i/variables] = mxGetPr(prhs[1])[i];
	}
	//Actual cramer
	
	double detA = determinant(CA,variables);
	
	copy_array();

	for(int i = 0; i < variables; i++)
	{
		swap_column(CA2, i);
		x[i] = determinant(CA2, variables);
	}

	// Output
	for(int j=0; j < variables; j++){
		plhs[j]=mxCreateDoubleScalar(x[j]/detA );
		
	} 
	// free memory
	for (int i = 0; i <= variables; i++ ){
		free(CA2[i]);
	}
	
	free(CA2);
	free(x);
  
return;
}