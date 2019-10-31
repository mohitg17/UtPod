#include "UtPod.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
    
    //default constructor
    UtPod::UtPod() {
     songs = NULL;
     memSize = MAX_MEMORY;
     unsigned int currentTime =  (unsigned)time(0);
     srand(currentTime);  //seed the random number generator
    }
    //additional constructor
    UtPod::UtPod(int size) {
     songs = NULL;
     if (size > MAX_MEMORY || size <= 0) {
        memSize = MAX_MEMORY;
     } else {
        memSize = size;
     }
     unsigned int currentTime =  (unsigned)time(0);
     srand(currentTime);  //seed the random number generator
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
     if (s.getSize() <= (*this).getRemainingMemory()) {
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
     input parms  - None
     output parms - remaining memory
    */
    int UtPod::getRemainingMemory() {
     int mem_used = 0;
     SongNode *temp = songs;
     while (temp != NULL) {
        mem_used += (temp->s).getSize();
        temp = temp->next;
     }
     int remaining_mem = memSize - mem_used;
     return remaining_mem;
    }


    /* FUNCTION - void showSongList
    * prints the current list of songs in order from first to last to standard output
    * format - Title, Artist, size in MB (one song per line)
     input parms - None
     output parms - None
    */
    void UtPod::showSongList(){
     SongNode *temp = songs;
     while(temp != NULL){
        cout << (temp->s.getTitle()) << ", " << (temp->s.getArtist()) << ", " << (temp->s.getSize()) << endl;
        temp = temp->next;
     }
    }

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
		if(temp == songs){
		   nodeFound = true;
		   songs = temp->next;
		   delete(temp);
		   return(0);
		}
		else{
                   nodeFound = true;
                   prev->next = temp->next;
                   delete(temp);
                   return(0);
		}
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
    *  sorts the songs in ascending order(artist, title, size)
     o will do nothing if there are less than two songs in the current list
    input parms -
    output parms -
    */

    void UtPod::sortSongList(){
      bool swap = true;
        if(songs == NULL){

        }
        else {
            while (swap == true) {
                SongNode *temp = songs;
                SongNode *prev = songs;
                SongNode *nxt = songs->next;
                swap = false;

                while (nxt != NULL) {
                    if (temp->s < nxt->s) {
                        prev = temp;
                        temp = nxt;
                        nxt = nxt->next;
                    } else if (temp->s == nxt->s) {
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
    }

    /* FUNCTION shuffle
     shuffles the order of the songs list
    */  

    void UtPod::shuffle() {
        SongNode *temp = songs;
        int numSongs = 0;
        while(temp != NULL) {
            numSongs += 1;
            temp = temp->next;
        }
        for(int i = 0; i < (numSongs*3); i++) {
            int random = (rand() % numSongs) + 1;
            int random2 = (rand() % numSongs) + 1;
            SongNode *temp = songs;
            SongNode *temp2 = songs;
            int songNumber = 1;
            for(songNumber; songNumber < random; songNumber++) {
                temp = temp->next;
            }
            for(songNumber = 1; songNumber < random2; songNumber++) {
                temp2 = temp2->next;
            }
            SongNode *temp3 = new SongNode;
            temp3->s = temp->s;
            temp3->next = temp->next;

            temp->s = temp2->s;
            temp2->s = temp3->s;

            delete(temp3);
        }
    }


    UtPod::~UtPod() {
        this->clearMemory();
    }

