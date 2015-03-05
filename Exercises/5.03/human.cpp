#include <iostream>
#include <string.h>
#include <cassert>

using namespace std;

class Human
{
    private :
        char* name;

    public :
        Human() { name = NULL; }
        ~Human() { if(name!=NULL) { delete [] name; } }
        Human(char*);
        Human(const Human&);
        const char* GetName() const;
        void SetName(char*);

};

Human::Human(char* n) : name(NULL)
{
    if(n!=NULL)
    {
        SetName(n);
    }
}

Human::Human(const Human& other) : name(NULL)
{
    if(other.name!=NULL)
    {
       SetName(other.name);
    }
}

const char* Human::GetName() const
{
    return name;
}

void Human::SetName(char* n)
{
    if(name!=NULL) { delete [] name; }
    name = new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name,n);
}

int main()
{
    Human A("AAA"),C("CCC"),B;
    B.SetName("Q");
    B.SetName("BBB");
    cout<<A.GetName()<<endl<<B.GetName()<<endl<<C.GetName();
    return 0;
}
