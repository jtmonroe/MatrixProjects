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

template <class T> void print(T out);

int main()
{
	print("TEST");
	//Prepare Bits
	CplexMat e00 = ei(2,0).tensor(ei(2,0));
	CplexMat e01 = ei(2,0).tensor(ei(2,1));

	//Prepare Gate
	CplexMat I = sigma_(Pauli::I);
	CplexMat X = sigma_(Pauli::X);
	CplexMat IX = I.tensor(X);
	IX.display();

	//Use Gate
	CplexMat out = IX*e00;
	out.display();

	//Test output
	if (out == e01){
		print("EQUAL");
	} else {print("NOT");}

	return 0;
}

template <class T> void print(T out){std::cout << out << std::endl;}
