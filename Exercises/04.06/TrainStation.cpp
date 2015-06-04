#include "Station.cpp"

#pragma once

class TrainStation : public Station{

public:

    TrainStation(const char* loc = NULL) : Station(loc){}

    virtual bool isCargo() const = 0;
    virtual bool isPeople() const = 0;

};
