#include <vector>
#include <iostream>
#include "2d.h"
using namespace std;

class Body
{
public:
	long double volume;
	long double mass;
	long double electric_resistance;
	vector<long double> heights;
	vector<long double> densities;
	vector<long double> resistances;

//Set
	void set_volume(long double v) { volume = v; };
	void set_mass(long double m) { mass = m; };
	void set_electric_resistance(long double er) { electric_resistance = er; };
//Get
	long double get_volume() { return volume; };
	long double get_mass() { return mass; };
	long double get_electric_resistance() { return electric_resistance; };
//Virtuals
	virtual void data_entry(){};
	virtual void compute_options(){};

	virtual long double compute_volume() { return 0; };
	virtual long double compute_mass() { return 0; };
	virtual long double compute_electric_resistamce() { return 0; };

	Body() {};
	virtual ~Body() {};
};



class Cylinder : public Body
{
public:
	vector<long double> radii;
	Cylinder() {};
	~Cylinder(){};

	void data_entry() override
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

	void compute_options() override
	{		
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
			case '3': cout << "Widerstand:	" << compute_electric_resistamce() << " ohm" << endl; break;

			default: cout << "Okay, bye" << endl; break;
			}
			cout << "Wollen Sie fortfahren? j/n "; cin >> auswahl;
		}
	}
	long double compute_volume() override
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
	long double compute_mass()override 
	{
		long double mass = 0;
		Circle circle;
		for (int i = 0; heights.size() != i; i++)
		{
			mass = mass + heights[i]/10 * circle.compute_area(radii[i]/10) * densities[i];
		}
		set_mass(mass);
		return mass;
	}
	long double compute_electric_resistamce() override
	{
		long double resistance = 0;
		Circle circle;
		for (int i = 0; heights.size() != i; i++)
		{
			resistance = resistance + ((heights[i]/1000) * resistances[i]) / circle.compute_area(radii[i]);
		}
		set_electric_resistance(resistance);
		return resistance;
	}
};