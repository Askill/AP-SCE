#include "DIFF.h"
using namespace std;

DIFF::DIFF()
{
	y1values.resize(yvalues.size());
}


DIFF::~DIFF()
{
}


vector<long double> DIFF::diff()
{
	vector<long double> diff = yvalues;
	vector<long double> xdiff (diff.size()-1);
	for(unsigned int i = 0; i < xdiff.size(); i++)
	{
		xdiff.at(i) = diff.at(i+1) - diff.at(i);
	}

	return xdiff;
}

vector<long double> DIFF::forward_diff()
{
	for(unsigned int i=0; i < xvalues.size()-1; i++)
	{
		y1values.at(i) = (yvalues.at(i + 1) - yvalues.at(i)) / (xvalues.at(i + 1) - xvalues.at(i));
	}
	y1values.at(25) = 0;
	return y1values;
}

vector<long double> DIFF::backward_diff()
{
	
	for (unsigned int i = 1; i < xvalues.size(); i++)
	{
		y1values.at(i) = (yvalues.at(i) - yvalues.at(i-1)) / (xvalues.at(i) - xvalues.at(i-1));
	}
	y1values.at(0) = 0;
	return y1values;
}

vector<long double> DIFF::backward_diff(vector<long double> y)
{
	vector<long double> temp;
	temp.resize(y.size());

	for (unsigned int i = 0; i < y.size() - 1; i++)
	{
		temp.at(i) = (y.at(i + 1) - y.at(i)) / (xvalues.at(i + 1) - xvalues.at(i));
	}
	temp.at(25) = 0;
	return temp;
}
vector<long double> DIFF::forward_diff(vector<long double> y)
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



