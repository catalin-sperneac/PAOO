#include "Playlist.hpp"
#include "Song.hpp"
#include<iostream>
using namespace std;

Playlist createPlaylist(const string& name) 
{
    Playlist rock(name);
    rock.addSong(Song("Linkin Park - In the End",216));
    rock.addSong(Song("The White Stripes - Seven Nation Army",232));
    rock.addSong(Song("Foo Fighters - Best of you",256));
    return rock;
}

int main()
{
    cout<<"Cream un playlist normal"<<endl;
    Playlist rock1("Rock Classics 90s");
    rock1.addSong(Song("Nirvana - Smells Like Teen Spirit",301));
    rock1.addSong(Song("Oasis - Wonderwall",258));
    rock1.addSong(Song("Nirvana - Come as you are",219));
    rock1.print();
    cout<<"================================================================="<<endl<<endl;

    cout<<"Cream un playlist temporar folosind functia createPlaylist() si se apeleaza move constructor cand il atribuim"<<endl;
    Playlist rock2 = createPlaylist("Rock Classics 2000s");
    rock2.print();
    cout<<"================================================================="<<endl<<endl;

    cout<<"Testam self-assignment la operator="<<endl;
    rock1 = rock1;
    rock1.print();
    cout<<"================================================================="<<endl<<endl;

    cout<<"Testam copy assignment"<<endl;
    rock1 = rock2;
    cout<<"Playlist rock1 actualizat"<<endl;
    rock1.print();
    cout<<"================================================================="<<endl<<endl;

    cout<<"Testam move assignment"<<endl;
    rock1 = createPlaylist("Rock Classics 2000s 2");
    cout<<"Playlist rock1 dupa move assignment"<<endl;
    rock1.print();
    cout<<"================================================================="<<endl<<endl;

    cout<<"Cream o copie a unui playlist"<<endl;
    Playlist copy(rock1);
    copy.print();

    return 0;
}