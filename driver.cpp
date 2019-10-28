#include <iostream>
#include <string>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
	Song s2("Beatles", "Hey Jude2", 5);
	t.addSong(s2);
	Song s3("Beatles", "Hey Jude3", 2);
	t.addSong(s3);
	t.showSongList();
	
}
