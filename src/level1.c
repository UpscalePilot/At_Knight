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





void level1(){		// creates level 1
	clear();
	level_outline();		// prints out the outline

	//foyer
	mvvline(20, 38, '|', 9);	
	mvvline(20, 42, '|', 9);

	//creates front rooms
	mvhline(17, 1, '_', 37);
	mvhline(17, 43, '_', 37);
	mvhline(19, 1, '_', 37);
	mvhline(19, 43, '_', 37);

	//split front rooms
	mvvline(20, 20, '|', 9);
	mvvline(20, 60, '|', 9);
	make_door(19,10);
	make_door(19,30);
	make_door(19,50);
	make_door(19,70);

	//mid hallway & back mid wall
	mvhline(14, 39, '-', 34);
	mvvline(3, 38, '|', 15);
	mvvline(1, 42, '|', 12);
	
	//staircase
	staircaseR(1, 1);

	// prints some rectangular tables/countertops
	rectangle( 4, 12, 12, 12);
	rectangle( 4, 43, 9, 4);

	//prints a series of ascii tables in dining area
	asciiTable( 1, 55);
	asciiTable( 4, 55);
	asciiTable( 7, 55);
	asciiTable( 10, 55);


	//front left room
	asciiBed(20, 1);		
	asciiTable(20, 16);

	//front middle-left room
	asciiBed(20, 21);
	asciiTable(20, 34);

	//front middle-right room
	asciiBed(20, 43);
	asciiTable(26, 56);

	//front right room
	asciiBed(20, 76);
	asciiTable(26, 76);

	//Fridge
	move( 1, 43);
	printw("|==|");
	move( 2, 43);
	printw("|F |.");
	move( 3, 43);
	printw("|==|");
	
	refresh();
}



