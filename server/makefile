all:player.o server.o main.o Socket.o
	g++ -o server player.o server.o main.o Socket.o
player.o:player.cc
	g++ -c player.cc
server.o:server.cc
	g++ -c server.cc
main.o:main.cc
	g++ -c main.cc
Socket.o:../include/Socket.cc
	g++ -c ../include/Socket.cc

clean:
	rm *.o
