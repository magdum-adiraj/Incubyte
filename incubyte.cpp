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

        void left()
        {
            if(face=='N') face='W';
            else if(face=='W') face='S';
            else if(face=='S') face='E';
            else if(face=='E') face='N';
            else if(face=='U' or face=='D')
            {
                if(prev=='N') face='W';
                else if(prev=='W') face='S';
                else if(prev=='S') face='E';
                else if(prev=='E') face='N';
            } 
        }

        void right()
        {
            if(face=='N') face='E';
            else if(face=='W') face='N';
            else if(face=='S') face='W';
            else if(face=='E') face='S';
            else if(face=='U' or face=='D')
            {
                if(prev=='N') face='E';
                else if(prev=='W') face='N';
                else if(prev=='S') face='W';
                else if(prev=='E') face='S';
            } 
        }

        void printPosition()
        {
            cout<<"Current Position: ("<<x<<","<<y<<","<<z<<") Direction:"<<face<<endl;
        }
};

int main()
{
    int x1=0,y1=0,z1=0;
    char face1='N';
    Chandrayan c(x1,y1,z1,face1);
    char a[3]={'f','l','b'};
    for(int i=0;i<3;i++)
    {
        if(a[i]=='f') c.forward();
        else if(a[i]=='b') c.backward();
        else if(a[i]=='l') c.left();
        else if(a[i]=='r') c.right();
    }
    c.printPosition();
    return 0;
}