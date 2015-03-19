#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <string.h>
#include <cassert>
#include "Product.h"
#include <stdlib.h>

class Store
{
public:
    Store(int maxSize = 20);
    Store(const Store& other);
    ~Store();
    bool full()const;
    bool empty()const;
    int findElement(char* name)const;
    Product getElementAt(int i)const;
    void setElementAt(int  i, const Product& other);
    void addElement(const Product& other);
    void removeElementFrom(int i);

private:
    Product* products;
    int maxSize;
    int size;
};

#endif
