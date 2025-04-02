#include "givenA3.h"

int countNotesInASong(A3Song * headLL, int givenSongId, char whichNote[4]){

	int matchingNotes = 0;
	int match = 0; // used to see if the note is valid
	char notes[7][NOTE_LENGTH] = {"do", "re", "mi", "fa", "sol", "la", "ti"};

	A3Song * ptr = headLL;

	//Remove newline
	whichNote[strcspn(whichNote,"\n")] = '\0';

	// Chack if whichNote is a valid note
	for(int i=0; i<7; i++){
		if (strcmp(whichNote, notes[i])==0){
			match++;
			break;
		}
	}
	if (match == 0){
		printf("\nInvalid note!");
		return -1; // Return -1 if no matching note is found
	}

	

	// Search for ID
	while(ptr != NULL){
		if (ptr->songId == givenSongId){
			for (int i=0; i<21; i++){
				if (strcmp(ptr->songNotes[i], whichNote) == 0){
					matchingNotes++;
				}
			}
			return matchingNotes;
		}
		ptr = ptr->nextSong;
	}
	printf("Song not found!");
	return -1; // song not found

}