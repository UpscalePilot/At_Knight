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

void staircaseR( int y, int x){

	for( int a = 0; a < 5; a++){
		move((y+a), x);
		printw("--|");
	}

	refresh();
}


void staircaseL( int y, int x){
	
	for( int a = 0; a < 5; a++){
		move((y+a), x);
		printw("|--");
	}

	refresh();
}



// quick function to make a door gap in walls
void make_door(int y, int x){

	move(y, x);		// moves co-ordinates to where the door will go
	printw("  ");	// clears the contents of those spaces where the door will go
	refresh();		// refreshes screen
}


void couch( int y, int x){
	
	move(y, x);
	printw(" _ _ _ _");
	move(y+1, x);
	printw("|_|_|_|_|");
	move(y+2, x);
	//printw("---------");

	refresh();

}

void level_outline(){			//prints a level outline 30x80
	mvhline(0, 1, '-', 79);		//prints top wall
	mvhline(29, 1, '-', 79);	//prints bottom wall
	mvvline(0, 0, '|', 30);		//prints left wall
	mvvline(0, 80, '|', 30);	//prints right wall

}

void loungeRoom(int y, int x){
	couch(y, x);
	move(y+3, x+2);
	printw("TTTT");
	asciiTable( y, x + 12);

	refresh();
}

void bedroom( int y, int x){
	asciiBed(y, x);
	asciiTable( y + 2 , x + 14 );


	refresh();
}


void bathroom( int y, int x){
	move(y,x);
	printw("|_|o");
	move(y+1, x);
	printw(" U ");
	// move(y+2, x);
	// printw("    ------"); 

	x += 12;
	y += 1;

	move(y, x);
	printw("|-|");
	move(y + 1, x);
	printw("|C|");
	move(y + 2, x);
	printw("|C|");
	move(y + 3, x);
	printw("|-|");

	refresh();
}


void giantBed(int y, int x){
	move(y,x);
	printw("|-----------------------|");
	move(y+1, x);
	printw("|      +---------+      |");
	move(y+2,x);
	printw("|      |^^^^^^^^^|      |");
	move(y+3,x);	
	for(int a = 4; a < 13; a++){
		printw("|      |         |      |");
		move(y+a, x);
	}


	printw("|      +---------+      |");
	move(y+13, x);
	printw("|_______________________|");


	refresh();
}


void gridnumbers(){

	for(int a = 1; a < 30; a += 2){
		move(a, 82);
		printw("-%i", a);
	}

	for(int b = 0; b <= 80; b += 5){
		move(31, b);
		printw("|");
		move(32, b);
		printw("%i", b);
	}

	refresh();
}
