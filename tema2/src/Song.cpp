#include "Song.hpp"
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

Song::Song(const Song& other)
    : title(other.title), duration(other.duration)
{
    cout<<"Song copy constructor: "<<this->title<<endl;
}

Song::Song(Song&& other) noexcept
    : title(move(other.title)), duration(other.duration)
{
    cout<<"Song move constructor: "<<this->title<<endl;
    other.duration = 0;
}

Song& Song::operator=(const Song& other)
{
    cout<<"Song copy assignment: "<<other.title<<endl;
    if(this == &other)
    {
        return *this;
    }
    title = other.title;
    duration = other.duration;
    return *this;
}

Song& Song::operator=(Song&& other) noexcept
{
    cout<<"Song move assignment: "<<other.title<<endl;
    if(this == &other)
    {
        return *this;
    }
    title = move(other.title);
    duration = other.duration;
    other.duration = 0;
    return *this;
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