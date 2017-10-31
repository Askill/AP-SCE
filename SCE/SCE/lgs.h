#pragma once
class LGS{
public:
	long double** GA;
	int variables = 0;


	LGS(){};
	~LGS()
	{
		for (int i = 0; i < variables; ++i)
			delete[] GA[i];
		delete[] GA;
	};

	float gauss();
	float cramer();
	void data_entry();
	void creat_array();
	void print();
	void print_ln(int);
	void print_exp();
	void gauss_down();
	void gauss_up();
};