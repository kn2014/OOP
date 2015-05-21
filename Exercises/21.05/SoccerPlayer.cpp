#include "SoccerPlayer.h"

SoccerPlayer::SoccerPlayer()
{
    team = nullptr;
}

SoccerPlayer::~SoccerPlayer()
{
    if(team!=nullptr)
    {
        delete [] team;
    }
}

SoccerPlayer::SoccerPlayer(const char* _name, bool g, int _age,int _num, const char* _team, const char* _pos) : Person(_name,g,_age) , team(nullptr)
{
    SetTeamName(_team);
    SetPosition(_pos);
    SetNumber(_num);
}

SoccerPlayer::SoccerPlayer(const SoccerPlayer& ot) : Person(ot.GetName(),ot.GetGender(),ot.age) , team(nullptr)
{
    SetTeamName(ot.team);
    SetPosition(ot.position);
    SetNumber(ot.num);
}

SoccerPlayer& SoccerPlayer::operator=(const SoccerPlayer& ot)
{
    if(this!=&ot)
    {
        this->Person::operator=(ot);
        SetTeamName(ot.team);
        SetPosition(ot.position);
        SetNumber(ot.num);
    }
    return *this;
}

void SoccerPlayer::SetTeamName(const char* _team)
{
    if(_team!=nullptr)
    {
        if(team!=nullptr)
        {
            delete [] team;
        }
        team = new char[strlen(_team)+1];
        strcpy(team,_team);
    }
}

void SoccerPlayer::SetNumber(int n)
{
    if(n>0)
    {
        num=n;
    }
}

void SoccerPlayer::SetPosition(const char* p)
{
    strcpy(position,p);
}

void SoccerPlayer::Print() const
{
    Person::Print();
    std::cout<<"Team:\t"<<team<<std::endl;
    std::cout<<"Pos:\t"<<position<<std::endl;
    std::cout<<"Number:\t"<<num<<std::endl;
}

