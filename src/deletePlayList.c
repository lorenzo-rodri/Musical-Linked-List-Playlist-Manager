#include "givenA3.h"
/*
 Remove every song from the playlist
 */
void deletePlayList(A3Song **headLL){
	
	A3Song * ptr = *headLL;
	A3Song * next;

    // Traverse, delete and free nodes
	while (ptr != NULL) {
        next = ptr->nextSong; 
        free(ptr);              
        ptr = next;            
    }

    // Clear head node
    *headLL = NULL; 
	printf("\nDeleting Playlist...");
}