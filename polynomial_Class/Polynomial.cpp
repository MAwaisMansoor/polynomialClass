#include "polynomial.h"
#include<iostream>
#include<string>

using namespace std;

Polynomial::Polynomial(int d, double*c) {

	degree = d;
	length = d + 1;

	//Allocating memory and initializing
	coEffe = new double[d + 1];
	
	for (int i = 0; i < length; i++)
		coEffe[i] = c[i];
	
}

Polynomial::Polynomial(int l) {

	this->length = l;

	coEffe = new double[l];
	
	for (int i = 0; i < l; i++)
		coEffe[i] = 0;

}

//copy constructor
Polynomial::Polynomial(const Polynomial& obj) {

	length = obj.length;
	degree = obj.degree;

	coEffe = new double[length];
	
	for (int i = 0; i < length; i++)
		coEffe[i] = obj.coEffe[i];

}

//evaluation function
double Polynomial::evaluate(double x) {
	
	cout << "evaluate(" << x <<"): ";
	 double evaluation = 0;
	int j = degree;
	for (int i = 0; i <= degree; i++) {
		evaluation += (coEffe[j] * pow(x, j));
		j--;
	}

	return evaluation;

}

//to return polynomial 
char* Polynomial::toString() {
	string poly;
	
	for (int i = degree; i >= 0; i--) 
		poly += to_string((int)coEffe[i]) + (i == 0 ? "" : "x^" + to_string(i) + " + ");
	
	int compLength = poly.length();
	
	char* polynomial = new char[compLength + 1];
	
	for (int i = 0; i <= compLength; i++)
		polynomial[i] = poly[i];

	return polynomial;
}

//to return degree 
int Polynomial::getDegree() {
	return degree;
}

//+ operator overloaded
Polynomial Polynomial::operator+(const Polynomial& obj) {

	Polynomial temp;
	
	if (obj.length > length) {
		
		// Attributes of greater one
		temp.coEffe = new double[obj.length];
		temp.length = obj.length;
		temp.degree = obj.degree;

		for (int i = 0; i < obj.length; i++) {
			
			temp.coEffe[i] = obj.coEffe[i];
			if (i < length)
				temp.coEffe[i] += coEffe[i];
		
		}
	}
	else {
		
		// Attributes of greater one
		temp.coEffe = new double[length];
		temp.length = length;
		temp.degree = degree;

		for (int i = 0; i < length; i++) {
		
			temp.coEffe[i] = coEffe[i];
			if (i < obj.length)
				temp.coEffe[i] += obj.coEffe[i];
		
		}
	}
	return temp;


}

//* operator overloaded
Polynomial Polynomial::operator*(const Polynomial& obj) {
	
	int tempLength = (length + obj.length) - 1;
	
	Polynomial temp(tempLength);
	temp.degree = degree + obj.degree;
	for (int i = 0; i < obj.length; i++) {
	
		for (int j = 0; j < length; j++) {
		
			int coeff = coEffe[i] * obj.coEffe[j];
			int power = i + j;
		
			temp.coEffe[power] += coeff;
		
		}

	}
	return temp;
}

//= operator overloaded
Polynomial Polynomial::operator=(const Polynomial& obj) {
	
	coEffe = new double[obj.length];
	
	length = obj.length;
	
	for (int i = 0; i < obj.length; i++)
		coEffe[i] = obj.coEffe[i];
	
	return *this;
}

//destructor
Polynomial::~Polynomial() {
	
	delete[] coEffe;

}






//   THE CODE BELOW COULD BE USED IF JUST THE DEGREE HAS TO BE PASSED TO THE CONSTRUCTOR

