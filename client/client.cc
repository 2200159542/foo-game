#include"client.h"

Client::Client(const char* ip, unsigned short int port):
Socket(ip,port){

}

int Client::Send(const char* s){
	if(write(this->fd, s, strlen(s))==strlen(s)) return 1;
	std::cout<<"send massage error!"<<std::endl;
	return 0;
}

int Client::Receive(){
	
	if(this->setmagsize(read(this->fd, this->buf, BUFSIZE))) return 1;
	std::cout<<"read massage error!"<<std::endl;
	return 0;
	
}

void Client::Print(){
	write(1, this->buf, this->magsize);
	std::cout<<std::endl;
}

int Client::setmagsize(int i){

	this->magsize=i;	
	return 1;
}
