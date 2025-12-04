#pragma once
#include "Song.hpp"
#include<memory>
#include<string>
#include<iostream>
using namespace std;

class Playlist
{
    private:
        unique_ptr<Song[]> songs;
        size_t count;
        string name;
        int capacity;

        void ensureCapacity(int minCapacity);
    
    public:
        Playlist(const string& name);
        ~Playlist() = default;
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