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
    

    int removeSong(Song const &s);


    void shuffle();


    void showSongList();

    
	void sortSongList();


    void clearMemory();


    /* FUNCTION - int removeSong
    * attempts to remove a song from the UtPod
    * removes the first instance of a song that is in the the UtPod multiple times
        o returns 0 if successful
        o returns -1 if nothing is removed
    input parms -
    output parms -
*/
    int UtPod::removeSong(Song const &song) {
        bool nodeFound = false;
        SongNode *temp = songs;
        SongNode *prev = temp;
        while(nodeFound == false && temp != NULL){
            if((Song) song == temp->s)
            {
                nodeFound = true;
                prev->next = temp->next;
                delete(temp);
                return(0);
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return(-1);
    }

    /* FUNCTION - void clearMemory
    * clears all the songs from memory
        input parms -
        output parms -
    */
    void UtPod::clearMemory(){
        SongNode *temp = songs;
        while(temp != NULL){
            songs = temp->next;
            delete(temp);
            temp = songs;
        }
    }

    /* FUNCTION - void sortSongList
    *  sorts the songs in ascending order
     o will do nothing if there are less than two songs in the current list
    input parms -
    output parms -
    */

    void UtPod::sortSongList(){
      bool swap = true;
        while(swap == true) {
            SongNode *temp = songs;
            SongNode *prev = songs;
            SongNode *nxt = songs->next;
            swap = false;
            while (nxt != NULL) {
                if (temp->s < nxt->s) {
                    prev = temp;
                    temp = nxt;
                    nxt = nxt->next;
                } else {
                    //head case
                    if (temp == songs) {
                        songs = nxt;
                    }
                    prev->next = nxt;
                    temp->next = nxt->next;
                    nxt->next = temp;
                    prev = nxt;
                    nxt = temp->next;
                    swap = true;

                }
            }
        }
    }


    UtPod::~UtPod() {
    }

