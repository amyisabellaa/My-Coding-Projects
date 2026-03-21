//main.cpp
#include <iostream>
#include "MusicPlayer.h"
#include "DNode.h"
using namespace std;

// initialize static variable
int DNode::activeNodes = 0;

int main() {
    // make a music player object
    MusicPlayer player("My Music Player");

    // add 3 songs
    player.addSong(Song("Blinding Lights", "The Weeknd"));
    player.addSong(Song("Levitating", "Dua Lipa"));
    player.addSong(Song("Die For You", "The Weeknd"));

    cout << "----- Initial Playback -----" << endl;
    player.play();

    player.next();
    player.next();
    player.next();

    player.previous();

    cout << endl;
    cout << "----- Playlist Review -----" << endl;
    player.print(true);
    cout << endl;
    player.print(false);

    cout << endl;
    cout << "----- Remove Current Song -----" << endl;
    player.removeSong();

    cout << endl;
    cout << "----- Playback After Removal -----" << endl;
    player.play();

    player.next();
    player.next();
    player.next();

    cout << endl;
    cout << "----- Final Playlist Review -----" << endl;
    player.print(true);
    cout << endl;
    player.print(false);

    cout << endl;
    cout << "Active nodes left: " << DNode::activeNodes << endl;

    return 0;
}
