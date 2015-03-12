#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string.h>
#include <cassert>

using namespace std;

class Product
{
    private :
        char* name;
        int quantity;
        double price;
    public :
        Product() { name = NULL; quantity=0; price=0; }
        ~Product() { if(name!=NULL) { delete [] name; } }
        Product(char*,int,double);
        Product(const Product&);
        double GetPrice() const;
        int GetQuantity() const;
        const char* GetName() const;
        void SetName(char*);
        void SetQuantity(int);
        void SetPrice(double);
};


#endif // PRODUCT_H
