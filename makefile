main: game.o main.o
	gcc game.o main.o -o impiccato.exe

game.o:
	gcc -c game.c

main.o:
	gcc -c main.c

clean:
	rm -f *.exe *.o