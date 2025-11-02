#include "Playlist.h"
#include "Song.h"
#include<iostream>
using namespace std;

Playlist createPlaylist() 
{
    Playlist rock00("Rock Classics 2000s",3);
    rock00.setSong(0,Song("In the End",216));
    rock00.setSong(1,Song("Seven nation Army",232));
    rock00.setSong(2,Song("Best of you",256));
    return rock00; //testam move constructor
}

int main()
{
    cout<<"Creez Playlist-ul principal"<<endl;
    Playlist rock90("Rock Classics 1990s",3);
    rock90.setSong(0,Song("Smells Like Teen Spirit",301));
    rock90.setSong(1,Song("Wonderwall",258));
    rock90.setSong(2,Song("Come as you are",219));
    rock90.print();
    
    cout<<"Creez o copie"<<endl;
    Playlist copy = rock90;//copy constructor
    copy.print();

    cout<<"Creez un playlist temporar"<<endl;
    Playlist rock00 = createPlaylist();
    rock00.print();

    return 0;
}