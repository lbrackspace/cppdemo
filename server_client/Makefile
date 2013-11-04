CF=-O0 -ggdb -I.

all: server client lookup

server.o: server.cpp
	g++ $(CF) -c server.cpp

client.o: client.cpp
	g++ $(CF) -c client.cpp

lookup.o: lookup.cpp lookup.h
	g++ $(CF) -c lookup.cpp

server: server.o
	g++ $(CF) -o server server.o -lboost_thread-mt -lboost_system-mt -lpthread

client: client.o
	g++ $(CF) -o client client.o -lboost_thread-mt -lboost_system-mt

lookup: lookup.o
	g++ $(CF) -o lookup lookup.o -lboost_system-mt -lpthread

clean:
	rm *.o server client lookup
