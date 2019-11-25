all: Cgol.o Cgol

Cgol: Cgol.o PrintCgolBoard.o replaceChar.o removeSpace.o
	gcc -ansi -Wall -o Cgol Cgol.o PrintCgolBoard.o replaceChar.o removeSpace.o

Cgol.o: Cgol.c
	gcc -ansi -Wall -c Cgol.c

PrintCgolBoard.o: PrintCgolBoard.c
	gcc -ansi -Wall -c PrintCgolBoard.c

replaceChar.o: replaceChar.c
	gcc -ansi -Wall -c replaceChar.c

removeSpace.o: removeSpace.c
	gcc -ansi -Wall -c removeSpace.c

clean:
	rm Cgol.o PrintCgolBoard.o replaceChar.o removeSpace.o
