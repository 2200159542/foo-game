#include<sys/types.h>
#include<sys/socket.h>
#include<iostream>
#define PLAYBUFSIZE 10

class Player {

private:
	int fd;
	int msize;
	char buf[PLAYBUFSIZE];
	struct sockaddr addr;
	
public:
	Player();
	~Player();
	
	int getfd();
	int getmsize();
	char* getbuf();
	
	struct sockaddr& setaddr();
	int setfd(int i);
	int setmsize(int i);

};
