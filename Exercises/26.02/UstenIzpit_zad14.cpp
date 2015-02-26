#include<iostream>
using namespace std;

double value(double *a, int n, int i){
    if(i == n-1)    return a[i];
    return (a[i] + 1/value(a, n, i+1));
}

double value(double *a, int n){
    return value(a, n, 0);
}

int main() {
    double arr[5] = {1,2,3,4,5};

    cout<<value(arr, 5);
}
