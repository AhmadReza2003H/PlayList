#ifndef _PALYLISH_H
#define _PALYLISH_H
#include "song.h"
#include <iostream>

using namespace std;

class PlayList{
public:
    PlayList();
    PlayList(const PlayList &playlist);
    ~PlayList();
    void play();
    void play(int num);
    void showStatus()const;
    void showAll()const;
    void addSong(const Song &s);
    bool deleteSong(const Song &s);
    PlayList operator+(const Song &s);
    PlayList operator-(const Song &s);
    PlayList operator=(const PlayList &playlist);
private:
    Song * playlist = (Song*)calloc(2 , sizeof(Song));
    int songIndex = 0;
    int numberOfSongs = 0;
    int capacity = 2;
    void doubleSize();
    void halfSize();
};

#endif