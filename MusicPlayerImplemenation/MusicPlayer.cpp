#include "MusicPlayer.h"
#include <iostream>
using namespace std;

// constructor
MusicPlayer::MusicPlayer(string t) {
    type = t;
}

// destructor
MusicPlayer::~MusicPlayer() {
}

// play current song
void MusicPlayer::play() {
    if (empty()) {
        cout << "Playlist is empty." << endl;
    }
    else {
        cout << "Now playing -> " << playlist.getCurrentSong() << endl;
    }
}

// move to next song and play
void MusicPlayer::next() {
    if (empty()) {
        cout << "Playlist is empty." << endl;
        return;
    }

    playlist.advance();
    play();
}

// move to previous song and play
void MusicPlayer::previous() {
    if (empty()) {
        cout << "Playlist is empty." << endl;
        return;
    }

    playlist.retreat();
    play();
}

// add song before current song
void MusicPlayer::addSong(const Song& s) {
    if (playlist.empty()) {
        playlist.add(s);
    }
    else {
        playlist.retreat();
        playlist.add(s);
    }
}

// remove current song
void MusicPlayer::removeSong() {
    if (empty()) {
        cout << "Playlist is empty. Nothing to remove." << endl;
        return;
    }

    cout << "Removing -> " << playlist.getCurrentSong() << endl;
    playlist.remove();
}

// return size
int MusicPlayer::size() const {
    return playlist.size();
}

// check if empty
bool MusicPlayer::empty() const {
    return playlist.empty();
}

// return current song
Song MusicPlayer::getCurrentSong() const {
    return playlist.getCurrentSong();
}

// recursive helper
void MusicPlayer::printRecursive(const Song& startSong, bool forward, bool firstCall) {
    cout << playlist.getCurrentSong() << endl;

    if (forward) {
        playlist.advance();
    }
    else {
        playlist.retreat();
    }

    if (playlist.getCurrentSong().getSongTitle() == startSong.getSongTitle() &&
        playlist.getCurrentSong().getSingerName() == startSong.getSingerName() &&
        !firstCall) {
        return;
    }

    printRecursive(startSong, forward, false);
}

// recursive print
void MusicPlayer::print(bool forward) {
    if (empty()) {
        cout << "Playlist is empty." << endl;
        return;
    }

    cout << "Playlist (" << (forward ? "forward" : "reverse") << "):" << endl;

    Song startSong = playlist.getCurrentSong();
    printRecursive(startSong, forward, true);
}
