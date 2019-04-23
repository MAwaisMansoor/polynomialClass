
#include <iostream>
#include "Polynomial.h"

using namespace std;
int main(){
	
	double coEffe[] = { 2, 3, 4, 5 };
	int degree = (sizeof(coEffe) / sizeof(double)) - 1;

	//creating two object on heap
	Polynomial* p1 = new Polynomial(degree, coEffe);
	Polynomial* p2 = new Polynomial(degree, coEffe);


	
	//printing  
	cout << "---Polynomial A---\n";
	cout << "getDegree(): " << p1->getDegree() << endl;
	cout << "toString(): " << p1->toString() << endl;
	cout << p1->evaluate(2) << endl;
	
	//printing
	cout << "\n---Polynomial B---\n";
	cout << "getDegree(): " << p2->getDegree() << endl;
	cout << "toString(): " << p2->toString() << endl;
	cout << p2->evaluate(2) << endl;

	//assigning the sum of two object to an other object on heap
	Polynomial* p3 = new Polynomial(*p1 + *p2);
	
	//printing
	cout << "\n---Polynomial (C = A + B)---\n";
	cout << "getDegree(): " << p3->getDegree() << endl;
	cout << "toString(): " << p3->toString() << endl;
	cout << p3->evaluate(2) << endl;
	
	//assigning the sum of two object to an other object on heap
	Polynomial* p4 = new Polynomial(*p1 * *p2);

	//printing
	cout << "\n---Polynomial (D = A * B)---\n";
	cout << "getDegree(): " << p4->getDegree() << endl;
	cout << "toString(): " << p4->toString() << endl;
	cout << p4->evaluate(2) << endl;

	delete p1;
	delete p2;
	delete p3;
	delete p4;

	//   THE CODE BELOW COULD BE USED IF JUST THE DEGREE HAS TO BE PASSED TO THE CONSTRUCTOR
	//Polynomial* p1 = new Polynomial(1);
	//Polynomial* p2 = new Polynomial(1);

}

