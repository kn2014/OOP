#include "Product.h"

Product::Product(char* n,int q, double p) : name(NULL)
{
    if(n!=NULL)
    {
        SetName(n);
        SetPrice(p);
        SetQuantity(q);

    }
}

Product::Product(const Product& other) : name(NULL)
{
    if(other.name!=NULL)
    {
        SetName(other.name);
        SetPrice(other.price);
        SetQuantity(other.quantity);
    }
}

const char* Product::GetName() const
{
    return name;
}

int Product::GetQuantity() const
{
    return quantity;
}

double Product::GetPrice() const
{
    return price;
}

void Product::SetName(char* n)
{
    if(name!=NULL) { delete [] name; }
    name = new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name,n);
}

void Product::SetQuantity(int q)
{
    if(q>=0)
    {
        quantity = q;
    }
}

void Product::SetPrice(double p)
{
    if(p>=0)
    {
        price = p;
    }
}

Product& Product::operator=(const Product& other){
    if(this != &other){
        SetName(other.name);
        SetPrice(other.price);
        SetQuantity(other.quantity);
    }
    return *this;
}
