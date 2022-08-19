#include"../include/Socket.h"
#include"player.h"

#define MAXREQUEST 4
#define MAXPLAYERC 4


class Server: public Socket{

public:
	Player player[MAXPLAYERC+1];

public:
	Server(unsigned short int port);
	~Server();
	
	int Bind();
	int Listen();
	int Accept(int);
	int Send(const char*, int);
	int Receive(int);
	void Print(int);
	void Close(int);
	
//	virtual int Send(const char* s){return 0;}
//	virtual int Receive(){return 0;}
//	virtual void Print(){}
//	virtual int setmagsize(int i){return 0;}

};
