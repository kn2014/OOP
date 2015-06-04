#include "Station.cpp"

#pragma once

class BusStation : public Station{
    unsigned seats[150];

public:

    BusStation(const char* loc = NULL) : Station(loc){
        for(int i = 0; i<150; i++){
            seats[i] = 0;
        }
    }

};
