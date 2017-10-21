class Shape
{
public:
	virtual long double compute_area(long double) { return 0; };
	Shape(){};
	virtual ~Shape() {};
};


class Circle : public Shape
{
public:
	Circle() {}
	~Circle() {}
	long double compute_area(long double d) override 
	{
		return (d / 2)*(d / 2) * 3.14159265359;
	}
};
