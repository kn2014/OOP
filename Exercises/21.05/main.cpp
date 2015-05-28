#include <iostream>
#include "Person.h"
#include "SoccerPlayer.h"
#include "TennisPlayer.h"

using namespace std;

int main()
{
    Person* ptr[10];
    Person p("P",0,20);
    Person p1=p;
    SoccerPlayer s("SP",1,30,1,"Barca","GK");
    TennisPlayer t("fdsfds",0,21,12,3,4);
    ptr[0]=&p;
    ptr[1]=&s;
    ptr[2]=&t;

    ptr[1]->Print();


    return 0;
}
