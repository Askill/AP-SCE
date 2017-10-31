#include "lgs.h"
#include "time.h"
#include <iostream>

using namespace std;

void LGS::data_entry()
{
	char auswahl = 'n';
	//Data entry
	while (auswahl == 'n')
	{
		cout << "Anzahl der Unbekannten: "; cin >> variables;
		create_array();
		cout << "Geben Sie die Gleichungen nach folgendem Schema an:" << endl;
		print_exp();
		
		for (int i = 0; i < variables; ++i)
		{
			for (int n = 0; n < variables+1; ++n)
			{
				cout << " "; 
				int var = n + 65;
				cout << (char)var << i + 1 << ": ";
				cin >> GA[i][n];
				
			}
			print_ln(i);
			cout << endl;
		}
		print();
		cout << "Sind die Angaben Korrekt? j/n "; cin >> auswahl;
		
	}
	cout << endl;	
}

void LGS::create_array()
{
	x = new long double[variables];
	GA = new long double*[variables];
	for (int i = 0; i < variables; ++i)
		GA[i] = new long double[variables+1];
}

void LGS::print()
{
	for (int i = 0; i < variables; ++i)
	{
		for (int n = 0; n < variables + 1; ++n)
		{
			cout << (GA[i][n] >= 0 ? (n == 0 ? " " : " +") : " ") << GA[i][n] << " ";
			if (n == variables-1)
				cout << "= ";
		}
		cout << endl;
	}
}

void LGS::print_ln(int ln)
{
	for (int n = 0; n < variables + 1; ++n)
	{
		int var = 123 - variables + n;
		cout << (GA[ln][n] >= 0 ? (n==0 ? " " : " +"): " ") << GA[ln][n] << (var!=123  ? (char)var : ' ');
		if (n == variables - 1)
			cout << "= ";
	}
	cout << endl;
}

void LGS::print_exp()
{
	for (int i = 0; i < variables; ++i)
	{
		for (int n = 0; n < variables + 1; ++n)
		{
			int var1 = n + 65;
			int var2 = 123 - variables + n;
			cout << "[" << (char)var1 << i + 1; var2!=123 ? cout<< (" *") << (char)var2 : cout << ""; cout << "]";
			if (n == variables - 1)
				cout << "= ";
		}
		cout << endl;
	}
}

float LGS::gauss()										
{
	double t1 = clock();

	int i, j, k;
	data_entry();
	for (i = 0; i<variables; i++)						//Pivotisation
		for (k = i + 1; k<variables; k++)
			if (abs(GA[i][i])<abs(GA[k][i]))
				for (j = 0; j <= variables; j++)
				{
					long double temp = GA[i][j];
					GA[i][j] = GA[k][j];
					GA[k][j] = temp;
				}

	cout << endl << "Matrix nach Pivot: " << endl;
	print();

	for (i = 0; i<variables - 1; i++)					//gauss elimination
		for (k = i + 1; k<variables; k++)
		{
			long double t = GA[k][i] / GA[i][i];
			for (j = 0; j <= variables; j++)
				GA[k][j] = GA[k][j] - t*GA[i][j];		//make the elements below the pivot elements equal to zero or elimnate the variables
		}

	cout << endl << "Matrix nach Gausselimination: " << endl;
	print();

	for (i = variables - 1; i >= 0; i--)                //back-substitution
	{													//x is an array whose values correspond to the values of x,y,z..
		x[i] = GA[i][variables];						//make the variable to be calculated equal to the rhs of the last equation
		for (j = i + 1; j<variables; j++)
			if (j != i)									//then subtract all the lhs values except the coefficient of the variable whose value is being calculated
				x[i] = x[i] - GA[i][j] * x[j];
		x[i] = x[i] / GA[i][i];							//now finally divide the rhs by the coefficient of the variable to be calculated
	}

	cout << endl << "Loesung: " << endl;				// Print the values of x, y, z
	for (i = 0; i<variables; i++){
		int var1 = i + 65;
		cout << (char)var1 << 1 << " = " << x[i] << endl;  
	}
	cout << endl;

	return (float)((clock() - t1) / CLOCKS_PER_SEC);
}

float LGS::cramer()
{
	double t1 = clock();

	long double det1 = determinant(GA,variables);
	cout << det1;

	return (float)((clock() - t1) / CLOCKS_PER_SEC);
}

long double LGS::determinant(long double** ga, int m)   
{

	long double sum = 0;
	long double** t = new long double*[variables];
	for (int i = 0; i < variables; ++i)
		t[i] = new long double[variables];

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