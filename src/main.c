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
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"asciiArt.h"
#include"level1.h"
#include"level2.h"
#include"level3.h"

struct player{
	int level;
	int y;
	int x;
	int milk;
	int bladder;
	char message[40];
	char status;
	char body[3];
};

// PROTOTYPES
void init_scr();
void splash_screen();
void display_level(int);
void game_op();
int isPositionEmpty(int, int);
void level4();
void display_info(struct player*);
void check_levelup(struct player*);
void check_interaction(struct player*);
void movement(struct player*);
void check_message(struct player*);
void npc_interaction(struct player*, struct player*);
void npc_movement(struct player*);
void npc_handle(struct player*);


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
	int ix, iy;	
	getyx(stdscr, iy, ix);	//gets x and y coordinates
	mvprintw( iy, (ix+15), "Use the arrow keys to move");
	mvprintw( iy+1, (ix+15), "Use the space bar for actions");
	attron(COLOR_PAIR(1));		// changes color to blue/black
	attron(A_BLINK);		// blinking for the 'press any key' text
	mvprintw(iy+3, ix+15, "PRESS ANY KEY TO CONTINUE");	//displays the press any key message
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


void check_message(struct player* p1){

	if(p1->status == ' '){
		if(p1->level == 1){
			if( p1->milk == 0){
				strcpy(p1->message, "Need a glass of milk!");
			}	
			else{
				strcpy(p1->message, "Better head upstairs");
			}
		}
		else if(p1->level == 2){
			if( p1->bladder > 0){
				strcpy(p1->message, "Better find a bathroom!");
			}		
			else{
				strcpy(p1->message, "Time to head up to bed");
			}
		}
		else{
			strcpy(p1->message, "Time to find my bed!");
		}

	}

}


void display_info(struct player* p1){

	//char message[30];

	check_message(p1);

	mvprintw(30, 30, p1->message);
	mvprintw(30, 1, "Bladder level: %i%%", p1->bladder);
	mvprintw(30, 72, "Milk: %i", p1->milk);
	refresh();
}

void check_interaction(struct player* p1){
	if(p1->level == 1 && p1->y == 2 && p1->x == 48){
		p1->milk++;
	}
	else if(p1->level == 2){
		if( (p1->bladder > 0) && ((p1->y == 10 && p1->x == 62) || (p1->y == 18 && p1->x == 6))){
			p1->bladder--;
		}
	}
	else if(p1->level == 3){
		if( p1->y == 25 && p1->x == 76){
			p1->y = 19;
			p1->x = 39;
			strcpy(p1->message, "SECRET PASSAGE!!!");
			p1->status = 's';
		}
		if ( p1->y == 15 && p1->x == 13 ){
			p1->x = 15;
			strcpy(p1->message, "That was easy!");
		}
	}

	refresh();	
}


void check_levelup( struct player* p1){
		if(p1->level == 1){
			if(p1->y == 6 && p1->x <= 2 && p1->milk > 0){
				p1->level = 2;
			}
		}
		else if(p1->level == 2){
			if(p1->y == 23 && p1->x >= 78 && p1->bladder == 0){
				p1->level = 3;
			}
		}
		else if(p1->level == 3){
			if(p1->y < 13 && p1->x == 34){
				p1->level = 4;
				p1->status = 'Q'; 
			}
		}
}

