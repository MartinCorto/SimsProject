sims: sims.o graph.o libisentlib.a
	gcc -Wall sims.o graph.o -o sims libisentlib.a -lm -lglut -lGL -lX11
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall exemple.o -o exemple libisentlib.a -lm -framework OpenGL -framework GLUT

sims.o: sims.c graph.h GfxLib.h BmpLib.h ESLib.h
	gcc -Wall -c -g sims.c
	
graph.o: graph.c graph.h GfxLib.h
	gcc -Wall -c -g graph.c
			

libisentlib.a: BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ar r libisentlib.a BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ranlib libisentlib.a

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	gcc -Wall -O2 -c -g BmpLib.c

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	gcc -Wall -O2 -c -g ESLib.c

ErreurLib.o: ErreurLib.c ErreurLib.h
	gcc -Wall -O2 -c -g ErreurLib.c

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
	gcc -Wall -O2 -c -g GfxLib.c -I/usr/include/GL
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall -O2 -c -g GfxLib.c -Wno-deprecated-declarations

OutilsLib.o: OutilsLib.c OutilsLib.h
	gcc -Wall -O2 -c -g OutilsLib.c

SocketLib.o: SocketLib.c SocketLib.h
	gcc -Wall -O2 -c -g SocketLib.c

ThreadLib.o: ThreadLib.c ThreadLib.h
	gcc -Wall -O2 -c -g ThreadLib.c

TortueLib.o: TortueLib.c TortueLib.h GfxLib.h
	gcc -Wall -O2 -c -g TortueLib.c

VectorLib.o: VectorLib.c VectorLib.h
	gcc -Wall -O2 -c -g VectorLib.c -msse3

WavLib.o: WavLib.c WavLib.h OutilsLib.h
	gcc -Wall -O2 -c -g WavLib.c -Wno-unused-result
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall -O2 -c -g WavLib.c

zip:
	tar -cvzf libisentlib.tgz *.[ch] *.bmp *.pdf makefile

clean:
	rm -f *~ *.o

deepclean: clean
	rm -f exemple exempleTortue libisentlib.a

