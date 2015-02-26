#include <iostream>
#include <math.h>

using namespace std;

struct Point2D
{
    double x,y;
};

struct Triangle
{
    Point2D P1,P2,P3;
};

double my_distance(Point2D p1, Point2D p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double Area(Triangle T)
{
    double S,p,a,b,c;
    a= my_distance(T.P1,T.P2);
    b= my_distance(T.P1,T.P3);
    c= my_distance(T.P3,T.P2);
    p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main ()
{
    Triangle T;
    cout<<"Koordinati na A: "; cin>>T.P1.x>>T.P1.y;
    cout<<"Koordinati na B: "; cin>>T.P2.x>>T.P2.y;
    cout<<"Koordinati na B: "; cin>>T.P3.x>>T.P3.y;
    cout<<Area(T);
    return 0;
}
