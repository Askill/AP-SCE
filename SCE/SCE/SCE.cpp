#include "3d.h"
#include <iostream>
#include "lgs.h"
#include "nlgs.h"
#include "DIFF.h"
#include "OPTIMIZATION.h"
#include "INTEGRAL.h"
#include <math.h>

#define PI 3.14159265358979323846
using namespace std;

void cylinder();
void lgs();
void nlgs();
void optimization();
void diff();
void integ();

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
		cout << "6 numerische Integration" << endl;

		cout << "e Beenden" << endl;
		
		cin >> auswahl;
		cout << endl;
		switch(auswahl)
		{
			case '1': cylinder(); break;
			case '2': lgs(); break;
			case '3': nlgs(); break;
			case '4': optimization(); break;
			case '5': diff(); break;
			case '6': integ(); break;
			
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

	long double x = -5, y = -5, 
	xnew, ynew,
	increments = 0.1,
	z = opt.g_von_theta(x, y),
	znew = 0, zold = 1,
	zinitial = z;
	int xTOy = 1, iAThalf = 100; //iAThalf: max iterations/2
	
	cout << "i" << "\t" << "z" << "\t" << "x" << "\t" << "y" << endl;

	for(int i = 0 ; i <= 2 * iAThalf + 1; ++i) // add. exit crit. needed
	{
		cout << i << "\t" << z << "\t" << x << "\t" << y << endl;
		if (xTOy == 1)
		{
			xnew = x;
			ynew = y;
			if (zinitial / 2 == z)	//appropriate criteria?
			{
				iAThalf = i;
				ynew = y + increments;
			}
			else
				xnew = x + increments;
		}
		else
		{
			xnew = x;
			ynew = y + increments;
		}

		znew = opt.g_von_theta(xnew, ynew);
		zold = z;
		if(znew > z)
		{
			z = znew;
			x = xnew;
			y = ynew;
		}
		else
			if (xTOy == 1)
				xTOy = 2;		
	}
	
	cout << endl;
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


void integ()
{
	INTEGRAL integ;
	cout << integ.trapz(0, (PI / 2), 0.001) << endl << endl;
	cout << integ.quad(0, (PI / 2), 0.001) << endl << endl;
}