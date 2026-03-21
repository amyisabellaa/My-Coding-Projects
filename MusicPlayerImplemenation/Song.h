#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
using namespace std;

class Song {

private:
    string songTitle;   // title of the song
    string singerName;  // singer of the song

public:
    Song(string sTitle = "", string sName = ""); // constructor
    ~Song(); // destructor

    string getSongTitle() const;
    string getSingerName() const;

    void setSongTitle(string);
    void setSingerName(string);

    friend ostream& operator<<(ostream& os, const Song& song);
};

#endif
