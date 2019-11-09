
#include <iostream>
#include "Playlist.h"

using namespace std;

void PrintMenu(string playlistTitle) {
    
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    
    return;
    
}



int main() {
    
    Playlist2 myList;
    string id;
    string sname;
    string aname;
    int length;
    int oldPos;
    int newPos;
    char choice;
    
    
    string playlistTitle;
    
    cout << "Enter playlist's title:" << endl << endl;
    getline(cin, playlistTitle);
    PrintMenu(playlistTitle);
    cout << "Choose an option:" << endl;
    
    cin>>choice;
    

    while(choice != 'q') {
        
        if (choice == 'a') {
            
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:";

            cin >> id;
            cin.ignore();
            
            cout << endl << "Enter song's name:";
            getline(cin, sname);
            cout << endl << "Enter artist's name:";
            getline(cin, aname);
            cout << endl << "Enter song's length (in seconds):" << endl << endl;
            
            cin >> length;
            
            myList.AddSong(id, sname, aname, length);
            
        }
        
        else if (choice == 'd') {
            
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:";
            
            cin >> id;
            cout << endl;
            
            myList.RemoveSong(id);
            
        }
        
        else if (choice == 'c') {
            
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:";
            cin >> oldPos;
            
            cout << endl << "Enter new position for song:";
            cin >> newPos;
            cout << endl;
            
            myList.ChangePosition(oldPos, newPos);
            
        }
        
        else if (choice == 's') {
            
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:";
            
            cin.ignore();
            getline(cin, aname);
            cout << endl << endl;
            
            myList.SongsByArtist(aname);
            
        }
        
        else if (choice == 't') {
            
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << myList.TotalTime() << " seconds" << endl << endl;
            
        }
        
        else if (choice == 'o') {
            
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            myList.PrintList();
            
        }
        
        else if(choice != 'q') {
            
            cout << "Invalid menu choice! Please try again." << endl;
            
        }
        
        
        PrintMenu(playlistTitle);
        cout << "Choose an option:" << endl;
        
        cin >> choice;
        
    }
    
    
    
    return 0;
    
}

