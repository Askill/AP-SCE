#include "3d.h"
#include <iostream>
using namespace std;

void cylinder();

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
			case '1': cylinder(); break;
			
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
