#include"../include/Socket.h"

#include"player.h"

#define MAXREQUEST 10
#define MAXPLAYERC 20

class Server: public Socket{

private:
	Player player[MAXPLAYERC];

public:
	Server(unsigned short int port);
	~Server();
	
	int Bind();
	int Listen();
	int Accept(int i);
	int Send(const char* s, int i);
	int Receive(int i);
	void Print(int i);
	
	virtual int Send(const char* s){return 0;}
	virtual int Receive(){return 0;}
	virtual void Print(){}
	virtual int setmagsize(int i){return 0;}

};
