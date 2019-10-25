#include<stdio.h>

// Screen size. Putty has default of 24x80 characters can be shown.
#define SCREEN_ROWS 24
#define SCREEN_COLUMNS 80

// We do have border like | - |, we need space between game and screen.
#define PADDING_ROWS 0
#define PADDING_COLUMNS 1

// Square made of GAME_ROWS x COLUMNS is where the tetris block can reside.
#define GAME_ROWS 23
#define GAME_COLUMNS 10


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

	for (i = 0; i < SCREEN_ROWS; i++) {
		for (j = 0; j < SCREEN_COLUMNS; j++) {
			bPrinted = 0;

			bPrinted = drawBorder(i, j);

			if (!bPrinted) {
				printf(" ");
			}
		}
		nl();
	}



	return 0;
}




int main() {

	display();

	return 0;
}

