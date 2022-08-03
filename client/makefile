client:client.o main.o Socket.o
	g++ -o client  client.o main.o Socket.o
client.o:client.cc
	g++ -c client.cc
main.o:main.cc
	g++ -c main.cc
Socket.o:../include/Socket.cc
	g++ -c ../include/Socket.cc 

clean:
	rm *.o
