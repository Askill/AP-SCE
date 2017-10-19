#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void Zylinder();
long double Kreis_flacheninhalt(long double);
long double Zylinder_volumen(vector<long double>, vector<long double>);
long double Zylinder_masse(vector<long double>, vector<long double>, vector<long double>);
long double Zylinder_widerstand(vector<long double>, vector<long double>, vector<long double>);

int main()
{
	char auswahl = 'a';
	while(auswahl != 'e')
	{
		cout << "Was wollen Sie tun ?" << endl;
		cout << "1 Berechungen an einem Zylinder" << endl;

		cout << "e Beenden" << endl;
		
		cin >> auswahl;
		switch(auswahl)
		{
			case '1': Zylinder(); break;
			
			default: cout << "Okay, bye"; break;
		}
	}
    return 0;
}

void Zylinder()
{
	vector<long double> zylinder_lange;
	vector<long double> zylinder_durchmesser;
	vector<long double> zylinder_dichte;
	vector<long double> zylinder_widerstand;

	char auswahl = 'j';
	long double teil_lange;
	long double teil_durchmesser;
	long double teil_dichte;
	long double teil_widerstand;

	//Eingabe der Daten
	while (auswahl == 'j')
	{
		//Reset der Variablen für den Durchlauf
		teil_lange = 0;
		teil_durchmesser = 0;
		teil_dichte = 0;
		teil_widerstand = 0;


		cout << "Definieren Sie die Teilabschnitte des Zylinders" << endl;
		cout << "Laenge: "; cin >> teil_lange; zylinder_lange.push_back(teil_lange);
		cout << endl << "Durchmesser in mm: "; cin >> teil_durchmesser; zylinder_durchmesser.push_back(teil_durchmesser);
		cout << endl << "Dichte in g/mm^3: "; cin >> teil_dichte; zylinder_dichte.push_back(teil_dichte);
		cout << endl << "Spezifischer Widerstand in ohm * (mm^2) / m: "; cin >> teil_widerstand; zylinder_widerstand.push_back(teil_widerstand);
		cout << "Gibt es weitere Teilbereiche? j/n "; cin >> auswahl;
	}
	auswahl = 'j';
	//Berechungen
	while(auswahl=='j')
	{
		cout << "Was wollen Sie berechnen?" << endl;
		cout << "Volumen" << "\t" << "1" << endl;
		cout << "Masse" << "\t" << "2" << endl;
		cout << "Elektrischer Widerstand" << "\t" << "3" << endl;

		cin >> auswahl;
		switch (auswahl)
		{
			case '1': cout << Zylinder_volumen(zylinder_lange, zylinder_durchmesser) << " mm^3" << endl; break;
			case '2': cout << Zylinder_masse(zylinder_lange, zylinder_durchmesser, zylinder_dichte) << " g" << endl; break;
			case '3': cout << Zylinder_widerstand(zylinder_lange, zylinder_durchmesser, zylinder_dichte) << " ohm" << endl; break;

		default: cout << "Okay, bye"; break;
		}
		cout << "Wollen Sie fortfahren? j/n "; cin >> auswahl;
	}

}

long double Kreis_flacheninhalt(long double durchmesser)
{
	return (durchmesser / 2)*(durchmesser / 2) * 3.14159265359;
}

long double Zylinder_volumen(vector<long double> langen, vector<long double> durchmesser)
{
	long double Volumen = 0;
	for(int i = 0; langen.size() != i; i++)
	{
		Volumen = Volumen + langen[i] * Kreis_flacheninhalt(durchmesser[i]);
	}
	return Volumen;
}

long double Zylinder_masse(vector<long double> langen, vector<long double> durchmesser, vector<long double> dichten)
{
	long double masse = 0;
	for (int i = 0; langen.size() != i; i++)
	{
		masse = masse + langen[i] * Kreis_flacheninhalt(durchmesser[i]) * dichten[i];
	}
	return masse;
}

long double Zylinder_widerstand(vector<long double> langen, vector<long double> durchmesser, vector<long double> widerstande)
{
	long double widerstand = 0;
	for (int i = 0; langen.size() != i; i++)
	{
		widerstand = widerstand + langen[i]* 1000 * Kreis_flacheninhalt(durchmesser[i]) * widerstande[i];
	}
	return widerstand;
}
