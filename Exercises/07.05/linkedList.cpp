#include<iostream>
#include<cassert>
using namespace std;

template <typename T>
struct node{
    T inf;
    node<T>* link;
};

template <typename T>
class linkedList{
private:
    node<T>* first;
    node<T>* current;
    unsigned size;

public:
    linkedList()
    {
        first = NULL;
        current = NULL;
        size = 0;
    }
//
//    ~linkedList()
//    {
//
//    }

    void addElementAt(const T what, int where){
        node<T>* temp = new node<T>;
        temp->inf = what;
        if(first==NULL)
        {
            first = temp;
            first->link = NULL;
            size = 1;
        }
        else
        {
            current = first;
            int i = 0;
            while(i<where-1)
            {
                if(current->link==NULL) { cout<<"Error";}
                else { current = current->link; }
                i++;
            }
            temp->link = current->link;
            current->link = temp;
            size++;
        }
    }

    T removeFrom(int where)
    {
        if(where==0)
        {
            node<T>* tmp = first;
            T res = first->inf;
            first = first->link;
            delete tmp;
            size--;
            return res;
        }
        else
        {
            current = first;
            int i = 0;
            while(i<where-1)
            {
                if(current->link==NULL) { cout<<"Error";}
                else { current = current->link; }
                i++;
            }
            node<T>* temp = current->link;
            T result = temp->inf;
            current->link = current->link->link;
            delete temp;
            size--;
            return result;
        }
    }

    T elementAt(int where)
    {
        current= first;
        int i=0;
        while(current!=NULL && i<where)
        {
            current=current->link;
            i++;
        }
        return current->inf;
    }

    void print()
    {
        current = first;
        while(current)
        {
            cout<<current->inf<<endl;
            current = current->link;
        }
    }
};

int main()
{
    linkedList<int> l;
    l.addElementAt(1,0);
    l.addElementAt(2,1);
    l.addElementAt(3,2);

    cout<<l.elementAt(0)<<endl;

    l.print();
    return 0;
}
