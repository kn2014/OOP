
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
    Store& operator=(const Store& other);

    bool full()const;
    bool empty()const;
    int findElement(char* name)const;
    Product getElementAt(int i)const;
    void setElementAt(int  i, const Product& other);
    void addElement(const Product& other);
    void removeElementFrom(int i);
    void sortByName();
    void sortByPrice();
    void print();
    const Product** ptrSortByName();
    const Product** ptrSortByPrice();
    const Product& operator[](int i) const;
    Store operator- (int i)const;
    Store operator+ (const Product& other)const;
    Store operator+ (const Store& other)const;
    bool operator> (Store& other);


private:
    Product* products;
    const Product** ptrs;
    int maxSize;
    int size;
    void sorter(bool (*func) (const Product&, const Product&));
};

#endif

