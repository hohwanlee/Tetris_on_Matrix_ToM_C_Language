
// TODO: Separate with header files.
// TODO: Include function prototypes in header files.

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

// TODO: Remove arbitary initial values built for debugging

// Define screen as 2D array, and game map as 2D array.
int screen[SCREEN_ROWS][SCREEN_COLUMNS] = { {0} };

int game[GAME_ROWS][GAME_COLUMNS] = { {0,100,0,0,0,0,0,0,0,0},{100,100,100,0,0,0,0,0,0,0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{1,0,1,1,1,1,1,1,1,1} }; // initial value for testing drawing


// increase score when time pass or a line or more has cleared.
int score = 0;;


//////////////////////////
/* Functions Prototypes */
//////////////////////////