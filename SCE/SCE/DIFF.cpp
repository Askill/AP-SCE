#include "DIFF.h"
using namespace std;

DIFF::DIFF()
{
}


DIFF::~DIFF()
{
}


vector<long double> DIFF::diff(vector<long double> yvalues)
{
	vector<long double> diff = yvalues;
	vector<long double> xdiff (diff.size()-1);
	for(unsigned int i = 0; i < xdiff.size(); i++)
	{
		xdiff.at(i) = diff.at(i+1) - diff.at(i);
	}

	return xdiff;
}

vector<long double> DIFF::backward_diff(vector<long double> y, vector<long double> xvalues)
{
	vector<long double> temp;
	temp.resize(y.size());

	for (unsigned int i = 0; i < y.size() - 1; i++)
	{
		temp.at(i) = (y.at(i + 1) - y.at(i)) / (xvalues.at(i + 1) - xvalues.at(i));
	}
	temp.at(y.size()-1) = 0;
	return temp;
}
vector<long double> DIFF::forward_diff(vector<long double> y, vector<long double> xvalues)
{
	vector<long double> temp;
	temp.resize(y.size());

	for (unsigned int i = 1; i < y.size(); i++)
	{
		temp.at(i) = (y.at(i) - y.at(i - 1)) / (xvalues.at(i) - xvalues.at(i - 1));
	}
	temp.at(0) = 0;
	return temp;
}
vector<long double> DIFF::central_diff(vector<long double> y, vector<long double> x)
{
	vector<long double> temp;
	temp.resize(y.size());

	for (unsigned int i = 1; i < y.size() - 1; i++)
	{
		temp.at(i) = (y.at(i+1) - y.at(i - 1)) / (x.at(i+1) - x.at(i - 1));
	}
	temp.at(0) = 0;
	temp.at(y.size() - 1) = 0;
	return temp;
}

vector<long double> DIFF::mid_diff(vector<long double>y, vector<long double>x)
{
	vector<long double> temp;
	temp.resize(y.size());
	unsigned int i = 0;

	temp.at(i) = (y.at(i + 1) - y.at(i)) / (x.at(i + 1) - x.at(i));
	i++;
	temp.at(i) = (y.at(i + 1) - y.at(i)) / (x.at(i + 1) - x.at(i));
	temp.at(i) += (y.at(i + 1) - y.at(i - 1)) / (x.at(i + 1) - x.at(i - 1));
	temp.at(i) /= 2;

	for (; i < y.size() - 2; ++i)
	{
		temp.at(i) = (y.at(i + 1) - y.at(i - 1)) / (x.at(i + 1) - x.at(i - 1));
	}

	temp.at(i) += (y.at(i) - y.at(i - 1)) / (x.at(i) - x.at(i - 1));
	temp.at(i) /= 2;
	i++;
	temp.at(i) = (y.at(i) - y.at(i - 1)) / (x.at(i) - x.at(i - 1));
	
	return temp;
}


