#include<iostream>

using namespace std;

class Zelen4yk{
    public:
    virtual bool isKopur() = 0;
};

class Kopur : public Zelen4yk{
public:

    bool isKopur(){
        return 1;
    }

};

class Magdanoz : public Zelen4yk{
public:

    bool isKopur(){
        return 0;
    }

};

void Zelen4ykCounts(Zelen4yk** arr, int& kopur, int& magdanoz, int size){
    kopur = 0;
    magdanoz = 0;
    for(int i = 0; i<size; i++){
        kopur += arr[i]->isKopur();
        magdanoz += !arr[i]->isKopur();
    }
}

int main(){
    //Zelen4yk **zel = new Zelen4uk*[10];
    Zelen4yk *zel[10];

    Kopur k;

    Magdanoz z;

    zel[0] = &k;
    zel[1] = &z;
    zel[2] = &k;
    zel[3] = &k;
    zel[4] = &z;
    zel[5] = &k;

    int kopur;
    int magdanoz;

    Zelen4ykCounts(zel, kopur, magdanoz, 6);
    cout<<"kopuri "<<kopur<<" broq\nmagdanozi "<<magdanoz<<" broq\n";
}
