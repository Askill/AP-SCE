#pragma once
class LGS{
private:
	void create_array();
	void copy_array();
	void print_ln(int);
	void print_exp();
	void swap_column(long double**, int);
public:
	long double** GA;
	long double** CA;
	long double** CA2;
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
	
	void print(long double**);
	float gauss();
	long double determinant(long double**, int);
		
};