// Project4Retry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;

// Aaron Ireland
// October 12, 2018
// Project 4 - Playlist Manager

//------Structures------//
struct Song { // Song structure, contains a name, artist, an album, and a pointer to the next song

	string name;
	string artist;
	string album;
	Song* next;
};

struct Playlist { // Playlist structure, contains a name, a Song pointer, and a pointer to the next playlist

	string name;
	Song* first;
	Song* last;
	Playlist* next;
};
//----------------------//

//----------Empty Functions---------//
bool emptyPlaylist(Playlist *head) { // bool function, checks if no playlists are available

	if (head == NULL) { // no playlists created
		return true;
	}
	else { // at least one playlist has been created
		return false;
	}
}

bool emptySongs(Song *first) { // bool function, checks if no songs are available

	if (first == NULL) { // no songs created
		return true;
	}
	else { // at least one song has been created
		return false;
	}
}
//---------------------------------//

//--------Display Functions--------//
void displaySongs(Playlist *&head, Song* current) { // function for displaying the songs in the playlist menu

	cout << head->name << " Playlist Menu\n\n";
	if (emptySongs(current)) { // checks if the list of songs is empty
		cout << "No songs available";
	}
	else { // at least one song is in a playlist
		cout << "Songs:\n\n";

		while (current != NULL) { // prints out the name of each song
			cout << current->name << endl;
			current = current->next;
		}
	}
}

void displayPlaylist(Playlist* current) { // function for displaying the playlists in the main menu

	cout << "Main Menu\n\n";
	if (emptyPlaylist(current)) { // checks if the list of playlists is empty
		cout << "No playlists available";
	}
	else { // at least one playlist has been created
		cout << "Playlists:\n\n";

		while (current != NULL) { // prints out the name of each playlist
			cout << current->name << endl;
			current = current->next;
		}
	}
}
//--------------------------------//

//-------Menu Functions----//
int menu() { // simple function: displays the main menu and returns the user's input

	int choice;
	cout << "\n\n1. View Playlist Details\n";
	cout << "2. Create New Playlist\n";
	cout << "3. Exit\n\n";
	cout << "Please enter the number of an option listed here: ";
	cin >> choice;
	return choice; // retruns the number input by the user, checked in later function
}

int detailMenu() { // simple function: displays a specific playlist's menu and retruns the user's input
	
	int option;
	cout << "\n\n1. Add a Song\n";
	cout << "2. Move a Song\n";
	cout << "3. Delete Playlist\n";
	cout << "4. Exit to Main Menu\n\n";
	cout << "Please enter the number of an option listed here: ";
	cin >> option;
	return option; // retruns the number input by the user, checked in later function
}

int songMenu(Song *&sCheck) { // simple function: displays a menu when user selects to move a song

	int songOption;

	cout << sCheck->name << " song menu"; // display of what song was selected
	cout << "\n\n1. Move Song Up\n";
	cout << "2. Move Song Down\n";
	cout << "3. Remove Song\n";
	cout << "4. Return to Playlist Menu\n\n";
	cout << "Please enter the number of an option listed here: ";
	cin >> songOption;
	return songOption; // returns the number input by the user, checked in later function
}
//-------------------------//

//-------------Playlist/Song Altering Functions------------------------------------------//
void createSong(Playlist *&check) { // function for adding a new song to a selected playlist

	string sName; // string variables used as input for each field
	string sArtist;
	string sAlbum;

	system("CLS"); // prompts below ask the user to enter song information
	cout << "\n\nPlease enter the name of the song. Enter '_' for spaces: ";
	cin >> sName;

	cout << "\n\nPlease enter the artist of the song. Enter '_' for spaces: ";
	cin >> sArtist;

	cout << "\n\nPlease enter the album that this song is from. Enter '_' for spaces: ";
	cin >> sAlbum;

	if (emptySongs(check->first)) { // checks if the list of songs is empty

		Song *temp = new Song; // temporary song pointer, all user input values will be added to temp

		temp->name = sName;
		temp->artist = sArtist;
		temp->album = sAlbum;
		temp->next = NULL;
		check->first = temp; // the selected playlist's first song is set to temp
		check->last = temp;

	}
	else { // checks if the list of songs includes at least one song

		Song *temp = new Song; // temporary song pointer, all user input values will be added to temp

		temp->name = sName;
		temp->artist = sArtist;
		temp->album = sAlbum;
		temp->next = NULL;
		check->last->next = temp; // sets the last song in the playlist's song list to point to the new song
		check->last = check->last->next;
	}
}

