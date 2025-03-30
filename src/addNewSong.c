#include "givenA3.h"

bool addNewSong(A3Song **headLL, int beginOrEnd){
	
	char notes[7][NOTE_LENGTH] = {"do", "re", "mi", "fa", "sol", "la", "ti"};

	srand(time(NULL));			// Set time for random thing

	A3Song *newSong = malloc(sizeof(A3Song));
	if (newSong == NULL){
		return false;
	}
	
	// Get song name
	printf("Enter the name of the song: ");
	getchar();
	if (fgets(newSong->songName, sizeof(newSong->songName), stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(newSong->songName);
        if (len > 0 && newSong->songName[len - 1] == '\n') {
            newSong->songName[len - 1] = '\0';
        }
        printf("\nYou entered: %s", newSong->songName);
    } else {
        printf("\nError reading input.");
        return false;
    }

	// Get random ID.
	newSong->songId = rand() % (1000 + 1);
	newSong->songId += strlen(newSong->songName);
	printf("\nYour random ID is: %d", newSong->songId);

	// Generate random notes
	printf("\nYour notes are: ");
	for (int i=0; i<21; i++){
		strcpy(newSong->songNotes[i], notes[rand() % (6 + 1)]); // Random index between 0 and 6
		printf("%s ", newSong->songNotes[i]);
	}

	// Insert song at begining or end
	newSong->nextSong = NULL; 				// Set next node

	if (beginOrEnd == 1){	// Insert beginning
		newSong->nextSong = *headLL;
		*headLL = newSong;
	}
	else{					// Insert end
		A3Song *temp = *headLL;
			while (temp->nextSong != NULL){
				temp = temp->nextSong;
			}
			temp->nextSong = newSong;
	}	
	
	return true;
}