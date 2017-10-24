#include <vector>
#include <iostream>

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
	virtual long double compute_electric_resistance() { return 0; };

	Body() {};
	virtual ~Body() {};
};



class Cylinder : public Body
{
public:
	vector<long double> radii;
	Cylinder() {};
	~Cylinder(){};

	void data_entry() override;
	void compute_options() override;
	long double compute_volume() override;
	long double compute_mass()override;
	long double compute_electric_resistance() override;
};