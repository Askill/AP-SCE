#pragma once
#include <vector>
using namespace std;

class DIFF
{
public:
	vector<long double> diff(vector<long double>);
	vector<long double> forward_diff(vector<long double>, vector<long double>);
	vector<long double> backward_diff(vector<long double>, vector<long double>);
	static vector<long double> central_diff(vector<long double>, vector<long double>);
	static vector<long double> mid_diff(vector<long double>, vector<long double>);


	DIFF();
	~DIFF();
};