/*constructor which takes degree as argument
Polynomial::Polynomial(int d) {

	degree = d;
	coEffe = new double[d + 1];
	polynomial = new char[(((d + 1) * 7) - 6)];
	length = (((d + 1) * 7) - 6);


	for (int i = 0; i <= degree; i++) {
		
		coEffe[degree - i] = 4;

	}

	int j = length, k = 0;

	for (int i = 0; i <= length; i++) {

		if (i == length) {
			polynomial[k] = (coEffe[j-1] + 48);
			polynomial[(((d + 1) * 7) - 6)] = '\0';
			break;
		}
		else {
			polynomial[k] = (coEffe[j-1] + 48);
			polynomial[k + 1] = 'x';
			polynomial[k + 2] = '^';
			polynomial[k + 3] = ((j - 1) + 48);
			polynomial[k + 4] = ' ';
			polynomial[k + 5] = '+';
			polynomial[k + 6] = ' ';
			j--;
			k += 7;
		}
	}


}

Polynomial::Polynomial(const Polynomial& obj) {

	if (this->polynomial != nullptr)
		delete[] this->polynomial;

	this->polynomial = new char[obj.length + 1];
	this->degree = obj.degree;
	this->length = obj.length;
	
	for (int i = 0; i <= obj.length; i++) {
		this->polynomial[i] = obj.polynomial[i];
	}
	
	if (this->coEffe != nullptr)
		delete[] coEffe;

	this->coEffe = new double[obj.degree + 1];

	for (int i = 0; i <= obj.degree; i++) {

		this->coEffe[i] = obj.coEffe[i];

	}

	this->coEffe[obj.degree + 1] = '\0';
	this->polynomial[obj.length] = '\0';
}
coEffecient setter
void Polynomial::setCoEfee() {

	for (int i = 0; i <= degree; i++) {
		cout << "\nEnter the co-effecient for term " << i + 1 << ": ";
		cin >> coEffe[(degree + 1) - i];
	}
	

	int j = degree+1, k = 0;

	for (int i = 0; i <= degree + 1; i++) {

		if (i == degree + 1) {
			polynomial[k] = (coEffe[j]+48);
			polynomial[(((degree + 1) * 7) - 6)] = '\0';
			break;
		}
		else {
			polynomial[k] = (coEffe[j] + 48);
			polynomial[k + 1] = 'x';
			polynomial[k + 2] = '^';
			polynomial[k + 3] = ((j-1) + 48);
			polynomial[k + 4] = ' ';
			polynomial[k + 5] = '+';
			polynomial[k + 6] = ' ';
			j--;
			k += 7;
		}
	}

}

+ operator overloaded
Polynomial Polynomial::operator+(const Polynomial& obj) {
	Polynomial temp;

	int sD, lD;
	if (degree < obj.degree) {
		temp.degree = obj.degree;
		sD = degree;
		lD = obj.degree;
		temp.length = obj.length;

		if (temp.coEffe != nullptr)
			delete[] temp.coEffe;

		temp.coEffe = new double[obj.degree + 1];

	}
	else if (degree > obj.degree ||
		degree == obj.degree) {

		temp.degree = degree;
		sD = obj.degree;
		lD = degree;
		temp.length = length;

		if (temp.coEffe != nullptr)
			delete[] temp.coEffe;

		temp.coEffe = new double[degree + 1];

	}

	for (int i = 0; i <= temp.degree; i++) {

		if (i <= sD)
			temp.coEffe[i] = coEffe[i] + obj.coEffe[i];

		if (i > sD) {

			if (sD < lD)
				temp.coEffe[i] = obj.coEffe[i];

			if (sD > lD || sD == lD)
				temp.coEffe[i] = coEffe[i];

		}
	}

	temp.coEffe[temp.degree + 1] = '\0';

	if (temp.polynomial != nullptr)
		delete[] temp.polynomial;

	temp.polynomial = new char[temp.length + 1];


	int j = temp.degree + 1, k = 0;

	for (int i = 0; i <= temp.degree; i++) {

		if (i == temp.degree) {
			temp.polynomial[k] = (temp.coEffe[j - 1] + 48);
			temp.polynomial[(((temp.degree + 1) * 7) - 6)] = '\0';
			break;
		}
		else {
			temp.polynomial[k] = (temp.coEffe[j - 1] + 48);
			temp.polynomial[k + 1] = 'x';
			temp.polynomial[k + 2] = '^';
			temp.polynomial[k + 3] = ((j - 1) + 48);
			temp.polynomial[k + 4] = ' ';
			temp.polynomial[k + 5] = '+';
			temp.polynomial[k + 6] = ' ';
			j--;
			k += 7;
		}

	}

	return temp;
}
* operator overloaded
Polynomial Polynomial::operator*(const Polynomial& obj) {

	Polynomial temp;

	temp.degree = degree + obj.degree;
	temp.length = (length + obj.length) - 1;
	temp.polynomial = new char[temp.length + 1];
	temp.coEffe = new double[temp.degree + 2];

	for (int i = 0; i <= temp.degree; i++) {
		temp.coEffe[i] = 0;
	}

	for (int i = 0; i <= obj.degree; i++) {
		
		for (int j = 0; j <= degree; j++) {
			
			int power = i + j;
			int coeffe = coEffe[i] * obj.coEffe[j];
			temp.coEffe[power] += coeffe;

		}
	}

	temp.coEffe[temp.degree+1] = '\0';

	int j = temp.degree + 1, k = 0;

	for (int i = 0; i <= temp.degree; i++) {

		if (i == temp.degree) {
			temp.polynomial[k] = (temp.coEffe[j - 1] + 48);
			temp.polynomial[(((temp.degree + 1) * 7) - 6)] = '\0';
			break;
		}
		else {
			temp.polynomial[k] = (temp.coEffe[j - 1] + 48);
			temp.polynomial[k + 1] = 'x';
			temp.polynomial[k + 2] = '^';
			temp.polynomial[k + 3] = ((j - 1) + 48);
			temp.polynomial[k + 4] = ' ';
			temp.polynomial[k + 5] = '+';
			temp.polynomial[k + 6] = ' ';
			j--;
			k += 7;
		}
	}
	return temp;
}
= operator overloaded
Polynomial& Polynomial::operator=(const Polynomial & obj) {
	
	if (this->polynomial != nullptr)
		delete[] this->polynomial;
	
	length = obj.length;
	degree = obj.degree;
	polynomial = new char[length + 1];
	coEffe = new double[obj.degree + 1];
	
	for (int i = 0; i <= length; i++) {

		this->polynomial[i] = obj.polynomial[i];

	}

	for (int i = 0; i <= obj.degree; i++) {

		this->coEffe[i] = obj.coEffe[i];

	}

	this->coEffe[obj.degree+1] = '\0';
	this->polynomial[length] = '\0';

	return *this;
}*/
