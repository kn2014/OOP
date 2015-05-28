#ifndef PERSON_H
#define PERSON_H

#include <string.h>
#include <iostream>

class Person
{
    public:
        Person();
        Person(const char*,bool,int);
        Person(const Person&);
        Person& operator=(const Person&);
        int GetAge() const;
        bool GetGender() const;
        const char* GetName() const;
        void SetAge(int);
        void SetName(const char*);
        void SetGender(bool);

        virtual void Print() const;

        virtual ~Person();

    protected:
        int age;
    private:
        char* name;
        bool gender;
};

#endif // PERSON_H
