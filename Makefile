all: Game.o Game

Game: Game.o PrintGameBoard.o replaceChar.o removeSpace.o
	gcc -ansi -Wall -o Game Game.o PrintGameBoard.o replaceChar.o removeSpace.o

Game.o: Game.c
	gcc -ansi -Wall -c Game.c

PrintGameBoard.o: PrintGameBoard.c
	gcc -ansi -Wall -c PrintGameBoard.c

replaceChar.o: replaceChar.c
	gcc -ansi -Wall -c replaceChar.c

removeSpace.o: removeSpace.c
	gcc -ansi -Wall -c removeSpace.c

clean:
	rm Game.o PrintGameBoard.o replaceChar.o removeSpace.o
