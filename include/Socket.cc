#include"Socket.h"

Socket::Socket(const char* ip, unsigned short int port):
fd(socket(AF_INET, SOCK_STREAM, 0)),magsize(0),ip(ip),port(port){
	if(fd==-1) std::cout<<"socket fd error!"<<std::endl;
	std::cout<<"success make socket!"<<std::endl;
		
}
	
Socket::Socket(unsigned short int port):
fd(socket(AF_INET, SOCK_STREAM, 0)),magsize(0),port(port){
	this->ip="127.0.0.1";
	if(fd==-1) std::cout<<"socket fd error!"<<std::endl;
	std::cout<<"success make socket!"<<std::endl;
		
}
Socket::~Socket(){

	if(fd==-1) {std::cout<<"close socket erroe!"<<std::endl; return;}
	close(this->fd);
	std::cout<<"successful close socket!"<<std::endl;
}

void Socket::conv(){
	memset(&(this->addr),0,sizeof(this->addr));
	this->addr.sin_family = AF_INET;
	this->addr.sin_port = htons(this->port);
	this->addr.sin_addr.s_addr = inet_addr(this->ip);
}

int Socket::link(){
	
	this->conv();
	
	if(!connect(this->fd, (const sockaddr*)&addr, sizeof(addr))) return 1;
	std::cout<<"link error!"<<std::endl;
	return 0;
}
