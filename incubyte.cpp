#include <bits/stdc++.h>
using namespace std;

class Chandrayan
{
    private:
        int x,y,z;
        char face,prev;

    public:
        Chandrayan(int x1,int y1,int z1,char face1)            //Initializing with starting coordinates and direction
        {
            x=x1;
            y=y1;
            z=z1;
            face=face1;
            prev='-';
        }
        
        void forward()                                         //Accoringly Add coordinates and direction remains same
        {
            if(face=='N') y++;
            else if(face=='S') y--;
            else if(face=='E') x++;
            else if(face=='W') x--;
            else if(face=='U') z++;
            else if(face=='D') z--;
        }

        void backward()                                        //Accoringly Add coordinates and direction remains same
        {
            if(face=='N') y--;
            else if(face=='S') y++;
            else if(face=='E') x--;
            else if(face=='W') x++;
            else if(face=='U') z--;
            else if(face=='D') z++;
        }

        void left()                                            //Rotated directions
        {
            if(face=='N') face='W';
            else if(face=='W') face='S';
            else if(face=='S') face='E';
            else if(face=='E') face='N';
            else if(face=='U' or face=='D')                 //When Up or Down the left and right depends on prev direction 
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

        void up()
        {
            if(face!='U' or face!='D')
            {
                prev=face;
                face='U';
            }
            else if(face=='D')                                  //When it is up and instructed to Down it will return to its prev direction
            {
                face=prev;
            }
            // Here Up when already face=Up is invalid arguement 
        }

        void down()
        {
            if(face!='U' or face!='D')
            {
                prev=face;
                face='D';
            }
            else if(face=='U')
            {
                face=prev;
            }
            //Here down when already face=down is invalid arguement
        }

        void printPosition()
        {
            cout<<"Final Position: ("<<x<<","<<y<<","<<z<<") Direction:"<<face<<endl;
        }
};

int main()
{
    int x1,y1,z1;
    char face1;
    cout<<"Enter initial X co-ordinate:";
    cin>>x1;
    cout<<"Enter initial Y co-ordinate:";
    cin>>y1;
    cout<<"Enter initial Z co-ordinate:";
    cin>>z1;
    cout<<"Enter initial direction:";
    cin>>face1;
    Chandrayan c(x1,y1,z1,face1);
    vector<char> a;
    char b;
    while(true)
    {
        cout<<"Enter instruction(f=forward, b=backward, l=left, r=right, u=up, d=down, e=exit):";
        cin>>b;
        if(b=='e') break;
        else a.push_back(b);
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='f') c.forward();
        else if(a[i]=='b') c.backward();
        else if(a[i]=='l') c.left();
        else if(a[i]=='r') c.right();
        else if(a[i]=='u') c.up();
        else if(a[i]=='d') c.down();
    }
    c.printPosition();
    return 0;
}