/*
#####################################################################
#           Ben Morley - CMPT 201 - Project                         #
#           ID 3142870                                              #
#                                                                   #
#####################################################################
*/


// HEADERS
#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include"asciiArt.h"

// PROTOTYPES
void init_scr();
void splash_screen();
void display_level(int);

int main(int argc, char* argv[]){

	init_scr();			//initializes screen
	splash_screen();	//displays splash screen
	
	clear();		// clear screen

	display_level(1);		// displays level 1
	getch();		// waits for user to enter a character

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


	attron(A_BLINK);		// blinking for the 'press any key' text
	refresh();
	int x, y;	
	getyx(stdscr, y, x);	//gets x and y coordinates
	move( y , (x + 15) );	//moves cursor to middle of screen under ascii castle art
	attron(COLOR_PAIR(1));		// changes color to blue/black
	printw("PRESS ANY KEY TO CONTINUE");	//displays the press any key message
	attroff(COLOR_PAIR(1));		// turns off the blue/black color
	curs_set(0);	// hides the cursor
	refresh(); 		// refreshes screen
	getch();		// waits for a char input
	attroff(A_BLINK);		// turns off the blinking attribute

}

void display_level(int i){
	switch(i){
		case 1:
			level1();		// displays level 1
			break;
	}

}
