
all: cppdemo

CF=-O0 -ggdb -I.

all: cppdemo

main.o: main.cpp
	g++ $(CF) -c main.cpp

cppdemo: main.o
	g++ $(CF) -o cppdemo main.o

clean:
	rm *.o
	rm cppdemo
