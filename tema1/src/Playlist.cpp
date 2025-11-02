#include "Playlist.h"
#include<iostream>
using namespace std;

Playlist::Playlist(const string& name, size_t count)
        :name(name), count(count)
{
    cout<<"Constructor Playlist: "<<name<<endl;
    songs = new Song[count];
}

Playlist::~Playlist()
{
    cout<<"Destructor Playlist: "<<name<<endl;
    delete[] songs;
}

//Copy constructor
Playlist::Playlist(const Playlist& other)
        :name(other.name+" (copie)"), count(other.count)
{
    cout<<"Copy constructor Playlist: "<<name<<endl;
    songs = new Song[count];
    for(size_t i = 0; i < count; i++)
    {
        songs[i] = other.songs[i];
    }
}

//Move constructor
Playlist::Playlist(Playlist&& other) noexcept
        :songs(nullptr), count(0), name(move(other.name))
{
    cout<<"Move constructor Playlist: "<<name<<endl;
    songs = other.songs;
    count = other.count;
    other.songs = nullptr;
    other.count = 0;
    other.name = "moved";
}

string Playlist::getName() const
{
    return name;
}

void Playlist::setSong(size_t index, const Song& song)
{
    if(index < count)
    {
        songs[index] = song;
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
