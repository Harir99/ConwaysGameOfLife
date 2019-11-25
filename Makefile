all: Cgol.o Cgol

Cgol: Cgol.o PrintGameBoard.o replaceChar.o removeSpace.o
	gcc -ansi -Wall -o Cgol Cgol.o PrintGameBoard.o replaceChar.o removeSpace.o

Cgol.o: Cgol.c
	gcc -ansi -Wall -c Cgol.c

PrintGameBoard.o: PrintGameBoard.c
	gcc -ansi -Wall -c PrintGameBoard.c

replaceChar.o: replaceChar.c
	gcc -ansi -Wall -c replaceChar.c

removeSpace.o: removeSpace.c
	gcc -ansi -Wall -c removeSpace.c

clean:
	rm Cgol.o PrintGameBoard.o replaceChar.o removeSpace.o
