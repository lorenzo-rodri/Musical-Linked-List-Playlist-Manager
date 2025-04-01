#include "givenA3.h"
/*
create a play list using data given in the file named "musicalNotes.csv"
 */
int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]){

	int numSongs = 0;
	char buffer[150];
	char *data;

	srand(time(NULL)); 					// Set random number generator

	FILE * fPtr;  
    fPtr = fopen(fileName, "r");  		// Open file
									
    if (fPtr == NULL){   				// File validation
        printf("File no work :( ");
        return -1;
    }

	fgets(buffer, sizeof(buffer), fPtr); // Skips the header of CSV file

	while (fgets(buffer, sizeof(buffer), fPtr) != NULL){
		
		int id;
		A3Song *newSong = malloc(sizeof(A3Song)); // Allocate memory for the new node				
		
		// Remove newline
		buffer[strcspn(buffer,"\n")] = '\0';

		// Store song name
		data = strtok(buffer, ","); 			// Store first element (title) into data
		strcpy(newSong->songName, data);
		
		// Get each of the 21 notes and store into data
		for (int i = 0; i<21; i++){			    
			data = strtok(NULL, ",");			// This tells the program to get the next element in the line which will be the note in this case
			strcpy(newSong->songNotes[i], data);
		}

		// Assign a random id + length of song name
		id = rand() % (1000 + 1);
		id += strlen(newSong->songName);
		newSong->songId = id;

		newSong->nextSong = NULL; 				// Put node at end of list

		if (*headLL == NULL){ 					// If this is the first song, it will be put at the front of the list
			*headLL = newSong;
		}
		else{									// If not, traverse to end of list and append
			A3Song *temp = *headLL;
			while (temp->nextSong != NULL){
				temp = temp->nextSong;
			}
			temp->nextSong = newSong;
		}
		numSongs++;
	}
	fclose(fPtr);
	return numSongs;
}