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
		creat_array();
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

void LGS::creat_array()
{
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


float LGS::cramer()
{
	double t1 = clock();

	return (float)((clock() - t1) / CLOCKS_PER_SEC);
}

float LGS::gauss()
{
	double t1 = clock();
	gauss_down();
	gauss_up();
	return (float)((clock() - t1) / CLOCKS_PER_SEC);
}

void LGS::gauss_down( )
{
	for(int stage = 1; stage < variables ; stage++)
	{
		long double div = (GA[stage][stage-1] / GA[stage-1][stage-1]);
		for (int i = 0; i < variables-1 && stage+i < variables; i++)
		{
			for (int n = 0; n <= variables; n++)
			{
				GA[stage + i][n] = GA[stage + i][n] - (GA[stage - 1][n] * div);
			}

		}

		print();
		cout << endl;
	}
		
	
}

void LGS::gauss_up()
{
	
}






