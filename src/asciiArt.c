/*
#####################################################################
#           Ben Morley - CMPT 201 - Project                         #
#           ID 3142870                                              #
#                                                                   #
#####################################################################
*/

#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include"objects.h"



void make_door(int y, int x){

	move(y, x);
	printw("  ");
	refresh();
}


void printCastle() {


    printw("                                               !_\n");
    printw("                                               |*~=-.,\n");
    printw("                                               |_,-'`\n");
    printw("                                               |\n");
    printw("                                               |\n");
    printw("                                              /^\\ \n");
    printw("                !_                           /   \\ \n");
    printw("                |*`~-.,                     /,    \\ \n");
    printw("                |.-~^`                     /#\"     \\ \n");
    printw("                |                        _/##_   _  \\_\n");
    printw("           _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n");
    printw("          [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n");
    printw("       !_ |_=_ =-_-_  = =_|           !_ |=_= -     |\n");
    printw("       |*`--,_- _        |            |*`~-.,= []   |\n");
    printw("       |.-'|=     []     |   !_       |_.-\"`_-      |\n");
    printw("       |   |_=- -        |   |*`~-.,  |  |=_-       |\n");
    printw("      /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]   |\n");
    printw("  _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-       |\n");
    printw(" [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-     |\n");
    printw("  |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []   |\n");
    printw(" _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -     |\\\n");
    printw("[ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-    | \\\n");
    printw("|_=__-_=-_  =_|-=_ |  ,  |     |_=-___-_ =-__|_     |  \\\n");
    printw(" | _- =-     |-_   | ((* |      |= _=       | -     |___\\\n");
    printw(" |= -_=      |=  _ |  `  |      |_-=_       |=_     |/+/|\n");
    printw(" | =_  -     |_ = _ `-.-`       | =_ = =    |=_-    ||+||\n");
    printw(" |-_=- _     |=_   =            |=_= -_     |  =    ||+||\n");
    printw(" |=_- /+\\    | -=               |_=- /+\\    |=_     |^^^|\n");
    printw(" |=_ |+|+|   |= -  -_,--,_      |_= |+|+|   |  -_   |=  |\n");
    printw(" |  -|+|+|   |-_=  / |  | \\     |=_ |+|+|   |-=_    |_-/\n");
    printw(" |=_=|+|+|   | =_= | |  | |     |_- |+|+|   |_ =    |=/\n");
    printw(" | _ ^^^^^   |= -  | |  <&>     |=_=^^^^^   |_=-    |/\n");
    printw(" |=_ =       | =_-_| |  | |     |   =_      | -_    |\n");
    printw(" |_=-_       |=_=  | |  | |     |=_=        |=-     |\n");
    printw("^^^^^^^^^^`^`^^`^`^^^\"\"\"\"\"^`^^``^^`^^`^^`^`^``^`^``^``^^\n");


}


void printTitle() {
    printw("            _  ___   _ _____ _____ _    _ _______ \n");
    printw("    ____   | |/ / \\ | |_   _/ ____| |  | |__   __|\n");
    printw("   / __ \\  | ' /|  \\| | | || |  __| |__| |  | |   \n");
    printw("  / / _` | |  < | . ` | | || | |_ |  __  |  | |   \n");
    printw(" | | (_| | | . \\| |\\  |_| || |__| | |  | |  | |   \n");
    printw("  \\ \\__,_| |_|\\_\\_| \\_|____/\\_____|_|  |_|  |_|   \n");
    printw("   \\____/                                          \n");
}


void level_outline(){
	mvhline(0, 1, '-', 79);
	mvhline(29, 1, '-', 79);
	mvvline(0, 0, '|', 30);
	mvvline(0, 80, '|', 30);

}

void level1(){
	level_outline();

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
	for(int y = 1; y < 6; y++){
		move(y, 1);
		printw("--|");
		refresh();
	}

	asciiBed(20, 1);		
	asciiTable(20, 16);
	rectangle( 4, 12, 12, 12);

	rectangle( 2, 43, 11, 4);
	asciiTable( 1, 55);
	asciiTable( 4, 55);
	asciiTable( 7, 55);
	asciiTable( 10, 55);


	asciiBed(20, 21);
	asciiTable(20, 34);

	asciiBed(20, 43);
	asciiTable(26, 56);

	asciiBed(20, 76);
	asciiTable(26, 76);


}



