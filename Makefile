all: Cgo.o Cgo

Cgo: Cgo.o PrintCgoBoard.o replaceChar.o removeSpace.o
	gcc -ansi -Wall -o Cgo Cgo.o PrintCgoBoard.o replaceChar.o removeSpace.o

Cgo.o: Cgo.c
	gcc -ansi -Wall -c Cgo.c

PrintCgoBoard.o: PrintCgoBoard.c
	gcc -ansi -Wall -c PrintCgoBoard.c

replaceChar.o: replaceChar.c
	gcc -ansi -Wall -c replaceChar.c

removeSpace.o: removeSpace.c
	gcc -ansi -Wall -c removeSpace.c

clean:
	rm Cgo.o PrintCgoBoard.o replaceChar.o removeSpace.o
