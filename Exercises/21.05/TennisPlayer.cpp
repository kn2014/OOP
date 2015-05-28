#include "TennisPlayer.h"

TennisPlayer::TennisPlayer()
{
    //ctor
}

TennisPlayer::TennisPlayer(const TennisPlayer& ot) : Person(ot)
{
    rank = ot.rank;
    win = ot.win;
    lost = ot.lost;
}

TennisPlayer::TennisPlayer(const char* _name,bool _gender,int _age,int _rank,int _win,int _lost) : Person(_name,_gender,_age) , win(_win), rank(_rank) , lost(_lost)
{

}

TennisPlayer::~TennisPlayer()
{
    //dtor
}

void TennisPlayer::SetRank(int _rank)
{
    if(_rank>0) { rank=_rank; }
}

void TennisPlayer::SetWin(int _win)
{
    if(_win>0) { win=_win; }
}

void TennisPlayer::SetLost(int _lost)
{
    if(_lost>0) { lost=_lost; }
}

void TennisPlayer::Print() const
{
    Person::Print();
    std::cout<<"Rank: "<<rank<<std::endl<<"Win: "<<win<<std::endl<<"Lost: "<<lost<<std::endl;
}
