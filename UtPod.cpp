#include "UtPod.h"
#include "Song.h"
#include <iostream>
#include <string>

using namespace std;
      
    UtPod::UtPod() {
     songs = NULL;
     memSize = MAX_MEMORY;
    }

    UtPod::UtPod(int size) {
     songs = NULL;
     if (size > MAX_MEMORY || size <= 0) {
        memSize = MAX_MEMORY;
     } else {
        memSize = size;
     }
    }

    /* FUNCTION - int addSong
    * attempts to add a new song to the UtPod
       o returns a 0 if successful
       o returns -1 if not enough memory to add the song

    precondition: s is a valid Song

    input parms - Song to add

    output parms - 0 if added sucessfully added, -1 if not enough memory
    */

    int UtPod::addSong(Song const &s) {
     if (s.getSize() < (*this).getRemainingMemory()) {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return 0;
     } else {
        return -1;
     }
    }

    /* FUNCTION - int getRemainingMemory
    *  returns the amount of memory available for adding new songs

     input parms -

     output parms -
    */

    int UtPod::getRemainingMemory() {
     int mem_used = 0;
     SongNode *temp = songs;
     while (temp != NULL) {
        mem_used += (temp->s).getSize();
        temp = temp->next;
     }
     int remaining_mem = MAX_MEMORY - mem_used;
     return remaining_mem;
    }

    void UtPod::showSongList(){
     SongNode *temp = songs;
     while(temp != NULL){
        cout << (temp->s.getTitle()) << ", " << (temp->s.getArtist()) << ", " << (temp->s.getSize()) << endl;
        temp = temp->next;
     }
    }

    UtPod::~UtPod() {
    }

