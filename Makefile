all: reader

reader: reader.c list.c
	gcc -g -Wall reader.c list.c -o list_reader