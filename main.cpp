#include <iostream>
#include "playlist.h"
#include "song.h"
using namespace std;

void DoAdd(PlayList& playlist)
{
  Song s;
  cout << "Enter song\n: ";
  cin >> s;

  playlist.addSong(s);
}

void DoDelete(PlayList& playlist)
{
  Song del_song;
  cout << "Enter song to delete\n: ";
  cin >> del_song;

  if(playlist.deleteSong(del_song))
  {
    cout << "Song successfully deleted\n";
  }
  else
  {
    cout << "No such song exists\n";
  }
}

bool Menu(PlayList& playlist)
{
  bool good;

  do
  {
    good = true;

    cout << "\n\nPlayList Program!\n"
      << "\tA - Add a song\n"
      << "\tD - Delete a song\n"
      << "\tP - Play a song\n"
      << "\tS - Show all songs\n"
      << "\tT - Show playlist status\n"
      << "\tQ - Quit\n: ";

    char choice;
    cin >> choice;

    switch(toupper(choice))
    {
    case 'A':
      DoAdd(playlist);
      break;

    case 'D':
      DoDelete(playlist);
      break;

    case 'P':
      playlist.play();
      break;

    case 'S':
      playlist.showAll();
      break;
    case 'T':
      playlist.showStatus();
      break;
  case 'Q':
    return false;

    default:
      good = false;
    }
  } while(!good);

  return true;
}

int main( )
{
  PlayList playlist;

  while(Menu(playlist))
    ;

  return 0;
}