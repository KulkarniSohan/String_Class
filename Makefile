CC=gcc
INCLUDE_PATH=-I/home/sohan/c/OOC/String_Class/include/
EXE=./bin/string_app
CFLAGS=-g -o

all:
	$(CC) $(CFLAGS) $(EXE) $(INCLUDE_PATH) ./src/main.c 
