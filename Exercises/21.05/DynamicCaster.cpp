#include "DynamicCaster.h"
#include<cstdlib>

DynamicCaster::DynamicCaster() : size(0)
{

}

DynamicCaster::~DynamicCaster()
{
    for(int i = 0; i<size; i++){
        delete people[i];
    }
}

DynamicCaster::DynamicCaster(const DynamicCaster& other) : size(0)
{
    const Person *p;
    const SoccerPlayer *s;
    const TennisPlayer *t;



    for(int i = 0; i<other.size; i++, size++){
        p = dynamic_cast<const Person*>(other.people[i]);

        if(p){
            people[i] = new Person(*p);
        }

        s = dynamic_cast<const SoccerPlayer*>(other.people[i]);

        if(s){
            people[size] = new SoccerPlayer(*s);
        }

        t = dynamic_cast<const TennisPlayer*>(other.people[i]);

        if(t){
            people[size] = new TennisPlayer(*t);
        }

    }

}

DynamicCaster& DynamicCaster::operator=(const DynamicCaster& other)
{
    if (this == &other) return *this;

    this->~DynamicCaster();

    size = 0;

    const Person *p;
    const SoccerPlayer *s;
    const TennisPlayer *t;

    for(int i = 0; i<other.size; i++, size++){
        p = dynamic_cast<const Person*>(other.people[i]);

        if(p){
            people[i] = new Person(*p);
        }

        s = dynamic_cast<const SoccerPlayer*>(other.people[i]);

        if(s){
            people[size] = new SoccerPlayer(*s);
        }

        t = dynamic_cast<const TennisPlayer*>(other.people[i]);

        if(t){
            people[size] = new TennisPlayer(*t);
        }

    }

    return *this;
}

void DynamicCaster::addPerson(const Person* who){

    if(size<10){

    const Person *p;
    const SoccerPlayer *s;
    const TennisPlayer *t;

        p = dynamic_cast<const Person*>(who);

        if(p){
            people[size] = new Person(*p);
        }

        s = dynamic_cast<const SoccerPlayer*>(who);

        if(s){
            people[size] = new SoccerPlayer(*s);
        }

        t = dynamic_cast<const TennisPlayer*>(who);

        if(t){
            people[size] = new TennisPlayer(*t);
        }

        size++;

    }
}

void DynamicCaster::print() const
{
    for(int i=0;i<size;i++)
    {
        people[i]->Print();
        std::cout<<"\n";
    }
}
