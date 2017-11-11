main:    main.cpp Pieza.o 
	g++ main.cpp Pieza.o -o main
main.o:	main.cpp Pieza.h 
	g++ -c main.cpp
Pieza:	Pieza.cpp Pieza.h
	g++ -c Pieza.cpp
clean:
	rm  *.o main 