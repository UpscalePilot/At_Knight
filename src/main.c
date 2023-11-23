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

	
	init_scr();
	splash_screen();
	
	clear();

	display_level(1);
	getch();

	endwin();
}

void init_scr(){
	// init
	initscr();
	start_color();
	init_pair(1,COLOR_BLUE, COLOR_BLACK);
	init_pair(2,COLOR_GREEN, COLOR_BLACK);

}

void splash_screen(){
	attron(COLOR_PAIR(2));
	printTitle();
	printCastle();      // Print the castle ASCII art
    refresh();          // Refresh the screen
	attroff(COLOR_PAIR(2));
	refresh();


	attron(A_BLINK);
	refresh();
	int x, y;
	getyx(stdscr, y, x);
	move( y , (x + 15) );
	attron(COLOR_PAIR(1));
	printw("PRESS ANY KEY TO CONTINUE");
	attroff(COLOR_PAIR(1));
	curs_set(0);
	refresh(); 
	getch();
	attroff(A_BLINK);

}

void display_level(int i){
	switch(i){
		case 1:
			level1();
			break;
	}

}
