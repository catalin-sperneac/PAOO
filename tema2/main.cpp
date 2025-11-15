#include "Playlist.h"
#include "Song.h"
#include<iostream>
using namespace std;

Playlist createPlaylist() 
{
    Playlist rock("Rock Classics");
    rock.addSong(Song("In the End",216));
    rock.addSong(Song("Seven nation Army",232));
    rock.addSong(Song("Best of you",256));
    rock.addSong(Song("Smells Like Teen Spirit",301));
    rock.addSong(Song("Wonderwall",258));
    rock.addSong(Song("Come as you are",219));
    return rock; //testam move constructor
}

int main()
{
    cout<<"Creez un playlist folosind move constructor"<<endl;
    Playlist playlist1 = createPlaylist();
    
    cout<<"Creez un playlist gol"<<endl;
    Playlist playlist2("Playlist Gol");

    cout<<"Testez copy assigment"<<endl;
    playlist2 = playlist1;

    cout<<"Testez move assignment"<<endl;
    playlist2 = createPlaylist();

    cout<<"Testez self-assignment"<<endl;
    playlist1 = playlist1;

    return 0;
}