main.o: verification.h
	gcc -c -Wall main.c

build: verification.h
	gcc -o sudoku main.c -lpthread -Wall

run:
	./sudoku

clean:
	rm sudoku main.o verification.h.gch
