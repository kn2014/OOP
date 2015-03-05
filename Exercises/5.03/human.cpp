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

Human::Human(char* n)
{
    name = new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name,n);
}

Human::Human(const Human& other)
{
    if(other.name!=NULL)
    {
        name = new char[strlen(other.name)+1];
        assert(name!=NULL);
        strcpy(name,other.name);
    }
    else name =NULL;
}

const char* Human::GetName() const
{
    return name;
}

void Human::SetName(char* n)
{
    name = new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name,n);    
}

int main()
{
    Human A("AAA"),B(A);
    cout<<A.GetName()<<endl<<B.GetName()<<endl;
    return 0;
}
