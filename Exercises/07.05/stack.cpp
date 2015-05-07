#include<iostream>
#include<cassert>
using namespace std;

template <typename T>
class stack{
private:
    T* arr;
    int current;
    int size;

public:
    stack(int s = 20) : size(s), current(0)
    {
        arr = new T[size];
        assert(arr != NULL);
    }

    ~stack()
    {
        delete [] arr;
    }

    void push(const T what)
    {
        if(size<current){
            arr[current] = what;
            current++;
        } else {
            T* temp = new T[2*size];
            assert(temp != NULL);
            for(int i = 0; i<size; i++){
                temp[i] = arr[i];
            }
            size = 2*size;
            delete [] arr;
            arr = temp;
            arr[current++] = what;
        }

    }

    T pop ()
    {
        if(!isEmpty()){
            current--;
            return arr[current];
        }
        cout<<"The stack is empty."<<endl;
        T dummy;
        return dummy;
    }

    bool isEmpty()const
    {
        return current == 0;
    }

    bool print(){
        while(!isEmpty()){
            cout<<pop()<<endl;
        }
    }

};

int main(){
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.print();
}
