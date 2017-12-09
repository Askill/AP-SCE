#include "3d.h"
#include <iostream>
#include "lgs.h"
#include "nlgs.h"
#include "DIFF.h"
#include "OPTIMIZATION.h"
using namespace std;

void cylinder();
void lgs();
void nlgs();
void optimization();
void diff();
void print_array(long double* a, int size)
{
	cout << endl;
	for(int i = 0; i < size; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl << endl;
}
void print_array(long double* a, long double* b,  int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "," << b[i] << endl;
	}
	cout << endl << endl;
}

int main()
{
	char auswahl = 'a';
	while(auswahl != 'e')
	{
		cout << "Was wollen Sie tun ?" << endl;
		cout << "1 Berechungen an einem Zylinder" << endl;
		cout << "2 LGS loesen" << endl;
		cout << "3 n.LGS loesen" << endl;
		cout << "4 optimization" << endl;
		cout << "5 numerische differentation" << endl;

		cout << "e Beenden" << endl;
		
		cin >> auswahl;
		switch(auswahl)
		{
			case '1': cylinder(); break;
			case '2': lgs(); break;
			case '3': nlgs(); break;
			case '4': optimization(); break;
			case '5': diff(); break;
			
			default: cout << "Okay, bye" << endl; break;
		}
	}
    return 0;
}

void cylinder()
{
	Cylinder cylinder;
	cylinder.data_entry();
	cylinder.compute_options();

}

void lgs()
{
	LGS lgs;
	lgs.data_entry();
	cout << lgs.gauss();
	cout << lgs.cramer();
	cout << endl;
}

void nlgs()
{
	NLGS nlgs;
	cout << endl << "Bisektion: " << nlgs.bisektion(1,4,100) << endl;
	cout << "Fixpunkt: " << nlgs.fixedpoint(1,100) << endl;
	cout << "Newton: " << nlgs.newton(1,100) << endl;
	cout << "skantenverfahren fehlt" << endl << endl;

}

void optimization()
{
	OPTIMIZATION opt;

	long double lower_bound = -2, upper_bound = 2;		//upper / lower - _bounds instead of theta-vector
	long double increments = 0.1;
	
	long double z = opt.g_von_theta(lower_bound, upper_bound);
	long double which_theta = 1;

	vector<long double> thetanew(2);
	cout << "i" << "\t" << "z" << "\t" << "lb" << "\t" << "ub" << endl;

	for(int i = 0; i < 41; i++)
	{
		
		cout << i << "\t" << z << "\t" << lower_bound << "\t" << upper_bound << endl;
		if (which_theta == 1)
		{
			thetanew.at(0) = lower_bound + increments;
			thetanew.at(1) = upper_bound;
		}
		else
		{
			thetanew.at(0) = lower_bound;
			thetanew.at(1) = upper_bound - increments;
		}

		long double znew = opt.g_von_theta(thetanew.at(0), thetanew.at(1));

		if(znew > z)
		{
			z = znew;
			lower_bound = thetanew.at(0);
			upper_bound = thetanew.at(1);
		}
		else
		{
			if (which_theta == 1)
				which_theta = 2;
		}
		
	}
	

}

void diff() {
	//Plotter: https://www.desmos.com/calculator

	DIFF diff;
	vector<long double> xvalues = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250 };
	vector<long double> yvalues = { 0, 2926, 10170, 21486, 33835, 45251, 55634, 65038, 73461, 80905, 87368, 92852, 97355, 100878, 103422, 104986, 106193, 110246, 119626, 136106, 162095, 199506, 238775, 277065, 314375, 350704 };
	vector<long double> AbfullX = {0, 5, 10, 15, 20 };
	vector<long double> AbfullY = {1, 0.8811, 0.7366, 0.5430, 0.1698};

	cout << "Erste Ableitung mit forward und backward" << endl;
	print_array(xvalues.data(), diff.forward_diff(yvalues, xvalues).data(), xvalues.size());
	print_array(xvalues.data(), diff.central_diff(yvalues, xvalues).data(), xvalues.size());

	cout << "Zweite Ableitung mit backward" << endl;
	print_array(xvalues.data(), diff.backward_diff(diff.forward_diff(yvalues, xvalues), xvalues).data(), xvalues.size());

	cout << "Erste Ableitung 6.1.2" << endl;
	print_array(xvalues.data(), diff.mid_diff(AbfullY, AbfullX).data(), AbfullX.size());
	
}