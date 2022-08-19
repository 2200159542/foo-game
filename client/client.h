#include"../include/Socket.h"

class Client:public Socket{

public:

	Client(const char* ip, unsigned short int port);
	
	int getmsize(){return this->magsize;}
	
	int Send(const char* s);
	int Receive();
	void Print();
	int setmagsize(int i);
//	virtual int Send(const char* s,int i){return 0;}
//	virtual int Receive(int i){return 0;}
//	virtual void Print(int i){}
	
};

