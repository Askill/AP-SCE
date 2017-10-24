#include "3d.h"
#include "2d.h"
using namespace std;

void Cylinder::data_entry()
{
	char auswahl = 'j';
	long double teil_lange;
	long double teil_durchmesser;
	long double teil_dichte;
	long double teil_widerstand;

	//Data entry
	while (auswahl == 'j')
	{
		//Reseting the variables
		teil_lange = 0;
		teil_durchmesser = 0;
		teil_dichte = 0;
		teil_widerstand = 0;


		cout << "Definieren Sie die Teilabschnitte des Zylinders" << endl;
		cout << "	Laenge in mm: "; cin >> teil_lange; heights.push_back(teil_lange);
		cout << "	Durchmesser in mm: "; cin >> teil_durchmesser; radii.push_back(teil_durchmesser);
		cout << "	Dichte in g/mm^3: "; cin >> teil_dichte; densities.push_back(teil_dichte);
		cout << "	Spezifischer Widerstand in ohm * (mm^2) / m: "; cin >> teil_widerstand; resistances.push_back(teil_widerstand);
		cout << "	Gibt es weitere Teilbereiche? j/n "; cin >> auswahl;
	}
	cout << endl;
}


void Cylinder::compute_options() {
	//Compute
	char auswahl = 'j';
	while (auswahl == 'j')
	{
		cout << "Was wollen Sie berechnen?" << endl;
		cout << "	1 Volumen" << endl;
		cout << "	2 Masse" << endl;
		cout << "	3 Elektrischer Widerstand" << endl;

		cin >> auswahl;
		switch (auswahl)
		{
		case '1': cout << "Volumen:	" << compute_volume() << " mm^3" << endl; break;
		case '2': cout << "Masse:	" << compute_mass() << " g" << endl; break;
		case '3': cout << "Widerstand:	" << compute_electric_resistance() << " ohm" << endl; break;

		default: cout << "Okay, bye" << endl; break;
		}
		cout << "Wollen Sie fortfahren? j/n "; cin >> auswahl;
	}
}

long double Cylinder::compute_volume()
{
	long double Volume = 0;
	Circle circle;
	for (int i = 0; heights.size() != i; i++)
	{
		Volume = Volume + heights[i] * circle.compute_area(radii[i]);
	}
	set_volume(Volume);
	return Volume;
}
long double Cylinder::compute_mass()
{
	long double mass = 0;
	Circle circle;
	for (int i = 0; heights.size() != i; i++)
	{
		mass = mass + heights[i] / 10 * circle.compute_area(radii[i] / 10) * densities[i];
	}
	set_mass(mass);
	return mass;
}
long double Cylinder::compute_electric_resistance()
{
	long double resistance = 0;
	Circle circle;
	for (int i = 0; heights.size() != i; i++)
	{
		resistance = resistance + ((heights[i] / 1000) * resistances[i]) / circle.compute_area(radii[i]);
	}
	set_electric_resistance(resistance);
	return resistance;
}
