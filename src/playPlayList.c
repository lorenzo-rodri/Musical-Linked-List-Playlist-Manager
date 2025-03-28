#include "givenA3.h"

/*
Play all songs in the playlist,
each song separated by a newline;
each note in a song separated by a .
for example, Do.Re.Mi. and so on
 */
void playPlayList(A3Song *headLL){

	A3Song * ptr = headLL;

	while(ptr != NULL){
		printf("\nSong ID: %d\nSong Name: %s\nNotes: ", ptr->songId, ptr->songName);
		for (int i=0; i<21; i++){
			printf("%s", ptr->songNotes[i]);
			if (i<20){
				printf(".");
			}
		}
		ptr = ptr->nextSong;
	}
}