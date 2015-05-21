#ifndef SOCCERPLAYER_H
#define SOCCERPLAYER_H

#include "Person.h"

class SoccerPlayer : public Person
{
    public:
        SoccerPlayer();
        SoccerPlayer(const char* _name, bool g, int _age,int _num, const char* _team, const char* _pos);
        SoccerPlayer(const SoccerPlayer&);
        SoccerPlayer& operator=(const SoccerPlayer&);
        virtual ~SoccerPlayer();
        int GetNumber() const { return num; }
        const char* GetTeamName() const {return team;}
        const char* GetPosition() const {return position;}

        void SetTeamName(const char*);
        void SetPosition(const char*);
        void SetNumber(int);
        void Print() const;
    private:
        int num;
        char* team;
        char position[5];
};

#endif // SOCCERPLAYER_H
