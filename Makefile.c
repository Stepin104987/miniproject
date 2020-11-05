OBJS	= BINARY.o
SOURCE	= BINARY.c
HEADER	= 
OUT	= final.out
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

programbin.o: programbin.c
	$(CC) $(FLAGS) programbin.c 


clean:
	rm -f $(OBJS) $(OUT)