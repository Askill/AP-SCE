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
		cout << "[A1 *x][B1 *y][C1 *z]=[D1]" << endl;
		cout << "[A2 *x][B2 *y][C2 *z]=[D2]" << endl;
		cout << "[A3 *x][B3 *y][C3 *z]=[D3]" << endl;
		
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
		cout << "Sind die angaben Korrekt? j/n"; cin >> auswahl;
		
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
			cout << GA[i][n] << " ";
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
		cout << " +" << GA[ln][n] << (var!=123  ? (char)var : ' ');
		if (n == variables - 1)
			cout << "= ";
	}
	cout << endl;
}

float LGS::cramer()
{
	double t1 = clock();

	return (float)((clock() - t1) / CLOCKS_PER_SEC);
}

float LGS::gauss()
{
	double t1 = clock();

	return (float)((clock() - t1) / CLOCKS_PER_SEC);
}




