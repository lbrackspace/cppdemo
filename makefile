CF=-O0 -ggdb -I.
#CF= -O3 -ftracer -funroll-loops -funsafe-loop-optimizations -ggdb -I.
#CF= -O3 -I.

all: cppdemo

main.o: main.cpp DemoUtils.h
	g++ $(CF) -c main.cpp

DemoUtils.o: DemoUtils.cpp DemoUtils.h
	g++ $(CF) -c DemoUtils.cpp

cppdemo: main.o DemoUtils.o
	g++ $(CF) -o cppdemo main.o DemoUtils.o

clean:
	rm *.o
	rm cppdemo
