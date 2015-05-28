#include <iostream>
#include "Person.h"
#include "SoccerPlayer.h"
#include "TennisPlayer.h"
#include "DynamicCaster.h"

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
    SoccerPlayer* ps;
    if(ps=dynamic_cast<SoccerPlayer*>(&s))
    {
        ptr[3]= new SoccerPlayer(s);
    }
    ptr[3]->Print();

    DynamicCaster dyn;

    dyn.addPerson(&p);
    dyn.addPerson(&s);
    dyn.addPerson(&t);

    cout<<"======================================================"<<endl;
    dyn.print();

    DynamicCaster dyn2(dyn);

    //dyn2 = dyn;

    cout<<"======================================================"<<endl;
    dyn2.print();




    return 0;
}
