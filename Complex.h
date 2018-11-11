#pragma once
#include <iostream>
#include <string>

//template <class T>
namespace ComplexMath {

template <class T> class Complex
{
public:
    inline Complex(T real = 0.0, T imag = 0.0) {m_real = real; m_imag = imag;}

    inline Complex<T> operator+(const Complex<T>& z){return Complex(this->m_real + z.m_real, this->m_imag + z.m_imag);}
    inline Complex<T> operator*(const T& c){return Complex(m_real*c, m_imag*c);}
    inline Complex<T> operator*(const Complex<T>& z){return Complex((m_real*z.m_real-m_imag*z.m_imag), (m_real*z.m_imag +  m_imag*z.m_real));}
    inline Complex<T>& operator+=(const Complex<T>& z){this->m_real += z.m_real; this->m_imag += z.m_imag; return *this;}

    inline operator double(){return Complex((double) m_real, (double) m_imag);}

    inline std::string display()const{return (to_string(m_real) + " + " + to_string(m_imag) + "i");}

private:
    T m_real;
    T m_imag;
};
    template <class T>
    std::string to_string(const Complex<T>& z) {return z.display();}
}