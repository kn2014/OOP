#include "TrainStation.cpp"

#pragma once

class CargoTrainStation : virtual public TrainStation{
    float load[150];

public:

    CargoTrainStation(const char* loc = NULL) : TrainStation(loc){
        for(int i = 0; i<150; i++){
            load[i] = 0;
        }
    }

    void setLoadAt(unsigned where, float what){
        load[where] = what;
    }

    float getLoadAt(unsigned where){
        return load[where];
    }

    bool isCargo()const {
        return true;
    }

    bool isPeople()const{
        return false;
    }

};

