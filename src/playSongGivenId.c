#include "givenA3.h"

int playSongGivenId(A3Song *headLL, int givenSongId){

	A3Song * ptr = headLL;

	// Traverse linked list and print only if matching ID is found
	while(ptr != NULL){
		if (ptr->songId == givenSongId){
			printf("\nSong ID: %d\nSong Name: %s\nNotes: ", ptr->songId, ptr->songName);
			for (int i=0; i<21; i++){
				printf("%s", ptr->songNotes[i]);
				if (i<20){
					printf(".");
				}
			}
			printf("\n");
			return 1; // song found
		}
		ptr = ptr->nextSong;
	}
	printf("\nNo song found!");
	return -1; // song not found
}