#include "Song.h"
#include<iostream>
using namespace std;

Song::Song(const string& title, int duration)
    : title(title), duration(duration)
{
    cout<<"Constructor Song: "<<this->title<<endl;
}

Song::~Song()
{
    cout<<"Destructor Song: "<<this->title<<endl;
}

string Song::getTitle() const
{
    return title;
}

int Song::getDuration() const
{
    return duration;
}

void Song::print() const
{
    cout<<"Song: "<<title<<" ( "<<duration<<" sec)"<<endl;
}