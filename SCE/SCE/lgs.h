#pragma once
class LGS{
public:
	long double** GA;
	long double* x;
	int variables = 0;


	LGS(){};
	~LGS()
	{
		for (int i = 0; i < variables; ++i)
			delete[] GA[i];
		delete[] GA;
		delete[] x;
	};

	
	float cramer();
	void data_entry();
	void create_array();
	void print();
	void print_ln(int);
	void print_exp();
	float gauss();
	long double determinant(long double**, int);
		
};