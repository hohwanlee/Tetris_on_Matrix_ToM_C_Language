#include<stdio.h>
#include <poll.h>
#include <unistd.h>
#include "Tetris.h"



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


// Draw blocks inside of game map.
int drawBlocks(int i, int j) {
	int bPrinted = 0;
	if (i >= PADDING_ROWS && i - PADDING_ROWS < GAME_ROWS && j >= PADDING_COLUMNS && j - PADDING_COLUMNS < GAME_COLUMNS) {
		if (game[i - PADDING_ROWS][j - PADDING_COLUMNS] > 0) {
			printf("O");
			bPrinted = 1;
		}
	}


	return bPrinted;
}


// Display with using printf. Check empty space and print " "
int display() {
	int i, j;

	int bPrinted;

	// leave top lines empty because of user inputs left behind. clear it away with new lines to hide.
	nl();
	nl();

	for (i = 0; i < SCREEN_ROWS; i++) {
		for (j = 0; j < SCREEN_COLUMNS; j++) {
			bPrinted = 0;

			// Conditional expression. Check border first and if empty check there is blocks.
			bPrinted = drawBorder(i, j) ? 1 : drawBlocks(i, j);

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


int move(int x, int y) {
	// TODO : Implements
	return 0;
}
int rotate() {
	// TODO : Implements
	return 0;
}

int gamePlay(void) {
	char buf[10];
	int count = 0;

	int infiniteLoop = 1;
	int i;
	while (infiniteLoop) {
		// InfiniteLoop for game running

		display();

		// TODO: Add auto tick, proceeded without input
		// TODO: Change 1 second sleep to more smaller scale. like 0.5 sec, 0.1 sec, by using nanosleep.
		// sleep(1);

		// TODO: Add user input

		/* Source code from
		*  https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input#comment15290087_448982
		*  C non-blocking keyboard input
		*  Answered by Alnitak
		*/

		struct pollfd mypoll = { STDIN_FILENO, POLLIN | POLLPRI };
		char stringInput[INPUT_BUFFER_SIZE];

		

		// TODO: Change it to faster polling at release.
		if (poll(&mypoll, 1, 2000))
		{
			scanf("%s",stringInput);
			printf("READ!! - %s", stringInput);
			// Read char
			for (i = 0; i < INPUT_BUFFER_SIZE && stringInput[i] != '\n' && stringInput != '\0'; i++) {
				switch (stringInput[i]) {
				case 'A':
				case 'a': // A key : Move Left

					break;
				case 'S':
				case 's': // S key : Move Down

					break;
				case 'D':
				case 'd': // D key : Move Right

					break;
				case 'W':
				case 'w': // Rotate block

					break;
				case ' ': // Fall down 
					// move down until collision
					

					break;
				default:
					printf("ERROR! Default!");
					i = 0;
					i = 99 / i; // Force error
					break;
				}
			}
		}
		else
		{
			printf("--NO--");
			// Read nothing
		}


		count++;
	}

	return 0;
}

int warning(void) {
	int i;
	for (i = 0; i < SCREEN_ROWS - 2; i++) {
		nl();
	}
	printf("================================================================================\n\n");
	printf("This game must be run on Columns x Rows = 80x24, and with the font with Courier New\n\n");	
	printf("--------------------------------------------------------------------------------\n\n");
	printf("Use Enter to confirm movement. \n\n");
	printf("Use ASD key to move. \n\n");
	printf("Use W key to rotate. \n\n");
	printf("Use Space Bar key to fall down fast. \n\n");
	printf("================================================================================\n\n");
	printf("Press Enter to continue...\n\n");
	getchar(); // stop for user input.
}

int main() {

	warning();

	gamePlay();

	return 0;
}

