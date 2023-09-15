#include <bits/stdc++.h>
using namespace std;

class Chandrayan
{
    private:
        int x,y,z;
        char face,prev;

    public:
        Chandrayan(int x1,int y1,int z1,char face1)
        {
            x=x1;
            y=y1;
            z=z1;
            face=face1;
            prev='-';
        }
        
        void forward()
        {
            if(face=='N') y++;
            else if(face=='S') y--;
            else if(face=='E') x++;
            else if(face=='W') x--;
            else if(face=='U') z++;
            else if(face=='D') z--;
        }

        void backward()
        {
            if(face=='N') y--;
            else if(face=='S') y++;
            else if(face=='E') x--;
            else if(face=='W') x++;
            else if(face=='U') z--;
            else if(face=='D') z++;
        }

        void printPosition()
        {
            cout<<"Current Position: ("<<x<<","<<y<<","<<z<<") Direction:"<<face<<endl;
        }
};

int main()
{
    int x1=0,y1=0,z1=0;
    char face1='W';
    Chandrayan c(x1,y1,z1,face1);
    char a[3]={'f','b','b'};
    for(int i=0;i<3;i++)
    {
        if(a[i]=='f') c.forward();
        else c.backward();
    }
    c.printPosition();
    return 0;
}