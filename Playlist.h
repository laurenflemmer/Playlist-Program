
#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <iostream>
#include <string>

using namespace std;

class PlaylistNode {
    
public:
    PlaylistNode();
    PlaylistNode(string id, string songname, string artist, int length);
    void InsertAfter(PlaylistNode* ptr);
    void SetNext(PlaylistNode* ptr);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode();
    
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
    
};


class Playlist2 {
    
private:
    
    PlaylistNode *head;
    PlaylistNode *tail;
    
    
    
public:
    
    Playlist2();
    void AddSong(string id, string songName, string artistName, int length);
    bool RemoveSong(string id);
    void PrintList();
    bool ChangePosition(int oldPos, int newPos);
    void SongsByArtist(string artist);
    int TotalTime();
    
};


#endif



