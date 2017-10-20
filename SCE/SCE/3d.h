#include <vector>
using namespace std;

class Body
{
private:
	long double volume;
	long double mass;
	long double electric_resistance;
	vector<long double> heights;
	vector<long double> densities;
	vector<long double> resistances;
//Virtual compute functions
	virtual long double compute_volume(){};
	virtual long double compute_mass(){};
	virtual long double compute_electric_resistamce(){};

public:
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

	Body() {};
	virtual ~Body() { heights.clear(); };
};

class Cylinder : public Body
{
private:
	vector<long double> radii;

public:

	Cylinder() {};
	~Cylinder(){};
};