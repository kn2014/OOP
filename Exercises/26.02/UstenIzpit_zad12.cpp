#include<iostream>
using namespace std;

int const m = 4;
int const n = 2;

bool increasing(int* arr, int i){
    cout<<"i="<<i<<endl;
    if(i == n)  return true;
    if(arr[i-1]<arr[i]){
        return increasing(arr, i+1);
    }
    return false;
}

bool increasing(int* arr){
    increasing(arr, 1);
}

bool anyIncreasing(int arr[m][n]){
    for(int i = 0; i<m; i++){
        if(increasing(arr[i])){
                return true;
        }
    }
    return false;
}

int main(){
    int arr[4][2] = {{2,1}, {3,2}, {4,1}, {10,11}};
    cout<<anyIncreasing(arr);
}
