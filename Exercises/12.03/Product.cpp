#include "Product.h"

Product::Product() : name(NULL), quantity(0), price(0){}

Product::Product(char* n, int q, double p) : name(NULL)
{
    if(n!=NULL)
    {
        setName(n);
        setPrice(p);
        setQuantity(q);
    }
}

Product::Product(const Product& other) : name(NULL)
{
    if(other.name!=NULL)
    {
        setName(other.name);
        setPrice(other.price);
        setQuantity(other.quantity);
    }
}
Product::~Product()
{
    if(name!=NULL)
    {
        delete [] name;
    }
}
const char* Product::getName() const
{
    return name;
}
int Product::getQuantity() const
{
    return quantity;
}

double Product::getPrice() const
{
    return price;
}
void Product::setName(char* n)
{
    if(name!=NULL)
    {
        delete[] name;
    }
    name = new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name,n);
}
void Product::setQuantity(int q)
{
    if(q>=0)
    {
        quantity = q;
    }
}
void Product::setPrice(double p)
{
    if(p>=0)
    {
        price = p;
    }
}

Product& Product::operator=(const Product& other)
{

    if(this != &other)
    {
        setName(other.name);
        setPrice(other.price);
        setQuantity(other.quantity);
    }
    return *this;
}

