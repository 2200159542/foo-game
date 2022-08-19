#include<unistd.h>
#include<winsock2.h>
#include<iostream>
#include<cstring>
#include"Socket.h"

Socket::Socket(const char* ip, unsigned short int port):
magsize(0),ip(ip),port(port){

	memset(&(this->wd),0,sizeof(this->wd));
	
	if(WSAStartup(MAKEWORD(2,2),&wd)!=0){
		std::cout<<"startup error!\n";
		return;
	}
	fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	
	if(fd==INVALID_SOCKET){
		std::cout<<"socket error!\n";
		return;
	}
	memset(this->buf,0,BUFSIZE);
	memset(&(this->addr),0,sizeof(this->addr));

}
	
Socket::Socket(unsigned short int port):
fd(socket(AF_INET, SOCK_STREAM, 0)),magsize(0),port(port){
	this->ip="0.0.0.0";
	if(fd==-1) std::cout<<"socket fd error!"<<std::endl;
	std::cout<<"success make socket!"<<std::endl;
	memset(this->buf,0,BUFSIZE);
}
Socket::~Socket(){

	if(fd==-1) {std::cout<<"close socket erroe!"<<std::endl; return;}
	closesocket(this->fd);
	WSACleanup();
//	std::cout<<"successful close socket!"<<std::endl;
}

void Socket::conv(){
	
	this->addr.sin_family = AF_INET;
	this->addr.sin_port = htons(this->port);
	this->addr.sin_addr.s_addr = inet_addr(this->ip);
}

int Socket::link(){
	
	this->conv();
	if(connect(this->fd, (const sockaddr*)&addr, sizeof(addr))!=SOCKET_ERROR) return 1;
	std::cout<<"link error!"<<std::endl;
	return 0;
}
