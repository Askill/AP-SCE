#pragma once
#include <vector>
using namespace std;

class DIFF
{
public:
	vector<long double> xvalues = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250};
	vector<long double> yvalues = {0, 2926, 10170, 21486, 33835, 45251, 55634, 65038, 73461, 80905, 87368, 92852, 97355, 100878, 103422, 104986, 106193, 110246, 119626, 136106, 162095, 199506, 238775, 277065, 314375, 350704};
	vector<long double> y1values; //y-values of 1st derivative
	vector<long double> y2values; //y-values of 2nd derivative
	vector<long double> diff();
	vector<long double> forward_diff();
	vector<long double> backward_diff();

	vector<long double> forward_diff(vector<long double>);
	vector<long double> backward_diff(vector<long double>);


	DIFF();
	~DIFF();
};