void movement(struct player* p1){

        int ch = getch();

        // Update player position based on input
        switch (ch) {
            case KEY_UP:
                if (isPositionEmpty(p1->y - 1, p1->x) && p1->y > 1){
					p1->y--;
				}
                break;
            case KEY_DOWN:
                if (isPositionEmpty(p1->y + 1, p1->x) && p1->y < HEIGHT - 1){
					p1->y++;
				}
                break;
            case KEY_LEFT:
                if (isPositionEmpty(p1->y, p1->x - 1) && p1->x > 1){
					 p1->x--;
				}
                break;
            case KEY_RIGHT:
                if (isPositionEmpty(p1->y, p1->x + 1) && p1->x < WIDTH - 1){
					 p1->x++;
				}
                break;
            case 'q':
                // Quit the game
				quit_screen();
				while(ch != 'y' && ch != 'n'){
					ch = getch();
				}
				if(ch == 'y'){
					p1->status = 'Q';
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
				check_interaction(p1);
				break;

        }
}


void npc_interaction(struct player* p, struct player* npc){
	int npc_x = npc->x;
	int npc_y = npc->y;
	int p_x = p->x;
	int p_y = p->y;

	if( (p_x < (npc_x + 5)) && (p_x > (npc_x - 5)) ){
		if( (p_y < (npc_y + 5)) && (p_y > (npc_y - 5)) ){
			npc->status = 'S';
		}
	}
	else{
		npc->status = 'u';
	}


	if( (npc_x == (p_x - 1) || npc_x == (p_x + 1)) && npc_y == p_y){
		p->status = 't';
		strcpy(p->message, npc->message);
	}
	else if( (npc_y == (p_y - 1) || npc_y == (p_y + 1)) && npc_x == p_x){
		p->status = 't';
		strcpy(p->message, npc->message);
	}
	else if( p->status == 't'){
		p->status = ' ';
	}

}

void npc_movement(struct player* npc){
	if(npc->status == 'S'){
		return;
	}

    // Generate a random direction for the NPC
    int direction = rand() % 4;  // 0: up, 1: down, 2: left, 3: right

    // Move the NPC based on the random direction
    switch (direction) {
		case 0:
        	if (isPositionEmpty(npc->y - 1, npc->x) && npc->y > 1){
				npc->y--;
			}
            break;
        case 1:
            if (isPositionEmpty(npc->y + 1, npc->x) && npc->y < HEIGHT - 1){
				npc->y++;
			}
            break;
        case 2:
            if (isPositionEmpty(npc->y, npc->x - 1) && npc->x > 1){
				npc->x--;
			}
            break;
        case 3:
            if (isPositionEmpty(npc->y, npc->x + 1) && npc->x < WIDTH - 1){
				npc->x++;
			}
            break;
    }
}


void npc_handle(struct player* pp1){
	struct player npc1;

	if(pp1->level == 1){
		npc1.x = 70;
		npc1.y = 6;
		npc1.level = 1;
		npc1.status = 'u';
		strcpy(npc1.body, "!");
		strcpy(npc1.message, "F is for fridge!");
	}
	else if(pp1->level == 2){
		npc1.x = 10;
		npc1.y = 10;
		npc1.level = 2;
		npc1.status = 'u';
		strcpy(npc1.body, "8");
		strcpy(npc1.message, "The bathroom is at the end of the hall");
	}

	struct player *pnpc1;
	pnpc1 = &npc1;


	npc_interaction(pp1, pnpc1);
	npc_movement(pnpc1);


	mvprintw(npc1.y, npc1.x, npc1.body);

	refresh();
}


void game_op(){
	//int level = 1;
	//int player_x = 40;
	//int player_y = 28;
	//int milk = 0;
	//int bladder = 100;

	struct player p1;
	p1.x = 40;
	p1.y = 28;
	p1.milk = 0;
	p1.bladder = 100;
	p1.level = 1;
	p1.status = ' ';
	strcpy(p1.body, "@");
	
	struct player *pp1;
	pp1 = &p1;
	

	// Main game loop
    while (1) {
        // Clear the screen
        clear();


		check_levelup(pp1);

        // Draw the game level
        display_level(p1.level);

		
		if (p1.status == 'Q'){
			break;
		}

        // Draw the player character
        mvprintw(p1.y , p1.x, p1.body);
		npc_handle(pp1);
		mvprintw(31, 37, "%i , %i", p1.y, p1.x);
        display_info(pp1);
		

		// Refresh the screen
        refresh();
		movement(pp1);

	}

}

