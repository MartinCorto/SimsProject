GestionEvenements: GestionEvenements.o main.o BmpLib.o OutilsLib.o
	gcc -o GestionEvenements GestionEvenements.o main.o BmpLib.o OutilsLib.o

main.o: main.c GestionEvenements.h
	gcc -c -Wall main.c

GestionEvenements.o: GestionEvenements.c GestionEvenements.h BmpLib.h
	gcc -c -Wall GestionEvenements.c

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	gcc -c -Wall BmpLib.c

OutilsLib.o: OutilsLib.c OutilsLib.h
	gcc -c -Wall OutilsLib.c

clean:
	rm -rf main.o GestionEvenements.o BmpLib.o OutilsLib.o GestionEvenements
