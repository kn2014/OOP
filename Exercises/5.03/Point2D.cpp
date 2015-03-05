#include <iostream>

using namespace std;

class Point2D
{
    private:
        double X,Y;

    public:
        Point2D() { X=0; Y=0;} // konstruktor po podrazbirane
        Point2D (double, double);
        void SetX(double);
        void SetY(double);
        double GetX() const;
        double GetY() const;
        void print() const;
};

Point2D::Point2D(double x, double y)
{
    X=x; Y=y;
}

double Point2D::GetX() const
{
    return X;
}

double Point2D::GetY() const
{
    return Y;
}

void Point2D::SetX(double val)
{
    X=val;
}

void Point2D::SetY(double val)
{
    Y=val;
}

void Point2D::print() const
{
    cout<<X<<" "<<Y<<endl;
}

int main()
{
    Point2D A,B(1,2);
    A.print();
    B.print();
    return 0;
}
