#include<stdio.h>

#define SCREEN_ROWS 24
#define SCREEN_COLUMNS 80

#define PADDING_ROWS 0
#define PADDING_COLUMNS 1

#define GAME_ROWS 23
#define GAME_COLUMNS 10



int screen[SCREEN_ROWS][SCREEN_COLUMNS] = { {0} };

int game[GAME_ROWS][GAME_COLUMNS] = { {0,1,0,0,0,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0},{0} };


int score = 0;;

int nl() { // simply newline
	printf("\n");
}

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

