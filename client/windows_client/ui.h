#include"client.h"


#define IPADDR "43.142.193.85"
#define PORT 12345

class UI{


public:
	
	Client client;
	
	UI();
	
	void showBegin();	
	int inputClass();
//	int inputSite();
	int inputOption(int);
	void showMenu_1();
	void showMenu_2();
	int logIn();
	int signUp();
	int process(const char* s);
	int pUser();
	
};
