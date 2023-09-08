#include "playlist.h"
#include <iostream>
using namespace std;

PlayList::PlayList(){}

PlayList::PlayList(const PlayList &playlist){
    this->numberOfSongs = playlist.numberOfSongs;
    this->songIndex = playlist.songIndex;
    this->capacity = playlist.capacity;
    this->playlist = (Song *)calloc(this->capacity , sizeof(Song));
    for(int i = 0 ; i < this->numberOfSongs ; i++){
        this->playlist[i] = playlist.playlist[i];
    }
}

PlayList::~PlayList(){
    free(this->playlist);
}

void PlayList::play(){
    if(this->numberOfSongs == 0){
        throw "empty playlist";
    }
    cout << this->playlist[this->songIndex] << '\n';

    this->songIndex == this->songIndex + 1 % this->numberOfSongs;

}

void PlayList::play(int num){
    if(num > 0 || num <= numberOfSongs){
        this->songIndex = num-1;
        this->play();
    } else{
        throw "index out of bounds";
    }
}

void PlayList::showStatus()const{
    printf("Playlist status: %d slots, %d song(s), currently at song No. %d\n",this->capacity,this->numberOfSongs,this->songIndex);
}

void PlayList::showAll()const{
    for(int i = 0 ; i < numberOfSongs ; i++){
        cout << "No " << i  << ":" << playlist[i] << endl; 
    }
}

void PlayList::addSong(const Song &s){
    this->playlist[this->numberOfSongs] = s;
    this->numberOfSongs++;
    if(this->numberOfSongs == this->capacity){
        this->doubleSize();
    }
}

bool PlayList::deleteSong(const Song &s){
    for(int i = 0 ; i < numberOfSongs ; i++){
        if(this->playlist[i] == s){
            for(int j = i ; j < numberOfSongs - 1; j++){
                this->playlist[j] = this->playlist[j-1];
            }
            this->numberOfSongs--;
            if(this->numberOfSongs < this->capacity/2){
                this->halfSize();
            }
            return true;
        }
    }
    return false;
}

PlayList PlayList::operator+(const Song &s){
    PlayList playlist = *this;
    playlist.addSong(s);
    return playlist;
}

PlayList PlayList::operator-(const Song &s){
    PlayList playlist = *this;
    playlist.deleteSong(s);
    return playlist;
}

PlayList PlayList::operator=(const PlayList & playlist){
    this->numberOfSongs = playlist.numberOfSongs;
    this->songIndex = playlist.songIndex;
    this->capacity = playlist.capacity;
    this->playlist = (Song *)realloc(this->playlist , sizeof(Song)*this->capacity);
    for(int i = 0 ; i < this->numberOfSongs ; i++){
        this->playlist[i] = playlist.playlist[i];
    }    return *this;
}

void PlayList::doubleSize(){
    this->capacity *= 2;
    this->playlist = (Song*)realloc(playlist , sizeof(Song)*this->capacity);
}

void PlayList::halfSize(){
    if(this->capacity != 2){
        this->capacity /=2;
        this->playlist = (Song*)realloc(playlist ,sizeof(Song)*this->capacity);
    }
}