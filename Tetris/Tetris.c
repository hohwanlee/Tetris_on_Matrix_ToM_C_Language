#include<stdio.h>
#include <unistd.h>


// TODO: Separate with header files.

// Screen size. Putty has default of 24x80 characters can be shown.
// ! Top line 0th is glitched with user input, make it empty
// ! Last line 24th is actually reserved for user input, so total number of SCREEN_ROWS == 24 - 2 = 22
#define SCREEN_ROWS 22
#define SCREEN_COLUMNS 80

// We do have border like | - |, we need space between game and screen.
#define PADDING_ROWS 0
#define PADDING_COLUMNS 1

// Square made of GAME_ROWS x COLUMNS is where the tetris block can reside.
#define GAME_ROWS 21
#define GAME_COLUMNS 10


// TODO: Define all shapes of tetris, using struct.

// Define screen as 2D array, and game map as 2D array.
int screen[SCREEN_ROWS][SCREEN_COLUMNS] = { {0} };

int game[GAME_ROWS][GAME_COLUMNS] = { {0,1,0,0,0,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0},{0} };


// increase score when time pass or a line or more has cleared.
int score = 0;;

int nl() { // simply newline
	printf("\n");
}

// drawBorder like | / \ - 
int drawBorder(int i, int j) {
	int bPrinted = 0;

	if (j == 0) {
		if (i == 0) {
			printf("/");
			bPrinted = 1;
		}
		else if (i < GAME_ROWS) {
			printf("|");
			bPrinted = 1;
		}
		else if (i == GAME_ROWS) {
			printf("\\");
			bPrinted = 1;
		}
		else {
			printf("ERROR ELSE");
			bPrinted = 1;
		}
	}
	else if (j == GAME_COLUMNS + 1) {
		if (i == 0) {
			printf("\\");
			bPrinted = 1;
		}
		else if (i < GAME_ROWS) {
			printf("|");
			bPrinted = 1;
		}
		else if (i == GAME_ROWS) {
			printf("/");
			bPrinted = 1;
		}
		else {
			printf("ERROR ELSE");
		}
	}
	else {
		if (i == SCREEN_ROWS - 1 && j > 0 && j < GAME_COLUMNS + 1) {
			printf("-");
			bPrinted = 1;
		}
	}
	return bPrinted;
}


// Display with using printf. Check empty space and print " "
int display() {
	int i, j;

	int bPrinted;

	nl(); // leave top line empty
	for (i = 0; i < SCREEN_ROWS; i++) {
		for (j = 0; j < SCREEN_COLUMNS; j++) {
			bPrinted = 0;

			bPrinted = drawBorder(i, j);

			// TODO: Draw blocks inside game.

			// TODO: Draw Scores outside game map, but inside screen.

			// TODO: Draw next tetris blocks outside game map, but inside screen.

			if (!bPrinted) {
				printf(" ");
			}
		}
		nl();
	}



	return 0;
}



int gamePlay(void) {
	int infiniteLoop = 1;
	while (infiniteLoop) {
		// InfiniteLoop for game running

		display();

		// TODO: Add auto tick, proceeded without input
		sleep(1);

		// TODO: Add user input


	}

	return 0;
}


int main() {


	gamePlay();

	return 0;
}

