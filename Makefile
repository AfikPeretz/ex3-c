CC=gcc
AR=ar
FLAGS= -Wall

all: txtfind isort

isort:isort.o
	$(CC) $(FLAGS) -o isort $^
	
txtfind:txtfind.o
	$(CC) $(FLAGS) -o txtfind $^
	
isort.o:isort.c isort.h
	$(CC) $(FLAGS) -c $^
	
txtfind.o:txtfind.c txtfind.h
	$(CC) $(FLAGS) -c $^

.PHONY:clean all

clean:
	rm *.o isort txtfind *.h.gch
