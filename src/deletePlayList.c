#include "givenA3.h"

void deletePlayList(A3Song **headLL){
	
	A3Song * ptr = *headLL;
	A3Song * next;

	while (ptr != NULL) {
        next = ptr->nextSong; 
        free(ptr);              
        ptr = next;            
    }

    *headLL = NULL; 
	printf("\nDeleting Playlist...");
}