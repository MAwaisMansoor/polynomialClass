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

	//   THE CODE BELOW COULD BE USED IF JUST THE DEGREE HAS TO BE PASSED TO THE CONSTRUCTOR
	/*void setCoEfee();*/
};
