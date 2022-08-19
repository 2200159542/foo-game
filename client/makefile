test1:frame.o test.o ui.o client.o Socket.o
	g++ -o client ./*.o -Wall -lpthread
frame.o:frame.cc
	g++ -g -c frame.cc -Wall
test.o:test.cc
	g++ -g -c test.cc -Wall
ui.o:
	g++ -g -c ui.cc -Wall
client.o:client.cc
	g++ -g -c client.cc -Wall
Socket.o:../include/Socket.cc
	g++ -g -c ../include/Socket.cc 

clean:
	rm *.o client
