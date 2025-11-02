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
        Song(const string& title = "Unknown", int duration = 0);
        ~Song();
        string getTitle() const;
        int getDuration() const;
        void print() const;
};