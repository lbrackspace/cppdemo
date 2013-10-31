CF=-O0 -ggdb -I.

all: server client

server.o: server.cpp
	g++ $(CF) -c server.cpp

client.o: client.cpp
	g++ $(CF) -c client.cpp

server: server.o
	g++ $(CF) -o server server.o -lboost_thread-mt -lboost_system-mt -lpthread

client: client.o
	g++ $(CF) -o client client.o -lboost_thread-mt -lboost_system-mt

clean:
	rm *.o server client
