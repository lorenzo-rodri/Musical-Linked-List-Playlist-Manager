#include "givenA3.h"

int deleteASongGivenId(A3Song **headLL, int givenSongId){

	A3Song * ptr = *headLL;
	A3Song * previous = NULL; // used to keep track of previous node when traversing

	if (ptr->songId == givenSongId){
		*headLL = ptr->nextSong;
		free(ptr);
		printf("\nSong deleted!");
		return 1;
	}

	while(ptr != NULL){
		if (ptr->songId == givenSongId){
			previous->nextSong = ptr->nextSong;
			free(ptr);
			printf("\nSong deleted!");
			return 1;
		}
		previous = ptr;
		ptr = ptr->nextSong;
	}

	printf("\nSong not found!");
	return -1;
}