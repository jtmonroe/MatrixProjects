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
	// Problem 10.2.1

	CplexMat X = sigma_(Pauli::H);
	X.display();
	(X*X).display();

	system("PAUSE");
	return 0;
}

template <class T> void print(T out) { std::cout << out << std::endl; }
