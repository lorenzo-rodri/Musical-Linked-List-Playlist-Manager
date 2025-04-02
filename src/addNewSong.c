#include "givenA3.h"
/*
add a new song to the start of the given linked list if beginOrEnd is 1; add it to the end of the given LL if beginOrEnd is 2
 return True for success and False if it fails for any reason
 */
bool addNewSong(A3Song **headLL, int beginOrEnd){
	
	char notes[7][NOTE_LENGTH] = {"do", "re", "mi", "fa", "sol", "la", "ti"};

	srand(time(NULL));			// Set time for random thing

	// Allocate memory for new song
	A3Song *newSong = malloc(sizeof(A3Song));
	if (newSong == NULL){
		return false;
	}
	
	// Get song name
	printf("Enter the name of the song: ");
	getchar();
	if (fgets(newSong->songName, sizeof(newSong->songName), stdin) != NULL) {
        // Remove newline
		newSong->songName[strcspn(newSong->songName,"\n")] = '\0';
    } 

	// Get random ID.
	newSong->songId = rand() % (1000 + 1);
	newSong->songId += strlen(newSong->songName);

	// Generate random notes
	for (int i=0; i<21; i++){
		strcpy(newSong->songNotes[i], notes[rand() % (6 + 1)]); // Random index between 0 and 6
	}

	// Insert song at begining or end
	newSong->nextSong = NULL; 				// Set next node

	if (beginOrEnd == 1){	// Insert beginning
		newSong->nextSong = *headLL;
		*headLL = newSong;
		printf("\nSong added at the beginning!");
	}
	else if (beginOrEnd == 2){					// Insert end
		A3Song *temp = *headLL;
			while (temp->nextSong != NULL){
				temp = temp->nextSong;
			}
			temp->nextSong = newSong;
			printf("\nSong added at the end!");
	}
	else{
		printf("\nInvalid beginOrEnd value!");
		return false;
	}

	// Print all data
	printf("\nSong ID: %d", newSong->songId);
	printf("\nSong Name: %s", newSong->songName);
	printf("\nNotes: ");
	for (int i=0; i<21; i++){
		printf("%s ", newSong->songNotes[i]);
	}
	
	return true;
}