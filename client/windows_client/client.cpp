#include<winsock2.h>
#include<unistd.h>
#include<iostream>
#include<cstring>
#include"client.h"

Client::Client(const char* ip, unsigned short int port):
Socket(ip,port){

}

int Client::Send(const char* s){
	if(send(this->fd, s, strlen(s),0)==strlen(s)) return 1;
//	std::cout<<"send massage error!"<<std::endl;
	return 0;
}

int Client::Receive(){
	
	if(this->setmagsize(recv(this->fd, this->buf, BUFSIZE,0))) return 1;
	std::cout<<"read massage error!"<<std::endl;
	return 0;
	
}

void Client::Print(){
	write(1, this->buf, this->magsize);
	std::cout<<std::endl;
}

int Client::setmagsize(int i){
	
	if(i<0) return 0;

	this->magsize=i;	
	return 1;
}
