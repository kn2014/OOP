#include "Person.h"

Person::Person()
{
    name = nullptr;
}

Person::Person(const Person& ot) : name(nullptr)
{
    SetAge(ot.age);
    SetGender(ot.gender);
    SetName(ot.name);
}

Person& Person::operator=(const Person& ot)
{
    if(this!=&ot)
    {
        SetAge(ot.age);
        SetGender(ot.gender);
        SetName(ot.name);
    }
    return *this;
}

Person::Person(const char* _name, bool g,int _age) : name(nullptr)
{
    SetName(_name);
    SetAge(_age);
    SetGender(g);
}
Person::~Person()
{
    if(name!=nullptr)
    {
        delete [] name;
    }
}

void Person::SetName(const char* _name)
{
    if(_name!=nullptr)
    {
        if(name!=nullptr)
        {
            delete [] name;
        }
        name = new char[strlen(_name)+1];
        strcpy(name,_name);
    }
}

void Person::SetAge(int _age)
{
    if(_age>=0)
    {
        age=_age;
    }
}

void Person::SetGender(bool g)
{
    gender=g;
}

int Person::GetAge() const
{
    return age;
}

bool Person::GetGender() const
{
    return gender;
}

const char* Person::GetName() const
{
    return name;
}

virtual void Person::Print() const
{
    std::cout<<"Name:\t"<<name<<std::endl;
    if(gender==1)
    {
        std::cout<<"Gender:\tMale"<<std::endl;
    }
    else
    {
        std::cout<<"Gender:\tFemale"<<std::endl;
    }
    std::cout<<"Age:\t"<<age<<std::endl;
}
