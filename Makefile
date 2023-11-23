# Makefile for Ben Morley/3142870

# C compiler
CC:= gcc

# C Flags
CFLAGS:=-std=c11 -Wall -lncurses -ltinfo

# V Path
VPATH:= src bin obj

atKnight: main.o asciiArt.o	objects.o	# create  app
	$(CC) -o $@ $(CFLAGS) $^
	mv *.o obj	

asciiArt.o: asciiArt.c asciiArt.h 
	$(CC) $(CFLAGS) -c $^
	mv src/*.gch obj

objects.o: objects.c objects.h
	$(CC) $(CFLAGS) -c $^
	mv src/*.gch obj

%.o: %.c			# compile .c files
	$(CC) -c $(CFLAGS) $^


.PHONY: clean, run, r
clean:				# removes all .o and app files
	rm -f *.o atKnight obj/*.o obj/*.gch


run:				# runs app_name application
	./atKnight

r:
	make
	make run

