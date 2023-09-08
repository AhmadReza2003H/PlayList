#ifndef SONG_H
#define SONG_H

#include <iostream>

using namespace std;

class Song
{
  friend ostream& operator<<(ostream& os, const Song& song);
  friend istream& operator>>(istream& is, Song& song);
  friend bool operator==(const Song& lhs, const Song& rhs);

public:
    Song();
    Song(const char* t, const char* a);
    void Set(const char* t, const char* a);

private:
    static const int MAX_CHARS = 64;
    char title[MAX_CHARS];
    char artist[MAX_CHARS];
};

#endif