#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<cstring>

#define BUFSIZE 100



class Socket{

protected:
	const char* ip;
	unsigned short int port;
	int fd;
	char buf[BUFSIZE];
	int magsize;
	struct sockaddr_in addr;

public:

	Socket(const char* ip, unsigned short int port);
	Socket(unsigned short int port);
	~Socket();
	
	void conv();
	int link();
	virtual int Send(const char* s)=0;
	virtual int Receive()=0;
	virtual void Print()=0;
	virtual int Send(const char* s,int i)=0;
	virtual int Receive(int i)=0;
	virtual void Print(int i)=0;
	virtual int setmagsize(int i)=0;
	
};
