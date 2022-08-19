#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<cstring>
#include"server.h"


Server::Server(unsigned short int port):
Socket(port){
	
}

Server::~Server(){
	
}

int Server::Bind(){
	
	this->conv();
	socklen_t addrlen = sizeof(struct sockaddr);
	if(!bind(this->fd, (const sockaddr*)&(this->addr), addrlen)) return 1;
	
	std::cout<<"bind addr error!"<<std::endl;
	return 0;
}

int Server::Listen(){
	if(!listen(this->fd, MAXREQUEST)) return 1;
	
	std::cout<<"set listen error!"<<std::endl;
	return 0;
}

int Server::Accept(int i){

	socklen_t addrlen = sizeof(struct sockaddr);
	if(this->player[i].setfd(accept(this->fd, &this->player[i].setaddr(), &addrlen))) return 1;
	
	std::cout<<"accpet request error!"<<std::endl;
	return 0;
}

int Server::Send(const char* s, int i){

	if(write(this->player[i].getfd(), s, strlen(s))==strlen(s)) return 1;
	std::cout<<"send massage error!"<<std::endl;
	return 0;
}

int Server::Receive(int i){
	
	if(this->player[i].setmsize(read(this->player[i].getfd(), this->player[i].getbuf(), PLAYBUFSIZE))) return 1;
	std::cout<<"read massage error!"<<std::endl;
	return 0;
}

void Server::Print(int i){
	write(1, this->player[i].getbuf(), this->player[i].getmsize());
}

void Server::Close(int i){
	close(this->player[i].getfd());
}
