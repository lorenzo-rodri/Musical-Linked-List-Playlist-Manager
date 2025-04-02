#include "givenA3.h"

// ADD ERROR CHECKING
// TEST WITH VALGRIND
// TEST WITH TEST HARNESS
// TEST ON SCHOOL SERVER
int main(){

	int choice, numSongs, beginOrEnd, givenSongId, matchingNotes;
	char fileName[MAX_LENGTH] = "src/MusicalTunes.csv";
	char givenSongName[MAX_LENGTH];
	char whichNote[NOTE_LENGTH];
	A3Song * newPlaylist = NULL;

	while(choice != 9){
		printf("\n======================================================\n");
		printf("1. Create a new playlist\n"
		"2. Add a new song to an existing playlist\n"
		"3. Play all songs in the given playlist\n"
		"4. Play a song from the playlist, given its id\n"
		"5. Play a song from the playlist, given its name\n"
		"6. Count the number of occurrences of a note in a given song\n"
		"7. Delete a song from the playlist, given its id\n"
		"8. Delete the entire playlist\n"
		"9. Exit\n");
		printf("======================================================\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice){
			case 1:
				numSongs = createPlayList(&newPlaylist, fileName);
				if (numSongs != -1){ 		//create new palylist, if print message for success/fail
					printf("\nPlaylist created successfully!");
				}
				else {
					printf("\nPlaylist creation unsuccessful!");
				}
				printf("\n%d songs added!", numSongs);
				break;
			case 2:
				printf("\nEnter your choice for beginOrEnd: ");
				scanf("%d", &beginOrEnd);
				if (addNewSong(&newPlaylist, beginOrEnd) == true){
					printf("\nYou added a song!");
				}
				else{
					printf("\nUnable to add to playlist!");
				}
				break;
			case 3:
				playPlayList(newPlaylist);
				break;
			case 4:
				printf("\nEnter the ID of the song you want to play: ");
				scanf("%d", &givenSongId);
				playSongGivenId(newPlaylist, givenSongId);
				break;
			case 5:
				printf("\nEnter the name of the song you want to play: ");
				getchar();
				fgets(givenSongName, sizeof(givenSongName), stdin); 
				playSongGivenName(newPlaylist, givenSongName);
				break;
			case 6:
				printf("\nEnter the ID of the song you want to play: ");
				scanf("%d", &givenSongId);
				getchar();
				printf("\nEnter the note that you want to count: ");
				fgets(whichNote, sizeof(whichNote), stdin); 
				matchingNotes = countNotesInASong(newPlaylist, givenSongId, whichNote);
				if (matchingNotes != -1){
					printf("\nThis note appears %d times in the song.", matchingNotes);
				}
				break;
			case 7:
				printf("\nEnter the ID of the song you want to play: ");
				scanf("%d", &givenSongId);
				deleteASongGivenId(&newPlaylist, givenSongId);
				break;
			case 8:
				deletePlayList(&newPlaylist);
				break;
			case 9:
				printf("Exiting the program...");
				break;
			default:
				printf("Incorrect input.\n");
				break;
	
		}
	}
	
	
	return 0;
}

	