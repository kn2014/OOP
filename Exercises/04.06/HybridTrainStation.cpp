#include "CargoTrainStation.cpp"
#include "PeopleTrainStation.cpp"

#pragma once

class HybridTrainStation : public CargoTrainStation, public PeopleTrainStation{

public:

    HybridTrainStation(const char* loc) : TrainStation(loc), CargoTrainStation(loc), PeopleTrainStation(loc){}

    bool isCargo()const {
        return true;
    }

    bool isPeople()const{
        return true;
    }
};
