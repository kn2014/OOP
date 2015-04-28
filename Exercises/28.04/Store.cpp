#include "Store.h"

Store::Store(int _maxSize) : products(NULL), size(0), maxSize(_maxSize){
    products = new Product[maxSize];
    ptrs = new const Product*[maxSize];
    assert(products != NULL);
    assert(ptrs != NULL);
}

Store::Store(const Store& other) : size (other.size), maxSize (other.maxSize), products(NULL)
{
    if (other.size != 0)
    {
        products = new Product[other.maxSize];
        ptrs = new const Product*[other.maxSize];
        assert(products != NULL);

        for(int i = 0; i<size; i++)
        {
            products[i] = other.products[i];
            ptrs[i] = &products[i] ;
        }
    }
}

Store::~Store()
{
    if(products != NULL)
    {
        delete[] products;
        delete[] ptrs;
    }


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
    ptrs[size]  = &products[size];
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

void Store::sorter(bool (*func) (const Product&, const Product&)){
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j < size ; j++){
            if(func(*ptrs[i], *ptrs[j])){
                swap(ptrs[i], ptrs[j]);
            }
        }
    }
}

bool cmpByName(const Product& p1, const Product& p2)
{
    return (strcmp(p1.getName(),p2.getName()))>0;
}

bool cmpByPrice(const Product& p1, const Product& p2)
{
    return p1.getPrice() > p2.getPrice();
}

void Store::sortByName()
{
    sorter(cmpByName);
}

void Store::sortByPrice(){
    sorter(cmpByPrice);
}

void Store::print()
{
    for(int i=0;i<size;i++)
    {
        cout<<ptrs[i]->getName()<<" "<<ptrs[i]->getPrice()<<" "<<ptrs[i]->getQuantity()<<endl;
    }
}

const Product** Store::ptrSortByName(){
    const Product *temp;
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j < size ; j++){
            if(strcmp(ptrs[i]->getName(), ptrs[j]->getName())>0){
                temp = ptrs[i];
                ptrs[i] = ptrs[j];
                ptrs[j] = temp;
            }
        }
    }
    return ptrs;
}

const Product** Store::ptrSortByPrice(){
    const Product *temp;
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j < size ; j++){
            if(ptrs[i]->getPrice()>ptrs[j]->getPrice()){
                temp = ptrs[i];
                ptrs[i] = ptrs[j];
                ptrs[j] = temp;
            }
        }
    }
    return ptrs;
}

const Product& Store::operator[](int i)const
{
    if(i<=size)
        return products[i];
    else{
        cout<<"No element on that position.\n";
        exit(1);
    }
}

Store& Store::operator=(const Store& other){
    if(&other != this){
        this->~Store();
        size = other.size;
        maxSize = other.maxSize;
        products = new Product[maxSize];
        ptrs = new const Product*[maxSize];
        for(int i = 0; i<size; i++)
        {
            products[i] = other.products[i];
            ptrs[i] = &products[i] ;
        }
    }

    return *this;
}

Store Store::operator- (int i)const{
    if(i>size){
        cout<<"No element on that position.\n";
        exit(1);
    }

    Store result(*this);
    result.removeElementFrom(i);
    return result;
}

Store Store::operator+ (const Product& other)const{
    if(full())
    {
        cout<<"The store is full\n";
        exit(1);
    }

    Store result(*this);

    result.products[size] = other;
    result.ptrs[size]  = &products[size];
    result.size++;

    return result;
}

Store Store::operator+ (const Store& other)const{
     Store result;

    if(&other != NULL){
        result.maxSize = maxSize + other.maxSize;
        result.size = size + other.size;
        result.products = new Product[result.maxSize];
        result.ptrs = new const Product*[result.maxSize];
        int i;
        for(i = 0; i<size; i++){
            result.products[i] = products[i];
            ptrs[i] = &result.products[i];
        }

        for(int j = 0; j<other.size; j++){
            result.products[i+j] = other.products[j];
            ptrs[i+j] = &result.products[i+j];
        }

        return result;

    }

    result = *this;

    return result;
}

bool Store::operator> (Store& other){
    this->sortByName();
    other.sortByName();

    for(int i = 0; i<min(this->size, other.size); i++){
        if(strcmp(ptrs[i]->getName(), other.ptrs[i]->getName()) > 0)
            return false;
        else if(strcmp(ptrs[i]->getName(), other.ptrs[i]->getName()) < 0)
            return true;
    }

    return size < other.size;

}

