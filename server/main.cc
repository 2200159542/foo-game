#include<cstring>
#include<thread>
//#include"server.h"
#include"manage.h"

/*
char s[10];
Server server(55555);
	
int login(int i){

	if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
	if(!strncmp((const char*)server.player[i].getbuf(),"user",4)){
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
//				   process user  
				
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
	}
	
				
	if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
	if(!strncmp((const char*)server.player[i].getbuf(),"passwd",6)){
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
				
//					   process passwd   
					
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		return 1;
	}
	return 0;
	
}

int signup(int i){

	if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
	if(!strncmp((const char*)server.player[i].getbuf(),"user",4)){
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
//				   process user  
				
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
	}
				
	if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
	if(!strncmp((const char*)server.player[i].getbuf(),"passwd",4)){
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
//					   process passwd   
					
		if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
		return 1;
	}
	return 2;
	
}

int process(int i){
	
	while(1){
		
		if(!server.Receive(i)){std::cout<<"receive error!\n";return 0;}
	
		if(!strncmp((const char*)server.player[i].getbuf(),"login",4)){
			if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
			
			if(login(i)) return 1;
			else return 0;
		}
		
		if(!strncmp((const char*)server.player[i].getbuf(),"signup",4)){
			if(!server.Send("OK",i)) {std::cout<<"send error!";return 0;}
			int s = signup(i);
			if(s==2) continue;
			else if(s==1) return 1;
			else return 0;
		}
	}
}

int main(){
	
	if(server.Bind()) std::cout<<"bind successful!"<<std::endl;
	else return 0;
	if(server.Listen()) std::cout<<"listen successful!"<<std::endl;
	else return 0;
	if(server.Accept(0)) std::cout<<"accept successful!"<<std::endl;
	else return 0;
	
	
	if(!server.Receive(0)){std::cout<<"receive error!\n";return 0;}
		if(!strncmp((const char*)server.player[0].getbuf(),"link",4))
			if(!server.Send("OK",0)){
				std::cout<<"send error!";
				return 0;
			}
	

	std::thread thr_d(process,0);
	
	thr_d.join();
	
	server.~Server();
		std::cin>>s;
		if(!strcmp("exit",(const char*)s)) break;
		if(server.Send((const char*)s,0)) std::cout<<"send successful!"<<std::endl;
		else return 0;
	
}
*/
	





int main(){

	Manage manage;
	
	manage.start();


}
