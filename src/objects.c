/*
#####################################################################
#           Ben Morley - CMPT 201 - Project                         #
#           ID 3142870                                              #
#                                                                   #
#####################################################################
*/

#include<ncurses.h>



void asciiBed( int y, int x){
	move(y,x);
	printw("+--+");
	move(y+1, x);
	printw("|^^|");
	move(y+2, x);
	printw("|  |");
	move(y+3, x);
	printw("+--+");
	refresh();

}

void asciiTable( int y, int x){
	move(y,x);
	printw(" __ ");
	move(y+1,x);
	printw("/  \\");
	move(y+2,x);
	printw("\\__/");
	refresh();
}


void rectangle( int y, int x, int l, int w){
	
	mvhline( y, (x+1), '_', (w-2));
	mvhline( (y+l-1), (x+1), '_', (w-2));

	mvvline( (y+1), x, '|', (l-1));
	mvvline( (y+1), (x+w-1), '|', (l-1));

	refresh();
}

