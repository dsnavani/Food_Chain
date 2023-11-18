#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<windows.h>
#include <unistd.h>

#define LENGTH 15
#define WIDTH 15
using namespace std;


struct position
{
    int x;
    int y;
};
/* ***********************CLASS ANIMAL***************************/
class Animal
{
private:
    int food;
    int max_speed;
    int vision_limit;

public:
    position current_position;
    Animal(int food,int max_speed,int vision_limit)
    {
        this->food = food;
        this->max_speed = max_speed;
        this->vision_limit = vision_limit;
    }
};
/***************************CLASS LION*************************/
class Lion : public  Animal
{
private:

public:
    Lion() : Animal(0,2,6)
    {};
};
/***************************CLASS RABBIT*************************/
class Rabbit : public  Animal
{
private:

public:
    Rabbit() : Animal(0,3,7)
    {};
};
/*************************2D FIELD******************************************/

bool is_rabbit_position(const list<Rabbit> &rabbit_list,int l, int w)
{
    for(auto it = rabbit_list.begin(); it!=rabbit_list.end(); ++it)
    {
        if(it->current_position.x == l && it->current_position.y == w) return true;
    }
    return false;
}

bool is_lion_position(const list<Lion> &lion_list,int l, int w)
{
    for(auto it = lion_list.begin(); it!=lion_list.end(); ++it)
    {
        if(it->current_position.x == l && it->current_position.y == w) return true;
    }
    return false;
}

void field(const list<Lion> &lion_list,const list<Rabbit> &rabbit_list,int length = LENGTH, int width = WIDTH)
{
    width++;
    for(int w=-1; w<width; w++)
    {
        cout<<"|";
        for(int l=0; l<length; l++)
        {
            if(w==-1 || w==width-1) cout<<"===";
            else if(is_rabbit_position(rabbit_list,l+1,w+1)) cout<<" R ";
            else if(is_lion_position(lion_list,l+1,w+1)) cout<<" L ";
            else cout<<"    ";
        }
        cout<<"|"<<endl;
    }
}
/******************************************************************/

int main()
{
    list<Lion> lion_list;
    list<Rabbit> rabbit_list;
    Lion first; Rabbit second;
    lion_list.push_back(first);
    rabbit_list.push_back(second);
    field(lion_list,rabbit_list);
}
