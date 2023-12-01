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
#include"objects.h"





void level3(){		// creates level 1
	clear();
	level_outline();

	//maze outline
	for(int a = 2; a < 24; a += 2){
		mvhline(a, 1, '-', 79);
	}
	mvhline(24, 1, '-', 76);
	mvhline(26, 1, '-', 76);
	
	mvvline( 2, 14, '|', 25);
	mvvline( 1, 40, '|', 26);
	mvvline( 2, 66, '|', 25);


	// column 4
	for(int b = 2; b < 24; b += 4){
		make_door(b, 78);
	}

	for(int d = 4; d < 27; d += 4){
		make_door(d, 67);
	}

	// column 3 upper half
	for(int e = 2; e < 14; e += 2){
		make_door(e, 51+e);
	}


	// column 3 lower half
	make_door(14, 53);
	make_door(16, 41);
	make_door(18, 53);
	make_door(20, 64);


	//horizontal middle
	make_door(21, 40);
	make_door(23, 40);
	make_door(25, 40);


	// column 2 lower half
	make_door(22, 15);
	make_door(24, 64);
	make_door(25, 13);


	// column 1 walls
	int xa = 4;
	int ya = 3;

	for(int a = 0; a < 9; a++){
		move(ya + (2*a), xa + a);
		printw("|");
	}


	// column 1 bottomside
	make_door(24, 1);
	make_door(22, 5);
	make_door(20, 8);
	make_door(18, 3);
	make_door(16, 2);
	make_door(14, 5);
	make_door(12, 3);
	make_door(10, 1);
	make_door( 8, 2);
	make_door( 6, 3);
	make_door( 4, 1);
	make_door( 2, 1);


	// column 1 topside 
	make_door( 2, 19);
	make_door( 4, 15);
	make_door( 6, 17);
	make_door( 8, 11);
	make_door(10, 21);
	make_door(12, 17);
	make_door(14, 21);
	make_door(16, 11);
	make_door( 7, 14);
	make_door( 9, 14);


	make_door(19, 14);
	make_door(18, 12);


	giantBed( 1, 28);
	staircaseL( 24, 77);	

	make_door(14, 29);


	refresh();
}




