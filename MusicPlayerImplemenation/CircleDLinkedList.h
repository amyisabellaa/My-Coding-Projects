#include "CircleDLinkedList.h"
#include <iostream>
using namespace std;

// constructor
CircleDLinkedList::CircleDLinkedList() {
    cursor = nullptr; // empty list
    n = 0;
}

// destructor
CircleDLinkedList::~CircleDLinkedList() {
    while (!empty()) {
        remove();
    }
}

// check if list is empty
bool CircleDLinkedList::empty() const {
    return cursor == nullptr;
}

// return current size
int CircleDLinkedList::size() const {
    return n;
}

// add a song after current song
// then move cursor to the new node
void CircleDLinkedList::add(const Song& s) {
    DNode* newNode = new DNode(s);

    // if list is empty, new node points to itself both ways
    if (empty()) {
        newNode->next = newNode;
        newNode->prev = newNode;
        cursor = newNode;
    }
    else {
        // insert after cursor
        newNode->next = cursor->next;
        newNode->prev = cursor;

        cursor->next->prev = newNode;
        cursor->next = newNode;

        // now new song becomes current
        cursor = newNode;
    }

    n++;
}

// remove current song
void CircleDLinkedList::remove() {
    if (empty()) {
        return;
    }

    DNode* old = cursor;

    // if there is only one node
    if (n == 1) {
        cursor = nullptr;
    }
    else {
        old->prev->next = old->next;
        old->next->prev = old->prev;

        // move cursor to next song
        cursor = old->next;
    }

    delete old;
    n--;
}

// move forward
void CircleDLinkedList::advance() {
    if (!empty()) {
        cursor = cursor->next;
    }
}

// move backward
void CircleDLinkedList::retreat() {
    if (!empty()) {
        cursor = cursor->prev;
    }
}

// return current song
Song CircleDLinkedList::getCurrentSong() const {
    if (empty()) {
        return Song();
    }

    return cursor->elem;
}

// print all songs starting from current position
void CircleDLinkedList::print(bool forward) const {
    if (empty()) {
        cout << "Playlist is empty." << endl;
        return;
    }

    DNode* temp = cursor;

    // print current first
    cout << temp->elem << endl;

    if (forward) {
        temp = temp->next;
        while (temp != cursor) {
            cout << temp->elem << endl;
            temp = temp->next;
        }
    }
    else {
        temp = temp->prev;
        while (temp != cursor) {
            cout << temp->elem << endl;
            temp = temp->prev;
        }
    }
}
