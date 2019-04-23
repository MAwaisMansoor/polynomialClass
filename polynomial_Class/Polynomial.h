#pragma once
class Polynomial{

	int degree;	
	double* coEffe;
	int length;
	
public:

	
	Polynomial(int = 0);
	Polynomial(int, double*);
	Polynomial(const Polynomial&);
	char* toString();
	int getDegree();
	double evaluate(double);
	Polynomial operator+(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	Polynomial operator=(const Polynomial&);
	~Polynomial();

	/*Polynomial(int = 0);
	void setCoEfee();*/
};
