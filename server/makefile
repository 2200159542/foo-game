all:player.o server.o main.o Socket.o manage.o
	c++ -o server player.o server.o main.o Socket.o manage.o -lpthread
player.o:player.cc
	c++ -c -g player.cc
server.o:server.cc
	c++ -c -g server.cc
main.o:main.cc
	c++ -c -g main.cc
Socket.o:../include/Socket.cc
	c++ -c -g ../include/Socket.cc
manage.o:manage.cc
	c++ -c -g manage.cc -l pthread

clean:
	rm *.o
