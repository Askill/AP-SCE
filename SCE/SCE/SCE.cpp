#include "3d.h"
#include <iostream>
#include "lgs.h"
#include "nlgs.h"
#include "DIFF.h"
using namespace std;

void cylinder();
void lgs();
void nlgs();
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
		cout << "5 numerische differentation" << endl;

		cout << "e Beenden" << endl;
		
		cin >> auswahl;
		switch(auswahl)
		{
			case '1': cylinder(); break;
			case '2': lgs(); break;
			case '3': nlgs(); break;
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
	cout << "Newton: " <<nlgs.newton(1,100) << endl;
	cout << "skantenverfahren fehlt" << endl << endl;

}

void diff() {
	//Plotter: https://www.desmos.com/calculator

	DIFF diff;
	vector<long double> AbfullX = {0, 5, 10, 15, 20 };
	vector<long double> AbfullY = {1, 0.8811, 0.7366, 0.5430, 0.1698};
	cout << "Erste Ableitung mit forward und backward" << endl;
	print_array(diff.xvalues.data(), diff.forward_diff(diff.yvalues).data(), diff.xvalues.size());
	print_array(diff.xvalues.data(), diff.central_diff(diff.yvalues, diff.xvalues).data(), diff.xvalues.size());
	cout << "Zweite Ableitung mit backward" << endl;
	print_array(diff.xvalues.data(), diff.backward_diff(diff.forward_diff(diff.yvalues)).data(), diff.xvalues.size());
	cout << "Erste Ableitung 6.1.2" << endl;
	print_array(diff.xvalues.data(), diff.mid_diff(AbfullY, AbfullX).data(), AbfullX.size());
	
}