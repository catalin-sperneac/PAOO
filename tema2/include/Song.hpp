#pragma once
#include<iostream>
#include<string>
using namespace std;

class Song
{
    private:
        string title;
        int duration; //secunde

    public:
        //constructor
        Song(const string& title = "Unknown", int duration = 0);
        //destructor
        ~Song();
        //copy constructor
        Song(const Song& other);
        //move constructor
        Song(Song&& other) noexcept;
        //copy assignment
        Song& operator=(const Song& other);
        //move assignment
        Song& operator=(Song&& other) noexcept;
        string getTitle() const;
        int getDuration() const;
        void print() const;
};