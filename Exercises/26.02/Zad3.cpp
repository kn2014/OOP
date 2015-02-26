#include <iostream>
#include <string.h>

using namespace std;

bool way(char M[20][20], int sizeX, int sizeY, int x, int y, char* word, char* cur_word)
{
    if(!strcmp(word,cur_word)) { return 1; }
    if( strlen(cur_word)>=strlen(word) || x>=sizeX || x<0 || y>=sizeY || y<0)
    { return 0; }
    int l = strlen(cur_word);
    cur_word[l] = M[y][x];
    cur_word[l+1] = '\0';
    if (way(M,sizeX,sizeY,x+1,y+1,word,cur_word)) { return 1; }
    if (way(M,sizeX,sizeY,x+1,y-1,word,cur_word)) { return 1; }
    if (way(M,sizeX,sizeY,x-1,y+1,word,cur_word)) { return 1; }
    if (way(M,sizeX,sizeY,x-1,y-1,word,cur_word)) { return 1; }
    cur_word[l] = '\0';
    return 0;
}


int main()
{
    int m,n;
    const int sizeX = 6, sizeY =5;
    char M[20][20] = { {'a','b','v','d','d','z'},
                       {'c','f','g','h','z','w'},
                       {'a','a','q','y','w','e'},
                       {'b','m','v','d','d','e'},
                       {'m','h','k','d','w','z'}}, word[100], junk[100];
    junk[0]='\0';
    bool flag =0;
    for(int i=0;i<sizeY;i++)
    {
        for(int j=0;j<sizeX;j++)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }

    cin>>word;
    for(int i=0;i<sizeY;i++)
    {
        for(int j=0;j<sizeX;j++)
        {
            if(M[i][j]==word[0])
            {
                flag = flag || way(M,sizeY,sizeX,i,j,word,junk);
            }
        }
    }

    cout<<flag;

    return 0;
}
