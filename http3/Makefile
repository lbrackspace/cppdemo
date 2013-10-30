CF= -O0 -I. -ggdb

all: http3demo

posix_main.o: posix_main.cpp server.hpp
	g++ $(CF) -c posix_main.cpp

connection.o: connection.hpp request_handler.hpp
	g++ $(CF) -c connection.cpp

mime_types.o: mime_types.cpp mime_types.hpp
	g++ $(CF) -c mime_types.cpp

reply.o: reply.cpp reply.hpp
	g++ $(CF) -c reply.cpp

request.o: request.cpp header.hpp
	g++ $(CF) -c request.cpp

request_handler.o: request_handler.cpp mime_types.hpp request.hpp reply.hpp
	g++ $(CF) -c request_handler.cpp

request_parser.o: request_parser.cpp request_parser.hpp
	g++ $(CF) -c request_parser.cpp

server.o: server.cpp server.hpp
	g++ $(CF) -c server.cpp

http3demo: posix_main.o connection.o mime_types.o reply.o request_handler.o request_parser.o server.o
	g++ $(CF) -o http3demo posix_main.o connection.o mime_types.o reply.o request_handler.o request_parser.o server.o -lboost_thread-mt -lboost_system-mt

clean:
	rm *.o http3demo
