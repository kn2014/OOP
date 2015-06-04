#include "Station.cpp"

#pragma once

class Airport : public Station{
    int seats[150];

public:

    Airport(const char* loc = NULL) : Station(loc){
        for(int i = 0; i<150; i++){
            seats[i] = 0;
        }
    }

};
