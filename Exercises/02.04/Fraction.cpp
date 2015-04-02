#include "Fraction.h"
#include<math.h>
#include<iostream>


int gcd(int a, int b)
{
    a = fabs(a);
    b = fabs(b);
  if (b == 0)
     return a;
  else
     return gcd(b, a%b);
}

int nok (int a, int b){
    return (a*b)/gcd(a, b);
}
void Fraction::skr()
{
    int k = gcd(num,den);
    num = num/k;
    den = den/k;
}

Fraction::Fraction(int n,int d )
{
    num = n;
    den = d;
    skr();
}

void Fraction::setDen(int d)
{
    if(d<=0) {  }
    den=d;
    skr();
}

void Fraction::setNum(int n)
{
    num=n;
    skr();
}

int Fraction::getNum()
{
    return num;
}

int Fraction::getDen()
{
    return den;
}

void Fraction::print()const{
    std::cout<<num<<"/"<<den<<std::endl;
}

Fraction Fraction::operator+(const Fraction& other) const
{
    Fraction result;
    result.den = nok(den, other.den);
    int n1 = result.den/den, n2 = result.den/other.den;
    result.num = num*n1 + other.num*n2;
    result.skr();
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const
{
    Fraction result;
    result.den = nok(den, other.den);
    int n1 = result.den/den, n2 = result.den/other.den;
    result.num = num*n1 - other.num*n2;
    result.skr();
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const{
    Fraction result;
    result.num = num * other.num;
    result.den = den * other.den;
    result.skr();
    return result;
}

Fraction Fraction::operator/(const Fraction& other) const{
    Fraction result;
    result.num = num * other.den;
    result.den = den * other.num;
    result.skr();
    return result;
}

bool Fraction::operator==(const Fraction& other) const{
    return num * other.den == den * other.num;
}

bool Fraction::operator<(const Fraction& other) const{
    return num * other.den < den * other.num;
}

bool Fraction::operator>(const Fraction& other) const{
    return !(*this<other);
}

Fraction operator+(const int& i, const Fraction& fr){
    Fraction result;
    result.den = fr.den;
    result.num = i * fr.den + fr.num;
    result.skr();
    return result;
}


