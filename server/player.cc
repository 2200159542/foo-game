#include"player.h"

Player::Player(){

}

Player::~Player(){

}

int Player::getfd(){
	std::cout<<"getfd:"<<this->fd<<std::endl;
	return this->fd;
}

int Player::getmsize(){
//	std::cout<<"getmsize:"<<this->msize<<std::endl;
	return this->msize;
}

char* Player::getbuf(){
//	std::cout<<"getbuf:"<<this->buf<<std::endl;
	return this->buf;
}

struct sockaddr& Player::setaddr(){
	std::cout<<"setaddr:"<<&this->addr<<std::endl;
	return this->addr;
}

int Player::setfd(int i){
	std::cout<<"setfd:"<<i<<std::endl;
	this->fd=i;
	return 1;
}

int Player::setmsize(int i){
	std::cout<<"setmsize:"<<i<<std::endl;
	this->msize=i;
	return 1;
}




