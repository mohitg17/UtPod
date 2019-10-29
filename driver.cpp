#include <iostream>
#include <string>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("P", "Hey You", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
	Song s2("B", "BBBBBB", 5);
	t.addSong(s2);
	Song s3("R", "Beast of Burden", 2);
	Song s4("A", "AAAAAA", 2);
	Song s5("C", "Dancing Queen", 7);
	t.addSong(s5);
	t.addSong(s4);
   // t.addSong(s5);
	t.addSong(s3);
	t.addSong(s3);
    t.addSong(s5);
    t.addSong(s2);
    t.addSong(s4);
	t.showSongList();
	//t.removeSong(s4);
	//cout << "break" << endl;
	//t.showSongList();
    cout << "break" << endl;
	//t.clearMemory();
	//t.showSongList();
	t.sortSongList();
	t.showSongList();
	
}
