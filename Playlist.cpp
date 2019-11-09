
#include "Playlist.h"


PlaylistNode::PlaylistNode() {
    
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
    
}

PlaylistNode::PlaylistNode(string id, string songname, string artist, int length) {
    
    uniqueID = id;
    songName = songname;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
    
}



void PlaylistNode::InsertAfter(PlaylistNode* ptr) {
    
    ptr->SetNext(this->GetNext());
    this->SetNext(ptr);
    
}


void PlaylistNode::SetNext(PlaylistNode* ptr) {
    
    nextNodePtr = ptr;
    
}

string PlaylistNode::GetID() const {
    
    return uniqueID;
    
}


string PlaylistNode::GetSongName() const {
    
    return songName;
    
}


string PlaylistNode::GetArtistName() const {
    
    return artistName;
    
}


int PlaylistNode::GetSongLength() const {
    
    return songLength;
    
}


PlaylistNode* PlaylistNode::GetNext() const {
    
    return nextNodePtr;
    
}


void PlaylistNode::PrintPlaylistNode() {
    
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength;
    
}


Playlist2::Playlist2() {
    
    head = nullptr;
    tail = nullptr;
    
}

void Playlist2::AddSong(string id, string songname, string artistname, int length) {
    
    PlaylistNode* added = new PlaylistNode(id, songname, artistname, length);
    
    if (head == nullptr) {
        
        head = added;
        tail = added;
        
    }
    
    else {
        
        tail->InsertAfter(added);
        tail = added;
        
    }
}



bool Playlist2::RemoveSong(string id) {
    
    if (head == nullptr) {
        
        cout << "Playlist is empty" << endl << endl;
        return false;
        
    }
    
    PlaylistNode* curr = head;
    PlaylistNode* prev = nullptr;
    
    while (curr != nullptr) {
        
        if (curr->GetID() == id) {
            
            if (prev != nullptr){
                
                prev->SetNext(curr->GetNext());
            }
            
            else {
                
                head = curr->GetNext();
            }
            
            if (tail == curr) {
                
                tail = prev;
            }
            
            cout << "\"" << curr->GetSongName() << "\" removed." << endl << endl;
            
            delete curr;
            
            return true;
            
        }
        
        prev = curr;
        curr = curr->GetNext();
        
    }
    
    
    
    if (curr == nullptr) {
        
        cout << "\"" << curr->GetSongName() << "\" is not found" << endl;
        
        return false;
        
    }
    
    return false;
    
}



bool Playlist2::ChangePosition(int oldPos, int newPos) {
    
    int length = 0;
    
    if (head == NULL) {
        
        cout << "Playlist is empty" << endl << endl;
        
        return false;
        
    }
    
    
    
    if(newPos < 1) {
        
        newPos = 1;
    }
    
    
    PlaylistNode* prev = NULL;
    PlaylistNode* curr = head;
    
    
    while(curr != nullptr) {
        
        length++;
        curr = curr->GetNext();
        
    }
    
    curr = head;
    
    if(newPos > length) {
        
        newPos = length;
        
    }
    
    int pos;
    
    if (head == tail) {
        
        cout << "Only one song" << endl;
        
        return false;
        
    }
    
    
    for (pos = 1; curr != NULL && pos < oldPos; pos++) {
        
        prev = curr;
        curr = curr->GetNext();
        
    }
    
    if (curr != NULL) {
        
        string currentSong = curr->GetSongName();
        
        
        if (prev == NULL) {
            
            head = curr->GetNext();
            
        }
        
        else {
            
            prev->SetNext(curr->GetNext());
            
        }
        
        
        if (curr == tail) {
            
            tail = prev;
            
        }
        
        
        
        PlaylistNode* curr1 = curr;
        prev = NULL;
        curr = head;
        
        
        for (pos = 1; curr != NULL && pos < newPos; pos++) {
            
            prev = curr;
            curr = curr->GetNext();
            
        }
        
        
        if (prev == NULL) {
            
            curr1->SetNext(head);
            head = curr1;
            
        }
        
        else {
            
            prev->InsertAfter(curr1);
            
        }
        
        
        if (curr == NULL) {
            
            tail = curr1;
    
        }
        
        
        cout << "\"" << currentSong << "\" moved to position " << newPos << endl << endl;
        
        return true;
        
    }
    
    else {
        
        cout << "Song's current position is invalid" << endl << endl;
        
        return false;
        
    }
    
}


    void Playlist2::PrintList() {
    
    if (head == NULL) {
        
        cout << "Playlist is empty" << endl << endl;
        
    }
    
    else {
        
        PlaylistNode* curr = head;
        int i = 1;
        
        while (curr != nullptr) {
            
            cout << i++ << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl << endl;
            curr = curr->GetNext();
            
        }
    }
}



void Playlist2::SongsByArtist(string artist) {
    
    if (head == NULL) {
        
        cout << "Playlist is empty" << endl << endl;
        
    }
    
    else {
        
        PlaylistNode* curr = head;
        int i = 1;
        
        while (curr != NULL) {
            
            if (curr->GetArtistName() == artist) {
                
                cout << i << "." << endl;
                curr->PrintPlaylistNode();
                cout << endl << endl;
                
            }
            
            curr = curr->GetNext();
            
            i++;
            
        }
    }
}


int Playlist2::TotalTime() {
    
    int total = 0;
    PlaylistNode* curr = head;
    
    
    
    while (curr != NULL) {
        
        total += curr->GetSongLength();
        curr = curr->GetNext();
        
    }
    
    
    
    return total;
    
}
