#include "Store.h"

Store::Store(int _maxSize) : products(NULL), size(0), maxSize(_maxSize){
    products = new Product[maxSize];
    assert(products != NULL);
}

Store::Store(const Store& other) : size (other.size), maxSize (other.maxSize), products(NULL)
{
    if (other.size != 0)
    {
        products = new Product[other.maxSize];
        assert(products != NULL);

        for(int i = 0; i<size; i++)
        {
            products[i] = other.products[i];
        }
    }
}

Store::~Store()
{
    if(products != NULL)
        delete[] products;
}

bool Store::full()const
{
    return size == maxSize;
}

bool Store::empty()const
{
    return size==0;
}

int Store::findElement(char* name)const
{
    for(int i = 0; i<size; i++)
    {
        if(!strcmp(name, products[i].getName()))
            return i;
    }
    return -1;
}

Product Store::getElementAt(int i)const
{
    if(i < 0 || i >= size)
    {
        cout<<"There is no element on that position.\n";
        exit(1);
    }
    Product result(products[i]);
    return result;
}

void Store::setElementAt(int  i, const Product& other)
{
    if(i < 0 || i >= size)
    {
        cout<<"There is no element on that position.\n";
        exit(1);
    }
    products[i] = other;
}

void Store::addElement(const Product& other)
{
    if(full())
    {
        cout<<"The store is full\n";
        exit(1);
    }
    products[size] = other;
    size++;
}

void Store::removeElementFrom(int i)
{
    if(i < 0 || i >= size)
    {
        cout<<"There is no element on that position.\n";
        exit(1);
    }
    for(int j = i; j<size-1; j++)
    {
        products[j] = products[j+1];
    }
    size--;
}
