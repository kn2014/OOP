#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
    private:
        int     num,den;
        void    skr();

    public:
        Fraction(int = 0,int = 1);
        ~Fraction() {};
        int     getNum();
        int     getDen();
        void    setNum(int);
        void    setDen(int);
        void print() const;
        Fraction operator+(const Fraction&)const;
        Fraction operator+(const int&)const;
        Fraction operator-(const Fraction&)const;
        Fraction operator*(const Fraction&)const;
        Fraction operator/(const Fraction&)const;
        bool operator==(const Fraction&)const;
        bool operator>(const Fraction&)const;
        bool operator<(const Fraction&)const;
        friend Fraction operator+(const int&,const Fraction&);

};


#endif // FRACTION_H

