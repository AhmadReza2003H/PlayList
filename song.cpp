#include <iostream>
#include "song.h"
#include <cstring>

using namespace std;

void IgnoreNewLines( )
{
  while(cin.peek( ) == '\n')
    cin.ignore( );
}

Song::Song( )
{
  strcpy(title, "");
  strcpy(artist, "");
}

Song::Song(const char* t, const char* a)
{
  Set(t, a);
}
    
void Song::Set(const char* t, const char* a)
{
  if(strlen(t) < MAX_CHARS)
    strcpy(title, t);

  if(strlen(a) < MAX_CHARS)
    strcpy(artist, a);
}

ostream& operator<<(ostream& os, const Song& song)
{
  os << song.title << " , " << song.artist;

  return os;
}

istream& operator>>(istream& is, Song& song)
{
  IgnoreNewLines( );

  cin.getline(song.title, Song::MAX_CHARS, ',');

  if(cin.peek( ) == ' ')
    cin.ignore( );

  IgnoreNewLines( );

  cin.getline(song.artist, Song::MAX_CHARS);

  return is;
}

bool operator==(const Song& lhs, const Song& rhs)
{
  if(strcmp(lhs.title, rhs.title))
    return false;

  if(strcmp(lhs.artist, rhs.artist))
    return false;

  return true;
}

