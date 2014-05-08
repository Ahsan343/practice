# Makefile

CC = g++
CFLAGS = -g -Wall
OBJ1 = pTreeNode.o pTree.o main.o

all: longestWord

longestWord: $(OBJ1)
	$(CC) $(CFLAGS) -o longestword $(OBJ1)

clean:
	rm -rf *.o longestword

pTreeNode.o: pTreeNode.cpp
	$(CC) $(CFLAGS) -c pTreeNode.cpp $(INC)
pTree.o:pTree.cpp
	$(CC) $(CFLAGS) -c pTree.cpp $(INC)
main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(INC)
