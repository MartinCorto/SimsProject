GestionEvenements: Personnage.o GestionEvenements.o main.o BmpLib.o OutilsLib.o
	gcc -o GestionEvenements main.o BmpLib.o OutilsLib.o Personnage.o GestionEvenements.o

main.o: main.c GestionEvenements.h Personnage.h BmpLib.h
	gcc -c -Wall main.c

GestionEvenements.o: GestionEvenements.c GestionEvenements.h
	gcc -c -Wall GestionEvenements.c

Personnage.o: Personnage.c Personnage.h
	gcc -c -Wall Personnage.c

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	gcc -c -Wall BmpLib.c

OutilsLib.o: OutilsLib.c OutilsLib.h
	gcc -c -Wall OutilsLib.c

clean:
	rm -rf main.o BmpLib.o GestionEvenements.o OutilsLib.o Personnage.o GestionEvenements
