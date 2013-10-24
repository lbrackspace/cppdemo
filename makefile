CF=-O0 -ggdb -I.
#CF= -O3 -ftracer -funroll-loops -funsafe-loop-optimizations -ggdb -I.
#CF= -O3 -I.

all: cppdemo

main.o: main.cpp DemoUtils.h Matrix.h
	g++ $(CF) -c main.cpp 

DemoUtils.o: DemoUtils.cpp DemoUtils.h
	g++ $(CF) -c DemoUtils.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ $(CF) -c Matrix.cpp

cppdemo: main.o DemoUtils.o Matrix.o
	g++ $(CF) -o cppdemo main.o DemoUtils.o Matrix.o

clean:
	rm *.o
	rm cppdemo
