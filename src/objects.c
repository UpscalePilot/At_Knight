/*
#####################################################################
#           Ben Morley - CMPT 201 - Project                         #
#           ID 3142870                                              #
#                                                                   #
#####################################################################
*/

// HEADERS
#include<ncurses.h>


// quick function to print a bed object at co-ordinates provided in arguments
void asciiBed( int y, int x){
	move(y,x);
	printw("+--+");		// headboard
	move(y+1, x);
	printw("|^^|");		// prints 2 pillows at top of bed
	move(y+2, x);
	printw("|  |");		// middle section
	move(y+3, x);
	printw("+--+");		// foot of the bed
	refresh();

}


// quick function to print a small table at co-ordinates provided in arguments
void asciiTable( int y, int x){
	move(y,x);		
	printw(" __ ");		// top of table
	move(y+1,x);
	printw("/  \\");	// middle of table
	move(y+2,x);
	printw("\\__/");	// bottom of table
	refresh();
}

// quick function for creating rectangles at y, x with a size of lxw
void rectangle( int y, int x, int l, int w){
	
	mvhline( y, (x+1), '_', (w-2));			// top of rectangle
	mvhline( (y+l-1), (x+1), '_', (w-2));	// bottom of rectangle

	mvvline( (y+1), x, '|', (l-1));			// left side
	mvvline( (y+1), (x+w-1), '|', (l-1));	// right side

	refresh();
}