void moveSong(Song *&first, Song *&last) { // function used for repostioning songs within a playlist

	Song* sCheck = first; // Song pointers used for checking the song name compared to user input
	Song* sCheck_prev = NULL;
	string selectedSong;

	cout << "\nPlease enter the name of the song you would like to move. Enter '_' for spaces: ";
	cin >> selectedSong;
	system("CLS");

	while (sCheck != NULL) { // while loop, breaks if the song name does not exist in the playlist

		if (selectedSong == sCheck->name) { // condition statement, checks if the user's input matches the name of a song list item
		
			int option;

			do { // do-while loop, cycles through the song movement menu based on the user's input option
			
			option = songMenu(sCheck);

			if (option == 1) { // condition for moving a song up in the list
			
				if (sCheck_prev == NULL) { // check if song is at the top of the list

					system("CLS");
					cout << sCheck->name << " is already at the top of this playlist.\n\n";
				}
				else { // else case song is 2nd song or lower

					swap(sCheck->name, sCheck_prev->name); // swaps the names of the current song with the previous song in the list
					swap(sCheck->artist, sCheck_prev->artist);
					swap(sCheck->album, sCheck_prev->album);
					system("CLS");
					break;
				}
			}
			else if (option == 2) { // condition for moving a song lower in the list
			
				if (sCheck->next == NULL) { // check if song is at the bottom of the list

					system("CLS");
					cout << sCheck->name << " is already at the bottom of this playlist.\n\n";
				}
				else { // else case song is anywhere above the bottom

					swap(sCheck->name, sCheck->next->name); // swaps the names of the current song with the next song in the list
					swap(sCheck->artist, sCheck->next->artist);
					swap(sCheck->album, sCheck->next->album);
					system("CLS");
					break;
				}
			}
			else if (option == 3) { // user enters 3, removes the selected song from playlist (no warning, since remove and delete can be different)
			
				if (sCheck->next == NULL && sCheck_prev == NULL) { // condition if the selected song to remove is the only song

					delete sCheck;
					first = NULL;
					last = NULL;
					system("CLS");
					return; // returns to the playlist menu after deletion
				}
				else if (sCheck_prev == NULL) { // condition if the selected song is the first song in the lsit
					Song* temp = first;
					first = first->next;
					delete temp;
					system("CLS");
					return; // returns to the playlist menu
				}
				else if (sCheck->next == NULL) { // condition if the selected song is the last song in the list

					sCheck_prev->next = NULL;
					delete sCheck;
					system("CLS");
					return; // returns to the playlist menu
				}
				else { // else statement for any songs in the middle of the list of songs

					sCheck_prev->next = sCheck->next;
					delete sCheck;
					system("CLS");
					return; // returns to playlist menu
				}
			}
			else if (option == 4) { // user enters 4, returns to the playlist menu
			
				system("CLS");
				return;
			}

			} while (option != 4); // while condition, loop ends if user enters 4

			break;
		}

		if (selectedSong != sCheck->name) { // condition statement, changes the value of sCheck and sCheck_prev if names do not match with user input

			sCheck_prev = sCheck;
			sCheck = sCheck->next;
		}
	}

	if (sCheck == NULL) { // condition statement, outputs message if the user enters a song name that does not exist

		cout << "This song does not exist, or is not located in this playlist. Double check the casing of your desired song.";
		return;
	}


}

void createPlaylist(Playlist *&head, Playlist *&tail) { // function for creating a new playlist

	string playlistName; // string used as user input

	system("CLS");
	cout << "Please enter a name for your new playlist. Enter '_' for spaces: ";
	cin >> playlistName;

	Playlist* temp = new Playlist; // creates new playlist, sets name to user's input and next value to NULL
	temp->name = playlistName;
	temp->next = NULL;
	temp->first = NULL;
	temp->last = NULL;

	if (emptyPlaylist(head)) { // checks if list of playlists is empty, sets new playlist as the only playlist

		head = temp;
		tail = temp;
	}
	else { // the playlist list contains at least one other playlist, sets new playlist as the next playlist

		tail->next = temp;
		tail = temp;
	}
	system("CLS");
}

