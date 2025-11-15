#include "Playlist.h"
#include<iostream>
#include<utility>
using namespace std;

Playlist::Playlist(const string& name)
        :name(name), songs(new Song[2]), count(0), capacity(2)
{
    cout<<"Constructor Playlist: "<<name<<endl;
}

Playlist::~Playlist()
{
    cout<<"Destructor Playlist: "<<name<<endl;
    delete[] songs;
}

void Playlist::ensureCapacity(int minCapacity)
{
    if(capacity >= minCapacity)
    {
        return;
    }
    int newCap = capacity;
    while(newCap < minCapacity)
    {
        newCap *= 2;
    }
    Song* newArray = new Song[newCap];
    for(int i = 0; i < count; i++)
    {
        newArray[i] = move(songs[i]);
    }
    delete[] songs;
    songs = newArray;
    capacity = newCap;
}

//Copy constructor
Playlist::Playlist(const Playlist& other)
        :name(other.name+" (copie)"), songs(new Song[other.capacity]), count(other.count), capacity(other.capacity)
{
    cout<<"Copy constructor Playlist: "<<other.name<<endl;
    for(size_t i = 0; i < count; i++)
    {
        songs[i] = other.songs[i];
    }
}

//Move constructor
Playlist::Playlist(Playlist&& other) noexcept
        :songs(other.songs), count(other.count), capacity(other.capacity), name(move(other.name))
{
    cout<<"Move constructor Playlist: "<<name<<endl;
    other.songs = nullptr;
    other.count = 0;
    other.name = "moved";
}

//Copy assignment
Playlist& Playlist::operator=(const Playlist& other)
{
    cout<<"Playlist copy assignment: "<<other.name<<endl;
    if(this == &other)
    {
        return *this;
    }
    delete[] songs;
    name = other.name;
    count = other.count;
    capacity = other.capacity;
    songs = new Song[capacity];
    for(int i = 0; i < count; i++)
    {
        songs[i] = other.songs[i];
    }
    return *this;
}

//Move assignment
Playlist& Playlist::operator=(Playlist&& other) noexcept
{
    cout<<"Playlist move assignment: "<<other.name<<endl;
    if(this == &other)
    {
        return *this;
    }
    delete[] songs;
    name = move(other.name);
    songs = other.songs;
    count = other.count;
    capacity = other.capacity;
    other.songs = nullptr;
    other.count = 0;
    other.capacity = 0;
    return *this;
}

string Playlist::getName() const
{
    return name;
}

void Playlist::addSong(const Song& s)
{
    ensureCapacity(count+1);
    songs[count++] = s;
}

void Playlist::setSong(size_t index, const Song& song)
{
    if(index < static_cast<size_t>(count))
    {
        songs[index] = song;
    }
    else
    {
        if(index == static_cast<size_t>(count))
        {
            addSong(song);
        }
        else
        {
            cout<<"setSong: index out of range"<<endl;
        }
    }
}

void Playlist::print() const
{
    cout<<"Playlist "<<name<<" ( "<<count<<" melodii )"<<endl;
    for(size_t i = 0; i < count; i++)
    {
        songs[i].print();
    }
}
