#include"server.h"

int main(){
	
	char s[10];
	Server server(5555);
	
	if(server.Bind()) std::cout<<"bind successful!"<<std::endl;
	else return 0;
	
	if(server.Listen()) std::cout<<"listen successful!"<<std::endl;
	else return 0;
	
	if(server.Accept(0)) std::cout<<"accept successful!"<<std::endl;
	else return 0;
	
	while(1){
		
		if(server.Receive(0)) std::cout<<"receive successful!"<<std::endl;
		else return 0;
		std::cout<<std::endl<<"*****"<<std::endl;
		server.Print(0);
		std::cout<<std::endl<<"*****"<<std::endl;
		
		
		std::cin>>s;
		if(!strcmp("exit",(const char*)s)) break;
		if(server.Send((const char*)s,0)) std::cout<<"send successful!"<<std::endl;
		else return 0;
	}
	

}
