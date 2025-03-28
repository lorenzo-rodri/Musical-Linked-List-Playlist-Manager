#include "givenA3.h"

// dont need to run file with cmd line args, just hardcode src/ldskf.csv
int main(){

	int choice;
	int numSongs;
	char fileName[MAX_LENGTH] = "src/MusicalTunes.csv";
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
				printf("You ran choice 2\n");
				break;
			case 3:
				playPlayList(newPlaylist);
				break;
			case 4:
				printf("You ran choice 4\n");
				break;
			case 5:
				printf("You ran choice 5\n");
				break;
			case 6:
				printf("You ran choice 6\n");
				break;
			case 7:
				printf("You ran choice 7\n");
				break;
			case 8:
				printf("You ran choice 8\n");
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

	