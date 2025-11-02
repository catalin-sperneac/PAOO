#pragma once
#include "Song.h"

class Playlist
{
    private:
        Song* songs;
        size_t count;
        string name;
    
    public:
        Playlist(const string& name, size_t count);
        ~Playlist();
        //Copy constructor
        Playlist(const Playlist& other);
        //Move constructor
        Playlist(Playlist&& other) noexcept;
        //Getter
        string getName() const;
        //Setter
        void setSong(size_t index, const Song& song);
        //Afisare
        void print() const;
};