#include "TrainStation.cpp"

#pragma once

class PeopleTrainStation : virtual public TrainStation{

    unsigned seats[150];

public:

    PeopleTrainStation(const char* loc) : TrainStation(loc){
        for(int i = 0; i<150; i++){
            seats[i] = 0;
        }
    }

    void setSeatsAt(unsigned where, float what){
        seats[where] = what;
    }

    unsigned getSeatsAt(unsigned where){
        return seats[where];
    }

    bool isCargo()const {
        return false;
    }

    bool isPeople()const{
        return true;
    }

};
