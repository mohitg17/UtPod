#include <iostream>
#include <string>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("P", "A", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
	Song s2("B", "B", 5);
	t.addSong(s2);
	Song s3("R", "A", 2);
	Song s4("A", "C", 2);
	Song s5("C", "D", 7);
	t.addSong(s5);
	t.addSong(s4);
   // t.addSong(s5);
	t.addSong(s3);
	t.clearMemory();
	t.addSong(s4);
    t.addSong(s2);
    t.addSong(s5);
    t.addSong(s3);
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
