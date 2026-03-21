#include "Song.h"

// constructor
#include "Song.h"

// constructor
Song::Song(string sTitle, string sName) {
    songTitle = sTitle;
    singerName = sName;
}

// destructor
Song::~Song() {
}

// return title
string Song::getSongTitle() const {
    return songTitle;
}

// return singer
string Song::getSingerName() const {
    return singerName;
}

// set title
void Song::setSongTitle(string s) {
    songTitle = s;
}

// set singer
void Song::setSingerName(string s) {
    singerName = s;
}

// overload << so I can print a song easily
ostream& operator<<(ostream& os, const Song& song) {
    os << "Song: " << song.songTitle << " | Singer: " << song.singerName;
    return os;
}
