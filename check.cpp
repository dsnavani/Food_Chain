#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct position
{
    int x;
    int y;
};

void field(list<position> pos,int length = 15, int width = 20)
{
    for(int w=0; w<width; w++)
    {
        cout<<"|";
        for(int l=0; l<length; l++)
        {
            if(w==0 || w==width-1) cout<<"===";
            else if(is_rabbit_position(l+1,w+1)) cout<<" R ";
            else if(is_lion_position(l+1,w+1)) cout<<" L ";
            else cout<<"   ";
        }
        cout<<"|"<<endl;
    }
}



int main()
{
    list<position> pos;
    position tpos;
    tpos.x = 2; tpos.y = 3;
    pos.push_back(tpos);
    field(pos);
}
