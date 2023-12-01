# Makefile for Ben Morley/3142870

# C compiler
CC:= gcc

# C Flags
CFLAGS:=-std=c11 -Wall -lncurses -ltinfo

# V Path
VPATH:= src bin obj

atKnight: main.o asciiArt.o	objects.o level1.o level2.o level3.o	# create  app
	$(CC) -o $@ $(CFLAGS) $^
	mv *.o obj


main.o: main.c
	$(CC) -c $(CLFAGS) $^

%.o: %.c %.h			# compile .c files
	$(CC) -c $(CFLAGS) $^
	mv src/*.gch obj

.PHONY: clean, run, r
clean:				# removes all .o and app files
	rm -f *.o atKnight obj/*.o obj/*.gch


run:				# runs app_name application
	./atKnight

r:
	make
	make run

