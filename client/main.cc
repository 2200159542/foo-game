#include"client.h"

int main(){

	char s[100];
	Client client("127.0.0.1",5555);
	if(client.link()) std::cout<<"link successful!"<<std::endl;
	else return 0;
	
	
	while(1){
		std::cin>>s;
		if(!strcmp("exit",s)) break;
		client.Send((const char*)s);
		
		if(client.Receive()) client.Print();	
	}

}
