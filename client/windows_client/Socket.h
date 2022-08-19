
#define BUFSIZE 20



class Socket{

protected:
	const char* ip;
	unsigned short int port;
	SOCKET fd;
	WSADATA wd;
	char buf[BUFSIZE];
	int magsize;
	struct sockaddr_in addr;
	
	void conv();

public:

	Socket(const char* ip, unsigned short int port);
	Socket(unsigned short int port);
	~Socket();
	
	int link();
	char* getbuf(){return this->buf;}
//	virtual int Send(const char* s)=0;
//	virtual int Receive()=0;
//	virtual void Print()=0;
//	virtual int Send(const char* s,int i)=0;
//	virtual int Receive(int i)=0;
//	virtual void Print(int i)=0;
//	virtual int setmagsize(int i)=0;
	
};
