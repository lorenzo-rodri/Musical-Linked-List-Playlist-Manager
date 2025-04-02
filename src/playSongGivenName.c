#include "givenA3.h"
/* 
Play a song, given its name givenSongName;
each note in the song must be separated by a dot (.)
for example, Do.Re.Mi. and so on

Return -1 if song not found; 1 if found
 */
int playSongGivenName(A3Song * headLL, char givenSongName[MAX_LENGTH]){
	
	A3Song * ptr = headLL;

	// Remove newline
	givenSongName[strcspn(givenSongName,"\n")] = '\0';

	// Traverse linked list and print only if matching name is found
	while(ptr != NULL){
		if (strcmp(givenSongName, ptr->songName) == 0){
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