#include "Matrix.h"
#include "Complex.h"

using MatMath::Matrix;
using ComplexMath::Complex;

typedef Complex<double> Cplex;
typedef Matrix<Cplex> CplexMat;

namespace QComputing{

enum class Pauli{ I, X, Y, Z };

CplexMat ei(int n, int i)
{
    CplexMat e(n, 1);
    e.setPos(i, 0, Cplex(1, 0));
    return e;
}

CplexMat sigma_(enum Pauli in)
{
    CplexMat result(2,2);
    switch (in)
    {
        case Pauli::I: { Cplex c0[2] = {Cplex(1, 0), Cplex(0, 0)};
                         Cplex c1[2] = {Cplex(0, 0), Cplex(1, 0)};
                         result.setCol(c0,0);
                         result.setCol(c1,1);
                         //result.display();                    
                         return result; } 
        case Pauli::X: { Cplex c0[2] = {Cplex(0, 0), Cplex(1, 0)};
                         Cplex c1[2] = {Cplex(1, 0), Cplex(0, 0)};
                         result.setCol(c0,0);
                         result.setCol(c1,1);
                         //result.display();                    
                         return result; }
        case Pauli::Y: { Cplex c0[2] = {Cplex(0, 0), Cplex(0, -1)};
                         Cplex c1[2] = {Cplex(0, 1), Cplex(0, 0)};
                         result.setCol(c0,0);
                         result.setCol(c1,1);
                         //result.display();
                         return result; }
        case Pauli::Z: { Cplex c0[2] = {Cplex(1, 0), Cplex(0, 0)};
                         Cplex c1[2] = {Cplex(0, 0), Cplex(-1, 0)};
                         result.setCol(c0,0);
                         result.setCol(c1,1);
                         //result.display();
                         return result; }
    }
}

}