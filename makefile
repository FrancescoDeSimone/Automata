CC = g++
LIBRARY = -lsfml-graphics -lsfml-window -lsfml-system 
OPTIMIZATION = -Ofast -march=native -mtune=native

all: Automata ant.o main.o clean

Automata: main.o ant.o
	$(CC) $(LIBRARY) -o Automata main.o ant.o
ant.o: source/ant.cpp
	$(CC) $(OPTIMIZATION) -c source/ant.cpp
main.o: source/main.cpp
	$(CC) $(OPTIMIZATION) -c source/main.cpp

.PHONY: clean
clean:
	rm *.o
