#ifndef DYNAMICCASTER_H
#define DYNAMICCASTER_H

#include "Person.h"
#include "SoccerPlayer.h"
#include "TennisPlayer.h"

class DynamicCaster
{
    public:
        DynamicCaster();
        virtual ~DynamicCaster();
        DynamicCaster(const DynamicCaster& other);
        DynamicCaster& operator=(const DynamicCaster& other);
        void addPerson (const Person* p);
        void print()const;
    protected:
    private:
        Person* people[10];
        int size;
};

#endif // DYNAMICCASTER_H
