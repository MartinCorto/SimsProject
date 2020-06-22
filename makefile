Personnage: Personnage.o  main.o BmpLib.o OutilsLib.o
	gcc -o Personnage main.o BmpLib.o OutilsLib.o Personnage.o 

main.o: main.c Personnage.h
	gcc -c -Wall main.c

Personnage.o: Personnage.c Personnage.h
	gcc -c -Wall Personnage.c

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	gcc -c -Wall BmpLib.c

OutilsLib.o: OutilsLib.c OutilsLib.h
	gcc -c -Wall OutilsLib.c

clean:
	rm -rf main.o BmpLib.o OutilsLib.o Personnage.o Personnage
