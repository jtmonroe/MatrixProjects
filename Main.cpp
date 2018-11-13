#include <iostream>
#include <string>
#include "Matrix.h"
#include "Complex.h"
#include "Fraction.h"
#include "Quantum.h"

using MatMath::Matrix;
using FracMath::Fraction;
using ComplexMath::Complex;
using namespace QComputing;

typedef Complex<int> Cplex;

template <class T> void print(T out);


int main()
{	
	//Prepare Bits
	Matrix<Cplex> e00 = ei(2,0).tensor(ei(2,0));
	Matrix<Cplex> e01 = ei(2,0).tensor(ei(2,1));

	//Prepare Gate
	Matrix<Cplex> I = sigma_(Pauli::I);
	Matrix<Cplex> X = sigma_(Pauli::X);
	Matrix<Cplex> IX = I.tensor(X);
	IX.display();

	//Use Gate
	Matrix<Cplex> out = IX*e00;
	out.display();

	//Test output
	if (out == e01){
		print("EQUAL");
	} else {print("NOT");}

	return 0;
}

template <class T> void print(T out){std::cout << out << std::endl;}