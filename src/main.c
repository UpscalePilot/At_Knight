/*
#####################################################################
#           Ben Morley - CMPT 201 - Project                         #
#           ID 3142870                                              #
#                                                                   #
#####################################################################
*/

// sorry the code is light on comments, I'm very tired and I've been 
// working on a project for another class as well as this and I'm
// too exhausted to any more tonight

#define HEIGHT 29
#define WIDTH  80


// HEADERS
#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<string.h>
#include"asciiArt.h"
#include"level1.h"
#include"level2.h"
#include"level3.h"

// PROTOTYPES
void init_scr();
void splash_screen();
void display_level(int);
void game_op();
int isPositionEmpty(int, int);
void level4();
void display_info(int, int, int);
void check_interaction(int, int, int, int*, int*);

int main(int argc, char* argv[]){

	init_scr();			//initializes screen
	raw();
    keypad(stdscr, TRUE);
    noecho();

	splash_screen();	//displays splash screen
	clear();		// clear screen

	game_op();

	endwin();	//closes window at end of program
}

void init_scr(){
	// init
	initscr();		//initialize screen
	start_color();		//start colors
	init_pair(1,COLOR_BLUE, COLOR_BLACK);	//color pattern for text
	init_pair(2,COLOR_GREEN, COLOR_BLACK);	//color pattern for ascii art

}

void splash_screen(){
	attron(COLOR_PAIR(2));	//sets the colors to green/black
	printTitle();			// prints the title ascii art for the game
	printCastle();      // Print the castle ASCII art
    refresh();          // Refresh the screen
	attroff(COLOR_PAIR(2));		//ends the green/black color
	refresh();		//refreshes screen


	refresh();
	int x, y;	
	getyx(stdscr, y, x);	//gets x and y coordinates
	mvprintw( y, (x+15), "Use the arrow keys to move");
	mvprintw( y+1, (x+15), "Use the space bar for actions");
	attron(COLOR_PAIR(1));		// changes color to blue/black
	attron(A_BLINK);		// blinking for the 'press any key' text
	mvprintw(y+3, x+15, "PRESS ANY KEY TO CONTINUE");	//displays the press any key message
	attroff(COLOR_PAIR(1));		// turns off the blue/black color
	curs_set(0);	// hides the cursor
	refresh(); 		// refreshes screen
	getch();		// waits for a char input
	attroff(A_BLINK);		// turns off the blinking attribute

}

void level4(){
	win_screen();
	int ch;
	do{
		ch = getch();
	}while(ch != 'q');

}

void display_level(int i){
	switch(i){
		case 1:
			level1();		// displays level 1
			break;
		case 2:
			level2();
			break;
		case 3:
			level3();
			break;
		case 4:
			level4();
			break;
	}


}

int isPositionEmpty(int y, int x) {
    int ch = mvinch(y, x);  // Get the character at the specified position
    return (ch == ' ');     // Return 1 if the position is empty (a space character)
}


void display_info(int milk, int blatter, int level){

	char message[30];

	if(level == 1){
		if( milk == 0){
			strcpy(message, "Need a glass of milk!");
		}
		else{
			strcpy(message, "Better head upstairs");
		}
	}
	else if(level == 2){
		if( blatter > 0){
			strcpy(message, "Better find a bathroom!");
		}
		else{
			strcpy(message, "Time to head up to bed");
		}
	}
	else{
		strcpy(message, "Time to find my bed!");
	}

	mvprintw(30, 30, message);
	mvprintw(30, 1, "Blatter level: %i%%", blatter);
	mvprintw(30, 72, "Milk: %i", milk);
	refresh();
}

void check_interaction(int level, int y, int x, int* milk, int* bladder){
	if(level == 1 && y == 2 && x == 48){
		(*milk)++;
	}
	else if(level == 2){
		if( ((*bladder) > 0) && ((y == 10 && x == 62) || (y == 18 && x == 6))){
			(*bladder)--;
		}
	}
	
}


void game_op(){
	int level = 1;
	int player_x = 40;
	int player_y = 28;
	int milk = 0;
	int bladder = 100;


	// Main game loop
    while (1) {
        // Clear the screen
        clear();

		if(level == 1){
			if(player_y == 6 && player_x <= 2 && milk > 0){
				level = 2;
			}
		}
		else if(level == 2){
			if(player_y == 23 && player_x >= 78 && bladder == 0){
				level = 3;
			}
		}
		else if(level == 3){
			if(player_y < 13 && player_x == 34){
				display_level(4);
				break; 
			}
		}

        // Draw the game level
        display_level(level);

        // Draw the player character
        mvprintw(player_y , player_x, "@");
		// mvprintw(31, 37, "%i , %i", player_y, player_x);
        display_info( milk, bladder, level);

		// Refresh the screen
        refresh();

        // Get user input
        int ch = getch();

        // Update player position based on input
        switch (ch) {
            case KEY_UP:
                if (isPositionEmpty(player_y - 1, player_x) && player_y > 1){
					 player_y--;
				}
                break;
            case KEY_DOWN:
                if (isPositionEmpty(player_y + 1, player_x) && player_y < HEIGHT - 1){
					player_y++;
				}
                break;
            case KEY_LEFT:
                if (isPositionEmpty(player_y, player_x - 1) && player_x > 1){
					 player_x--;
				}
                break;
            case KEY_RIGHT:
                if (isPositionEmpty(player_y, player_x + 1) && player_x < WIDTH - 1){
					 player_x++;
				}
                break;
            case 'q':
                // Quit the game
				quit_screen();
				while(ch != 'y' && ch != 'n'){
					ch = getch();
				}
				if(ch == 'y'){
					ch = 'q';
				}
                break;
			case 'p':
				pause_screen();
				ch = 'u';		//temporary assignment for the following loop
				while(ch != 'p'){
					ch = getch();
				}
				break;
			case ' ':
				check_interaction(level, player_y, player_x, &milk, &bladder);
				break;

        }
		if (ch == 'q'){
			break;
		}
	}

}

