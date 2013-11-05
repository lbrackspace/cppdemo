CF=-O0 -ggdb -I.

all: server client lookup

ring_buffer.o: ring_buffer.h ring_buffer.cpp
	g++ $(CF) -c ring_buffer.cpp

cmd_server.o: cmd_server.h cmd_server.cpp
	g++ $(CF) -c cmd_server.cpp

server.o: server.cpp ring_buffer.h cmd_server.h
	g++ $(CF) -c server.cpp

client.o: client.cpp
	g++ $(CF) -c client.cpp

lookup.o: lookup.cpp lookup.h
	g++ $(CF) -c lookup.cpp

server: server.o cmd_server.o ring_buffer.o
	g++ $(CF) -o server server.o cmd_server.o ring_buffer.o -lboost_thread-mt -lboost_system-mt -lpthread

client: client.o
	g++ $(CF) -o client client.o -lboost_thread-mt -lboost_system-mt -lpthread

lookup: lookup.o
	g++ $(CF) -o lookup lookup.o -lboost_system-mt -lpthread

clean:
	rm *.o server client lookup
