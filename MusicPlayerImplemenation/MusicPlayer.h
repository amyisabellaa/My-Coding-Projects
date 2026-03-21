#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "CircleDLinkedList.h"
#include <string>
using namespace std;

class MusicPlayer {

private:
    string type;                 // type of music player
    CircleDLinkedList playlist;  // playlist

    // helper function for recursive print
    void printRecursive(const Song& startSong, bool forward, bool firstCall);

public:
    MusicPlayer(string);     // constructor
    virtual ~MusicPlayer();  // destructor

    void play();             // play current song
    void next();             // move next and play
    void previous();         // move previous and play

    void addSong(const Song&); // add song before current
    void removeSong();         // remove current song

    int size() const;          // return size
    bool empty() const;        // check if empty
    Song getCurrentSong() const; // return current song

    void print(bool);          // print playlist recursively
};

#endif
