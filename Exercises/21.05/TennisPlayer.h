#ifndef TENNISPLAYER_H
#define TENNISPLAYER_H
#include "Person.h"

class TennisPlayer : public Person
{
    public:
        TennisPlayer();
        TennisPlayer(const TennisPlayer&);
        TennisPlayer(const char*,bool,int,int,int,int);
        TennisPlayer& operator=(const TennisPlayer&);
        virtual ~TennisPlayer();
        void Print() const;
        int GetRank()  const { return rank; }
        int GetWin() const { return win; }
        int GetLost() const { return lost; }
        void SetWin(int);
        void SetLost(int);
        void SetRank(int);
    protected:
    private:
        int rank;
        int win;
        int lost;
};

#endif // TENNISPLAYER_H
