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



void level2(){
	clear();
	level_outline();
	staircaseR(1,1);
	staircaseL(24, 77);

	//Hallway structure
	mvhline( 5,  4, '-', 76);
	mvhline( 7,  1, '-', 76);
	
	mvhline(24,  1, '-', 76);
	mvhline(22,  4, '-', 76);

	mvvline( 8, 76, '|',  5);
	mvvline(16,  4, '|',  6);	
	
	mvhline(15,  4, '-', 76);
	mvhline(13,  1, '-', 76);


	//Room division
	mvvline( 1, 20, '|', 4);
	mvvline( 1, 40, '|', 4);
	mvvline( 1, 60, '|', 4);

	mvvline( 8, 20, '|', 5);
	mvvline( 8, 40, '|', 5);
	mvvline( 8, 60, '|', 5);

	mvvline(16, 20, '|', 6);
	mvvline(16, 40, '|', 6);
	mvvline(16, 60, '|', 6);
	
	mvvline(25, 20, '|', 4);
	mvvline(25, 40, '|', 4);
	mvvline(25, 60, '|', 4);

	//Doors
	
	// R1
	make_door( 5,  9);
	make_door( 5, 29);
	make_door( 5, 49);
	make_door( 5, 69);

	// R2
	make_door( 7, 18);
	make_door( 7, 38);
	make_door( 7, 58);
	make_door( 7, 74);
		
	make_door(13, 21);
	make_door(13, 41);
	make_door(13, 61);

	// R3
	make_door(15, 18);
	make_door(15, 38);
	make_door(15, 58);
	make_door(15, 69);
	
	// R4
	make_door(24,  9);
	make_door(24, 29);
	make_door(24, 49);
	make_door(24, 69);


	//objects
	rectangle( 1, 6, 2, 6);

	loungeRoom(1 , 22 );
	loungeRoom(8 , 22 );
	loungeRoom(1 , 62 );
	loungeRoom(25,  1 );
	loungeRoom(25, 22 );



	for(int row = 1; row < 30; row += 8){
		asciiTable( row, 43);
		asciiTable( row, 47);	
		asciiTable( row, 51);
		asciiTable( row, 55);
	}

	asciiTable( 25, 63);
	asciiTable( 25, 67);	
	asciiTable( 25, 71);

	
	bedroom(8, 1);
	bedroom(16, 21);
	bedroom(16, 61);


	bathroom(8, 61);
	bathroom(16, 5);


	refresh();
}




