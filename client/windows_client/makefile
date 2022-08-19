test1:frame.o test.o ui.o client.o Socket.o
	g++ frame.o test.o ui.o client.o Socket.o -o test -Wall -lpthread -lws2_32
frame.o:frame.cc
	g++ -g -c frame.cc -Wall
test.o:test.cc
	g++ -g -c test.cc -Wall
ui.o:
	g++ -g -c ui.cc -Wall
client.o:client.cc
	g++ -g -c client.cc -Wall
Socket.o:Socket.cc
	g++ -g -c Socket.cc 

clean:
	rm *.o test
