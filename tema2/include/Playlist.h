#pragma once
#include "Song.h"

class Playlist
{
    private:
        Song* songs;
        size_t count;
        string name;
        int capacity;

        void ensureCapacity(int minCapacity);
    
    public:
        Playlist(const string& name);
        ~Playlist();
        //Copy constructor
        Playlist(const Playlist& other);
        //Move constructor
        Playlist(Playlist&& other) noexcept;
        //Copy assignment
        Playlist& operator=(const Playlist& other);
        //Move assignment
        Playlist& operator=(Playlist&& other) noexcept;
        string getName() const;
        void addSong(const Song& s);
        void setSong(size_t index, const Song& song);
        void print() const;
};