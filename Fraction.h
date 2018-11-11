#pragma once
#include <iostream>
#include <string>
#include "MathFunc.h"

namespace FracMath{
int gcd(int n, int k);

class Fraction
{
public:
    inline Fraction(int n = 0, int d = 1){if(d == 0){throw std::invalid_argument("denominator cannot be 0");} m_numer = n; m_denom = d;}
    
    inline Fraction operator+(const Fraction& f){return Fraction(m_numer*f.m_denom + m_denom*f.m_numer, m_denom*f.m_denom).reduce();}
    inline Fraction operator-(const Fraction& f){return Fraction((m_numer*f.m_denom - f.m_numer*m_denom), (m_denom*(f.m_denom))).reduce();}
    inline Fraction& operator+=(const Fraction& f){this->m_numer = m_numer*f.m_denom + m_denom*f.m_numer; this->m_denom = m_denom*f.m_denom; return *this;}
    inline Fraction operator*(const Fraction& f){return Fraction(m_numer*f.m_numer, m_denom*f.m_denom).reduce();}

    inline Fraction operator+(const int& c){return Fraction(m_numer + m_denom*c, m_denom).reduce();}
    inline Fraction operator-(const int& c){return Fraction((m_numer - c*m_denom), m_denom).reduce();}    
    inline Fraction operator*(const int& c){return Fraction(c*m_numer, m_denom).reduce();}

    inline operator double() const {return ((double) m_numer)/((double) m_denom);}

    inline Fraction reduce(){return Fraction(m_numer/MathFunc::gcd(m_numer, m_denom), m_denom/MathFunc::gcd(m_numer, m_denom));}
    inline std::string display()const{return (std::to_string(m_numer) + "/" + std::to_string(m_denom));}

private:
    int m_numer;
    int m_denom;
};


std::string to_string(const Fraction& f) {return f.display();}
}