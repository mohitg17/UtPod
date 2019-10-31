///* utPod_driver.cpp
//Demo Driver for the UtPod.
//
//Roger Priebe
//EE 312 10/16/18
//
//This is a basic driver for the UtPod.
//
//You will want to do more complete testing.
//
//*/
using namespace std;
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <string>
#include <sstream>

int main() {
    string line;
    UtPod t(1000);
    ifstream mysongs("test.txt");
    if(mysongs.is_open()) {
        while(getline(mysongs, line)) {
            if(line == "TM") {
                cout << "Total memory: " << t.getTotalMemory() << "\n" << endl;
            }
            if(line == "RM") {
                cout << "Remaining memory: " << t.getRemainingMemory() << "\n" << endl;
            }
            if(line == "C") {
                t.clearMemory();
                cout << "Memory has been cleared" << "\n" << endl;
            }
            if(line == "W") {
                cout << "Songs in UtPod" << endl;
                t.showSongList();
                cout << "\n";
            }
            if(line == "S") {
                t.sortSongList();
                cout << "Songs have been sorted" << "\n" << endl;
            }
            if(line == "F") {
                t.shuffle();
                cout << "Songs have been shuffled" << "\n" << endl;
            }
            if(line == "A") {
		string artist;
                string title;
                string size;
		int x = 0;
                getline(mysongs, artist, ',');
                getline(mysongs, title, ',');
                getline(mysongs, size, '\n');
		stringstream temp(size);
		temp >> x;
                Song s(artist, title, x);
                int result = t.addSong(s);
                if (result == 0) {
                    cout << title << " was added\n" << endl;
                } else {
                    cout << "Failed to add " << title << "\n" << endl;
                }
            }
            if(line == "R") {
                string artist;
                string title;
                string size;
		int x = 0;
                getline(mysongs, artist, ',');
                getline(mysongs, title, ',');
                getline(mysongs, size, '\n');
		stringstream temp1(size);
		temp1 >> x;
                Song s(artist, title, x);
                int result = t.removeSong(s);
                if (result == 0) {
                    cout << title << " was removed\n" << endl;
                } else {
                    cout << "Failed to remove " << title << "\n" << endl;
                }
            }

        }
    }
    else {
        cout << "file not open" << endl;
    }
    mysongs.close();
}
