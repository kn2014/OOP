#pragma once
#include<cstring>
#include<cassert>

using namespace std;

class Station{
    char* location;
    unsigned transportNumber[150];
    bool leaving[150];

public:

    Station(const char *loc = NULL){
        if(loc != NULL){
            location = new char[strlen(loc) + 1];
            assert (location!=NULL);
            strcpy(location, loc);
        } else location = NULL;
        for(int i = 0; i<150; i++){
            transportNumber[i] = -1;
            leaving[i] = 0;
        }
    }

    virtual ~Station(){
        if(location != NULL){
            delete [] location;
        }
    }

    void setLocation(const char* loc){
        if(loc != NULL){
            location = new char[strlen(loc) + 1];
            assert (location!=NULL);
            strcpy(location, loc);
        }
    }

    void setTransportAt(unsigned where, unsigned number, bool _leaving){
        if(where < 150)
            transportNumber[where] = number;
            leaving[where] = _leaving;
    }

    const char* getLocation(){
        return location;
    }

    unsigned getTransportNumberAt(unsigned where){
        return transportNumber[where];
    }

    unsigned getLeavingAt(unsigned where){
        return leaving[where];
    }

};