int deletePlaylist(Playlist *&head, Playlist *&tail, Playlist *&check, Playlist *&check_prev) { // function for deleting a playlist

	char confirm; // char variable used for confirmation

	cout << "\n\nAre you sure you wish to delete this playlist? Enter 'y' to confirm, or 'n' to refuse: ";
	cin >> confirm;

	if (confirm == 'y' || confirm == 'Y') { // checks if the user entered a capital or lowercase y
		
		if (head->next == NULL && tail->next == NULL) { // checks if the playlist is the only one available

			delete check;
			head = NULL;
			tail = NULL;
			return 0; // returns to the main menu, updated list of playlists
		}
		else if (check_prev == NULL) { // checks if the playlist is the first playlist in the list

			Playlist* temp = head;
			head = head->next;
			delete temp;
			return 0; // returns to the main menu, updated list of playlists
		}
		else if (check->next == NULL) { // checks if the playlist is the last playlist in the list

			check_prev->next = NULL;
			delete check;
			return 0; // returns to the main menu, updated list of playlists

		}
		else { // else case, used for deleting a playlist that is in the middle of the list of playlists

			check_prev->next = check->next;
			delete check;
			return 0; // returns to the main menu, updated list of playlists
		}
	}
	else if (confirm == 'n' || confirm == 'N') { // checks if user input a capital os lowercase n
		system("CLS");
		cout << "Your playlist will remain unchanged.\n\n";
		return 1; // returns to the playlist menu
	}
	else if (confirm != 'y' || confirm != 'Y' || confirm != 'n' || confirm != 'N' || cin.fail()) { // checks if the user input is invalid, leaves the paylist alone
		cin.clear();
		cin.ignore(999, '\n');
		system("CLS");
		cout << "Your confirmation was invalid. Your playlist will remain unchanged.\n\n";
		return 1; // returns to the playlist menu
	}
}

void playlistDetail(Playlist *&head, Playlist *&tail) { // function for displaying and operating with a selected playlist

	Playlist* check = head; // creates a pointer called check, sets it equal to the first list node
	Playlist* check_prev = NULL; // pointer used as a previous value to check
	string selectedPlaylist;

	cout << "\nPlease enter the name of the playlist you would like to view. Enter '_' for spaces: ";
	cin >> selectedPlaylist;
	system("CLS");

	while (check != NULL) { // loop condition checks if the user input the name of an existing playlist

		if (selectedPlaylist == check->name) { // condition statement for when the user input matches the name of check

			int option;

			do { // do-while loop, used to loop through the menu options for the selected playlist
				displaySongs(check, check->first);
				option = detailMenu();

				if (option == 1) { // user enters 1, enters the createSong function
					createSong(check);
					system("CLS");
				}
				else if (option == 2) { // user enters 2, enters the moveSong function
					moveSong(check->first, check->last);

				}
				else if (option == 3) { // user enters 3, enters the delete playlist function. Exits loop entirely if delPlaylist returns 0

					int delPlaylist = deletePlaylist(head, tail, check, check_prev);

					if (delPlaylist == 0) { // checks the return value of delPlaylist
						system("CLS");
						return;
					}
				}
				else if (option == 4) { // user enters 4, returns to the main menu
					system("CLS");
					return;
				}
				else if (option < 1 || option > 4 || cin.fail()) { // user inputs an invalid number or letter(s)
					cin.clear();
					cin.ignore(999, '\n');
					system("CLS");
					cout << "Please input a valid menu option\n\n";
				}

			} while (option != 4); // loop ends if user enters 4

			break;
		}
		if (selectedPlaylist != check->name) { // condition that changes the check and check_prev value if the first instance does not match

			check_prev = check;
			check = check->next;
		}
	}

	if (check == NULL) { // condition statement that executes if a playlist name is entered, but does not exist
		cout << "This playlist does not exist. Double check the casing of your desired playlist.\n\n";
		return;
	}
}

void clearPlaylists(Playlist *&head, Playlist *&tail) { // function for clearing playlists when the program ends

	Playlist* current = head; // playlist pointer, points to the head

	while (current != NULL) { // while loop, cycles through all playlists and deletes them one by one

		Playlist* prev = NULL;
		prev = current;
		current = current->next;
		delete prev;
	}
	head = NULL;
	tail = NULL;
}
//--------------------------------------------------------//

int main() // main function, sets playlist pointers to NULL and cycles through the main menu
{
	Playlist* head = NULL; // head and tail are set to NULL, program starts with no playlists or songs
	Playlist* tail = NULL;

	int choice;

	cout << "Welcome to Magic Music Manager!\n\n";

	do { // do-while loop, used to loop through the main menu
		displayPlaylist(head);
		choice = menu();

		if (choice == 1) { // user inputs 1 for an option to view a playlist's details
			playlistDetail(head, tail);
		}
		else if (choice == 2) { // user inputs 2 for an option to create a new playlist
			createPlaylist(head, tail);
		}
		else if (choice == 3) { // user inputs 3, exits the program
			break;
		}
		else if (choice < 1 || choice > 3 || cin.fail()) { // user input is invalid, reprompts user to enter an option
			cin.clear();
			cin.ignore(999, '\n');
			system("CLS");
			cout << "Please input a valid menu option\n\n";
		}

	} while (choice != 3); // while condition, loop ends if user inputs 3

	system("CLS");
	clearPlaylists(head, tail);
	cout << "Thank you for managing your music with us!\n"; // program end message
    return 0;
}