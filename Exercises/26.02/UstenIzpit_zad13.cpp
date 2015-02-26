#include<iostream>
using namespace std;

bool identificator(string str, int i){
    if(i == str.size())
        return true;
    const char* arr = str.c_str(); /// Прави string на const char*
    if(i == 0 && (arr[0] < 'a' || arr[0] > 'z') && arr[0] != '_')
        return false;
    if (!(arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= '0' && arr[i] <= '9' || arr[i] == '_'))
        return false;
    return identificator(str, i+1);

}
bool identificator (string str){
    return identificator (str, 0);
}


int main(){
    string str = "_a76sd";
    const char* arr = str.c_str();
    cout<<identificator(str)<<endl;
    cout<<str.size();

}
